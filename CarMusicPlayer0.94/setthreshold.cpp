#include "setthreshold.h"
#include "ui_setthreshold.h"
#include "mainwindow.h"

setthreshold::setthreshold(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setthreshold)
{
    ui->setupUi(this);
    this->showFullScreen();
    //按钮绑定操作
    QButtonGroup *m_buGroup=new QButtonGroup ();
    ui->pushButton_num0->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num1->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num5->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num6->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num7->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num8->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_num9->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_x->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_clear->setFocusPolicy(Qt::NoFocus);
    m_buGroup->addButton(ui->pushButton_num0,0);
    m_buGroup->addButton(ui->pushButton_num1,1);
    m_buGroup->addButton(ui->pushButton_num2,2);
    m_buGroup->addButton(ui->pushButton_num3,3);
    m_buGroup->addButton(ui->pushButton_num4,4);
    m_buGroup->addButton(ui->pushButton_num5,5);
    m_buGroup->addButton(ui->pushButton_num6,6);
    m_buGroup->addButton(ui->pushButton_num7,7);
    m_buGroup->addButton(ui->pushButton_num8,8);
    m_buGroup->addButton(ui->pushButton_num9,9);
   // m_buGroup->addButton(ui->pushButton_x,10);
   m_IniFile = new QSettings("./test1.ini", QSettings::IniFormat);
   m_IniFile= new QSettings("./test1.ini", QSettings::IniFormat);
   QString value = m_IniFile->value("settings/ip").toString();
    ui->lineEdit_IP->setText(value);
   QString value2=m_IniFile->value("settings/temperature").toString();
   ui->lineEdit_Tem->setText(value2);
   QString value3 = m_IniFile->value("settings/thr").toString();
    ui->lineEdit_Thr->setText(value3);
   QString value5=m_IniFile->value("settings/oil").toString();
   ui->lineEdit_oil->setText(value5);
    QObject::connect(m_buGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonNumslot(int)));
    //返回主页面
  // MainWindow *MainWindowpage=new MainWindow();
   //QObject::connect(ui->pushButton, SIGNAL(clicked()), MainWindowpage,SLOT(show()));
   //QObject::connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(hide()));
}

setthreshold::~setthreshold()
{
    delete ui;
}

void setthreshold::on_pushButton_2_clicked()
{
    m_IniFile = new QSettings("./test1.ini", QSettings::IniFormat);

      m_IniFile->beginGroup("settings");     // 设置当前节名，代表以下的操作都是在这个节中
      QString ip=ui->lineEdit_IP->text();

      m_IniFile->setValue( "ip", ip); // 因为上面设置了节了，这里不在需要把节名写上去
      QString tem=ui->lineEdit_Tem->text();
      m_IniFile->setValue("temperature",tem);
      QString thr=ui->lineEdit_Thr->text();
      m_IniFile->setValue("thr",thr);
      QString oil=ui->lineEdit_oil->text();
      m_IniFile->setValue("oil",oil);
      m_IniFile->endGroup();

}
void setthreshold::buttonNumslot(int bn)
{
    if(ui->lineEdit_IP->hasFocus())//输入框1焦点
    {
            ui->lineEdit_IP->insert(QString::number(bn));


    }
     else if(ui->lineEdit_Tem->hasFocus())//输入框2焦点
    {
        ui->lineEdit_Tem->insert(QString::number(bn));

    }else if(ui->lineEdit_Thr->hasFocus()){
        ui->lineEdit_Thr->insert(QString::number(bn));
    }else if(ui->lineEdit_oil->hasFocus()){
        ui->lineEdit_oil->insert(QString::number(bn));
    }
}



void setthreshold::on_pushButton_x_clicked()
{
    if(ui->lineEdit_IP->hasFocus())//输入框1焦点
    {
        ui->lineEdit_IP->insert(".");
    }
     else if(ui->lineEdit_Tem->hasFocus())//输入框2焦点
    {
        ui->lineEdit_Tem->insert(".");
    }else if(ui->lineEdit_Thr->hasFocus()){
        ui->lineEdit_Thr->insert(".");
    }else if(ui->lineEdit_oil->hasFocus()){
        ui->lineEdit_oil->insert(".");
    }
}

void setthreshold::on_pushButton_clear_clicked()
{
    if(ui->lineEdit_IP->hasFocus())//输入框1焦点
    {
        ui->lineEdit_IP->backspace();
    }
     else if(ui->lineEdit_Tem->hasFocus())//输入框2焦点
    {
        ui->lineEdit_Tem->backspace();

    }else if(ui->lineEdit_Thr->hasFocus()){
        ui->lineEdit_Thr->backspace();
    }else if(ui->lineEdit_oil->hasFocus()){
        ui->lineEdit_oil->backspace();
    }
}


void setthreshold::on_pushButton_clicked()
{
    MainWindow::mInstance->show();
    this->close();
}
