#include "carmusic.h"
#include "ui_carmusic.h"
#include "mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include<QMovie>
#include<QToolTip>
#include<QSettings>
#include <QMenu>
#include<QMessageBox>
#include "sensor.h"
#include "communication.h"
CarMusic::CarMusic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarMusic)
{
    ui->setupUi(this);
    //创建播放器
    //this->showFullScreen();

    player = new QMediaPlayer(this);
    //创建视频显示区域
    videoWidget = new QVideoWidget(this);
    ui->verticalLayout_video->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);
    videoWidget->installEventFilter(this);
    //绑定音量拖放信号与播放器音量调整槽
    connect(ui->horizontalSlider_volume,&QSlider::sliderMoved,
            player,&QMediaPlayer::setVolume);
    ui->horizontalSlider_volume->setValue(player->volume());
    //绑定进度条更新槽函数
    connect(player,&QMediaPlayer::positionChanged,
            this,&CarMusic::positionupdate);
    //绑定播放进度更新槽函数
    connect(ui->horizontalSlider_process,&QSlider::sliderMoved,
            this,&CarMusic::updatePlayPosition);

    m_pLabel = new QLabel(this);
      //创建播放列表
    playlist = new QMediaPlaylist(this);
    player->setPlaylist(playlist);
    //绑定播放列表更新信号与列表当前行更新槽
    connect(playlist,&QMediaPlaylist::currentIndexChanged,
            ui->tableWidget_playlist,&QTableWidget::selectRow);

    //更新媒体数据信息
    connect(player,&QMediaPlayer::metaDataAvailableChanged,
            this,&CarMusic::updateMediaInfo);
    //创建播放列表右键菜单
    playlistMenu = new QMenu(ui->tableWidget_playlist);
    playlistMenu->addAction("播放",this,SLOT(playStart()));
    playlistMenu->addAction("删除",this,SLOT(deletePlaylistItem()));
    playlistMenu->addAction("清空列表",this,SLOT(clearPlaylist()));

    //ui->dockWidget_playlist->hide();

    pTimer = new QTimer(this);
    connect(pTimer,  SIGNAL(timeout()),  this,  SLOT(scrollCaption()));

    connect(Communication::getInstance(),&Communication::HighTempAlarm,
            this,&CarMusic::on_HighTempAlarm);
    connect(Communication::getInstance(),&Communication::LowOilAlarm,
             this,&CarMusic::on_LowOilAlarm);
    connect(Communication::getInstance(),&Communication::MediaControlCmd,
             this,&CarMusic::music_operation);

     //定时200毫秒
    pTimer->start(200);

    //this->hide();
    //QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this,SLOT(savemusicdir()));
}

CarMusic::~CarMusic()
{
    delete ui;
}
bool CarMusic::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonDblClick){
        QMouseEvent *e = (QMouseEvent*)event;
        if(e->button() == Qt::LeftButton){

            if(videoWidget->isFullScreen()){
                videoWidget->setWindowFlags(Qt::SubWindow);
                videoWidget->showNormal();
            }else{
                videoWidget->setWindowFlags(Qt::Window);
                videoWidget->showFullScreen();
            }
            return true;
        }
    }
    return false;
}

//存储音乐路径
/*
void MainWindow::savemusicdir(){
    QSettings setting("D:\study\qtMusic\CarMusic\i.ini",QSettings::IniFormat);
    setting.beginGroup(tr("MusicDir"));
    setting.setValue("musicdir1","xxx");
    setting.endGroup();
}
*/
void CarMusic::positionupdate(qint64 p){
    //根据媒体文件的长度，设置进度条的长度
    ui->horizontalSlider_process->setMaximum(
          player->duration()/1000);
    ui->horizontalSlider_process->setValue(p/1000);
    if(ui->pushButton_mode->text() == "单曲1次")
    {
        if(ui->horizontalSlider_process->value()==ui->horizontalSlider_process->maximum())
        {
              ui->pushButton_play->setStyleSheet("border-image: url(:/new/prefix1/musicc1.png)");
        }
    }
    ui->label_time->setText(QString("%1:%2")
                            .arg(player->position()/1000/60)
                            .arg(player->position()/1000%60));
}
void CarMusic::updatePlayPosition(int p){
    player->setPosition(p*1000);
}
void CarMusic::deletePlaylistItem(){
    playlist->removeMedia(ui->tableWidget_playlist->currentRow());
    ui->tableWidget_playlist->removeRow(ui->tableWidget_playlist->currentRow());
}

void CarMusic::clearPlaylist(){
    playlist->clear();
    while(ui->tableWidget_playlist->rowCount())
        ui->tableWidget_playlist->removeRow(0);
}
void CarMusic::scrollCaption()
{
   const QString strScrollCation=player->metaData("Title").toString()+"------"+player->metaData("Author").toString();
    static int nPos = 0;

    // 当截取的位置比字符串长时，从头开始
    if (nPos > strScrollCation.length())
        nPos = 0;

    ui->label_10->setText(strScrollCation.mid(nPos));
    nPos++;
}
void CarMusic::updateMediaInfo(bool available){
    if(available){
        QString title = player->metaData("Title").toString();
        QString author = player->metaData("Author").toString();
        if(!title.isEmpty())
            setWindowTitle(title+" - "+author);
        else
            setWindowTitle(ui->tableWidget_playlist->item(
                               playlist->currentIndex(),0)->text());
        ui->tableWidget_playlist->item(playlist->currentIndex(),1)
                ->setText(QString("%1:%2")
                          .arg(player->duration()/1000/60)
                          .arg(player->duration()/1000%60));
    }
}
void CarMusic::playStart(){
    if(playlist->mediaCount() == 0)return;

    ui->pushButton_play->setText("");
    if(playlist->currentIndex() != ui->tableWidget_playlist->currentRow()){
        playlist->setCurrentIndex(ui->tableWidget_playlist->currentRow());
    }
     //player->setMedia(QUrl::fromLocalFile(fpath));
    player->play();
    ui->pushButton_play->setStyleSheet("border-image: url(:/new/prefix1/musicc2.png)");
}

void CarMusic::on_pushButton_2_clicked()
{
   QStringList slist =
            QFileDialog::getOpenFileNames(
                this,"选择媒体文件","c:/",
                "媒体文件(*.mp3 *.mp4 *.wmv);;所有文件(*)");
    //如果文件路径不为空，设置播放器的媒体
    int index = playlist->mediaCount();
    foreach (QString s, slist) {
        playlist->addMedia(QUrl::fromLocalFile(s));

        //添加媒体到tablewidget
        QTableWidgetItem *item0 = new QTableWidgetItem(QFileInfo(s).fileName());
       // fpath=QFileInfo(s).fileName();
        QTableWidgetItem *item1 = new QTableWidgetItem("--:--");
        int newRow = ui->tableWidget_playlist->rowCount();
        ui->tableWidget_playlist->insertRow(newRow);
        ui->tableWidget_playlist->setItem(newRow,0,item0);
        ui->tableWidget_playlist->setItem(newRow,1,item1);
    }

    if(slist.size() > 0){
        playlist->setCurrentIndex(index);
        ui->tableWidget_playlist->selectRow(index);
    }
}


void CarMusic::on_tableWidget_playlist_doubleClicked(const QModelIndex &index)
{
    playStart();
}

void CarMusic::on_tableWidget_playlist_customContextMenuRequested(const QPoint &pos)
{
    playlistMenu->exec(QCursor::pos());
}

void CarMusic::on_pushButton_clicked()
{
     // ui->dockWidget_playlist->setVisible(!ui->dockWidget_playlist->isVisible());
    if(ui->dockWidget_playlist->isVisible()){
        ui->dockWidget_playlist->setVisible(false);
        QMovie *movie = new QMovie(":/new/prefix1/yingif.gif");
           ui->label_5->setMovie(movie);
           movie->start();
          ui->label_5->setVisible(true);


    }else
    {
        ui->dockWidget_playlist->setVisible(true);
        //ui->label_5->setMovie(false);


    }

}

void CarMusic::on_pushButton_play_clicked()
{
    if(player->state()==QMediaPlayer::PlayingState)
    {
       // player->setMedia(QUrl::fromLocalFile(fpath));
    player->pause();
    ui->pushButton_play->setStyleSheet("border-image: url(:/new/prefix1/musicc1.png)");
    }else if(player->state()==QMediaPlayer::PausedState)
    {//  player->setMedia(QUrl::fromLocalFile(fpath));
        playStart();

    }else if(player->isAudioAvailable()==true){
    //    player->setMedia(QUrl::fromLocalFile(fpath));
        playStart();

    }
}

void CarMusic::on_pushButton_below_clicked()
{
    if(playlist->currentIndex() > 0)
    playlist->previous();
}

void CarMusic::on_pushButton_next_clicked()
{
    if(playlist->currentIndex() < playlist->mediaCount()-1)
    playlist->next();
}

void CarMusic::on_pushButton_mode_clicked()
{
    if(ui->pushButton_mode->text() == "单曲1次"){
        ui->pushButton_mode->setText("单曲循环");
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music4.png)");

    }else if(ui->pushButton_mode->text() == "单曲循环"){
       // ui->pushButton_mode->setText("顺序1次");
       // playlist->setPlaybackMode(QMediaPlaylist::Sequential);
        ui->pushButton_mode->setText("顺序循环");
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music2.png)");
    }else if(ui->pushButton_mode->text() == "顺序循环"){
        ui->pushButton_mode->setText("随机");
        playlist->setPlaybackMode(QMediaPlaylist::Random);
        ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music3.png)");
    }else if(ui->pushButton_mode->text() == "随机"){
        ui->pushButton_mode->setText("单曲1次");
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music1.png)");
    }
}

void CarMusic::on_pushButton_return_clicked()
{
    MainWindow::mInstance->show();
    this->hide();
}

void CarMusic::on_pushButton_delete_clicked()
{
    deletePlaylistItem();
}

void CarMusic::on_pushButton_deleteal_clicked()
{
    clearPlaylist();
}

void CarMusic::on_LowOilAlarm(bool flag, int t)
{
    if(flag&&this->isHidden())
    QMessageBox::warning(this, "油量提醒", "油量过低", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}

void CarMusic::on_HighTempAlarm(bool flag, int t)
{
    if(flag)
       ui->label_warning->setStyleSheet("border-image: url(:/new/prefix1/warning2.png");
    else
        ui->label_warning->setStyleSheet("");
}
 void CarMusic::music_operation(MediaControlType cmdtype)
{
     qDebug()<<"music_operation"<<cmdtype;

     switch (cmdtype) {
     case PLAY_START:
         on_pushButton_play_clicked();
         break;
     case PLAY_PAUSE:
         on_pushButton_play_clicked();
         break;
     case PLAY_STOP:
         on_pushButton_play_clicked();
         break;
     case PLAY_NEXT:
         on_pushButton_next_clicked();
         break;
     case PLAY_PREV:
         on_pushButton_below_clicked();
         break;
     case PLAY_REPEAT_ONE:
         if(ui->pushButton_mode->text() != "单曲循环"){
             ui->pushButton_mode->setText("单曲循环");
             playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
             ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music4.png)");
         }
         break;
     case PLAY_REPEAT_LIST:
         if(ui->pushButton_mode->text() != "顺序循环"){
                 ui->pushButton_mode->setText("顺序循环");
                 playlist->setPlaybackMode(QMediaPlaylist::Loop);
                 ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music2.png)");
             }
         break;
     case PLAY_REPEAT_RANDOM:
         if(ui->pushButton_mode->text() != "随机"){
                 ui->pushButton_mode->setText("随机");
                 playlist->setPlaybackMode(QMediaPlaylist::Random);
                 ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music3.png)");
             }

         break;
     case PLAY_REPEAT_ONETIME:
         if(ui->pushButton_mode->text() != "单曲1次"){
                 ui->pushButton_mode->setText("单曲1次");
                 playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
                 ui->label_2->setStyleSheet("border-image: url(:/new/prefix1/music1.png)");
             }
         break;
     default:
         break;
     }

}
