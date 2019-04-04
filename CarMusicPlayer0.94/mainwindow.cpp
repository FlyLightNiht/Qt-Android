#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include "QString"
#include "QDateTime"
#include "display.h"
#include "sensor.h"
#include "communication.h"
#include <QMessageBox>
MainWindow* MainWindow::mInstance=nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();
    mInstance = this;
    //this->setFixedSize(394,442);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
        //显示时间
    QTimer *timer = new QTimer(this);//创建定时器对象
    //设置定时信号产生信号时间间隔(ms)
    timer->start(1000);
    //连接timer对象的timeout()信号
    //到当前对象的timerUpdate()槽函数
    this->connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));

    connect(Communication::getInstance(),&Communication::HighTempAlarm,
            this,&MainWindow::on_HighTempAlarm);
    connect(Communication::getInstance(),&Communication::LowOilAlarm,
            this,&MainWindow::on_LowOilAlarm);
    CarMusicpage=new CarMusic(nullptr);
    //CarMusicpage->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeUpdate()
{
    //获取当前时间，存放在time对象中
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh:mm:ss");
    //把time形式转化字符串形式
    QDateTime Day = QDateTime::currentDateTime();
    QString DayText = Day.toString("yy年MM月dd日");

    this->ui->label_3->setText(DayText);
    this->ui->label_2->setText(timeText);
    ui->label_4->setText(QString::number(sensor::GetInstance()->GetLeftOil()));
    //this->ui->lable_4->setText();
}

void MainWindow::on_media_player_button_clicked()
{
    CarMusicpage->showFullScreen();
    this->hide();
}

void MainWindow::on_data_button_clicked()
{
    display *displayformpage=new display();
    displayformpage->show();
    this->hide();
}

void MainWindow::on_set_button_clicked()
{
    setthreshold *threshold=new setthreshold();
    threshold->show();
    this->hide();
}

void MainWindow::on_video_button_clicked()
{
    cameracap* c = new cameracap(this);
    c->show();
    this->hide();
}

void MainWindow::on_LowOilAlarm(bool flag, int t)
{
    if(flag)
    QMessageBox::warning(this, "油量提醒", "油量过低", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}

void MainWindow::on_HighTempAlarm(bool flag, int t)
{
    if(flag)
        ui->label_warningT->setStyleSheet("");
    else
        ui->label_warningT->setStyleSheet("");
}

