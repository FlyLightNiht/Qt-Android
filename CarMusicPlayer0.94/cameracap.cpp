#include "cameracap.h"
#include "ui_cameracap.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "imageview.h"
cameracap::cameracap(QWidget *parent) :
    QDialog(parent)
{
    this->resize(1200, 900);
   this->showFullScreen();
    camera = new QCamera();
    cameraViewFinder = new QCameraViewfinder();
    cameraImageCapture = new QCameraImageCapture(camera);

    captureBtn = new QPushButton();
    saveBtn = new QPushButton();
    exitBtn = new QPushButton();
    pictureBtn = new QPushButton();
    displayLabel = new QLabel();
    displayLabel->setFixedSize(256,200);
    //打开自动平衡收放图片，显示图像大小，自动调节为QLabel的大小。
    displayLabel->setScaledContents(true);
    //部件垂直布局
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(displayLabel);
    rightLayout->addStretch();
    rightLayout->addWidget(captureBtn);
    rightLayout->addWidget(saveBtn);
    rightLayout->addWidget(exitBtn);
    rightLayout->addWidget(pictureBtn);
    //部件水平布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(cameraViewFinder);
    mainLayout->addLayout(rightLayout);

    connect(captureBtn, SIGNAL(clicked()), this, SLOT(captureBtnResponded()));
    connect(saveBtn, SIGNAL(clicked()), this, SLOT(saveBtnResponded()));
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(exitBtnResponded()));
    connect(pictureBtn, SIGNAL(clicked()), this, SLOT(pictureopen()));
    connect(cameraImageCapture, SIGNAL(imageCaptured(int,QImage)), this,
            SLOT(cameraImageCaptured(int,QImage)));

    cameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setViewfinder(cameraViewFinder);
    camera->start();//启动摄像头

    /*QVBoxLayout *layout = new QVBoxLayout;
       layout->addWidget(formWidget);
       setLayout(layout);
    */
    this->setLayout(mainLayout);/*必须执行这句代码才显现出布局*/
    this->translateLanguage();

}

cameracap::~cameracap()
{

}

void cameracap::translateLanguage()
{
    this->setWindowTitle(tr("testCapture"));
    captureBtn->setText(tr("capture"));
    saveBtn->setText(tr("save"));
    exitBtn->setText(tr("exit"));
    pictureBtn->setText(tr("photos"));
}

void cameracap::captureBtnResponded()
{
    cameraImageCapture->capture();
}

void cameracap::saveBtnResponded()
{
    const QPixmap *pixmap = displayLabel->pixmap();
    if(pixmap) //{pixmap->save("a.jpg");}
    {
        indexPhoto="pi/photo"+QString::number(rand())+QString::number(rand())+".jpg";
        pixmap->save(indexPhoto);
        indexPhoto="";
    }

}

void cameracap::exitBtnResponded()
{
    camera->stop();
    MainWindow::mInstance->show();
    this->close();
}

void cameracap::cameraImageCaptured(int id, QImage image)
{
    displayLabel->setPixmap(QPixmap::fromImage(image));
}
void cameracap::pictureopen()
{imageview *imageviewpage=new imageview();
    imageviewpage->show();
    camera->stop();
    this->close();
}
