    #include "testform.h"
    #include "ui_testform.h"
    #include "setthreshold.h"
    #include"mainwindow.h"
    testform::testform(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::testform)
    {
        ui->setupUi(this);
          m_IniFile= new QSettings("./test1.ini", QSettings::IniFormat);
          QString value = m_IniFile->value("settings/ip").toString();
           ui->lineEdit->setText(value);
          QString value2=m_IniFile->value("settings/temperature").toString();
          ui->lineEdit_2->setText(value2);
          QString value3 = m_IniFile->value("settings/thr").toString();
           ui->lineEdit_3->setText(value3);
          QString value5=m_IniFile->value("settings/oil").toString();
          ui->lineEdit_5->setText(value5);
    }

    testform::~testform()
    {
        delete ui;
    }

    void testform::on_pushButton_clicked()
    {
        MainWindow::mInstance->show();
        this->close();
    }
