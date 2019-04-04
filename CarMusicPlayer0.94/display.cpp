#include "display.h"
#include "ui_display.h"
#include"mainwindow.h"
#include"sensor.h"
display::display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
    this->showFullScreen();
    qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(data()));

    qtimer->start(1000);
}

display::~display()
{
    delete ui;
}
void display::data()
{

    int temp = sensor::GetInstance()->GetTemp();
    if(temp <= SER_ERROR)
        ui->Temp->setText("--");
    else
        ui->Temp->setText(QString::number(temp));

    int humi = sensor::GetInstance()->GetHumi();
    if(humi <= SER_ERROR)
        ui->Humi->setText("--");
    else
        ui->Humi->setText(QString::number(humi));

    int light = sensor::GetInstance()->GetLight();
        if(light< SER_ERROR)
            ui->Light->setText("--");
        else
           ui->Light->setText(QString::number(light));


    int oil = sensor::GetInstance()->GetLeftOil();

        ui->Oil->setText(QString::number(oil));

    int kph = sensor::GetInstance()->GetKph();

        ui->Kph->setText(QString::number(kph));
    int rev = sensor::GetInstance()->GetRev();
        ui->Rev->setText(QString::number(rev));


}


void display::on_pushButton_clicked()
{
    MainWindow::mInstance->show();
    this->close();
}
