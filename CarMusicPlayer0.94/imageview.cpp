#include "imageview.h"
#include "ui_imageview.h"
#include<QFileDialog>
#include<QImage>
#include<QPixmap>
#include<QDirIterator>
#include<QTextEdit>
#include"cameracap.h"
imageview::imageview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::imageview)
{
    ui->setupUi(this);
    this->showFullScreen();
}

imageview::~imageview()
{
    delete ui;
}
//获得打开图片在stringlist中的位置
void imageview::getposition(QStringList imagelist)
{
    //num=0;
    QListIterator<QString> it(imagelist);//迭代器，用来遍历
    while(it.hasNext())
    {
        if(filepath == it.next())
            break;
        else
            position++;
    }
}


//遍历文件夹下边的图片类型文件
void imageview::Open_File(QString path)
    {
        QDirIterator m_DirIterator(path,QDir::Files|QDir::NoSymLinks);
        while (m_DirIterator.hasNext())
        {
            QString tempFile=m_DirIterator.next();
            QStringList list=tempFile.split(".");
            QString expandedName=list.takeLast();
            if(expandedName=="jpg"||expandedName=="JPG"||expandedName=="png"||expandedName=="PNG")
             stringlist<<tempFile;
        }
        getposition(stringlist);//获得打开图片在stringlist中的位置
    }

void imageview::on_pushButton_8_clicked()
{
    ui->label->setScaledContents(true);
    position =0;
    stringlist.clear();
    filepath = QFileDialog::getOpenFileName(NULL, QObject::tr("打开文件"), ".",
                                            QObject::tr("Image Files(*.jpg *.png)"));
    filelist = filepath.split("/");
    filelist.removeLast ();
    folderpath = filelist.join("/");
    Open_File(folderpath);
    ui->label->setPixmap(filepath);
}
void imageview::on_pushButton_clicked()
{
    ui->label->clear();
    cameracap *cameracappage=new cameracap();
    cameracappage->show();
    this->close();

}


//打开下一张图片
void imageview::on_pushButton_3_clicked()
{       ui->label->setScaledContents(true);
        left=0;
        right=0;
        if(0 == stringlist.size())
        {
            printf("get next image error \n");
            return ;
        }
        position++;
        if(position>stringlist.size()-1)
        {
            position=0;
        }
        filepath = stringlist.at(position);
        ui->label->setPixmap(filepath);
}


//打开上一张图片
void imageview::on_pushButton_2_clicked()
{       ui->label->setScaledContents(true);
        left=0;
        right=0;
        if(0 == stringlist.size())
        {
            printf("get pre image error \n");
            return ;
        }
        position--;
        if(position<0)
        {
            position=stringlist.size()-1;
        }
        filepath = stringlist.at(position);
       ui->label->setPixmap(filepath);
}


//顺时针旋转图片
void imageview::on_pushButton_4_clicked()
{   ui->label->setScaledContents(true);
    if(0 == stringlist.size())
       {
           printf("get next image error \n");
           return ;
       }
       right=1;
       if(left==1&&right==1)
       {
           num_Roll--;
           QMatrix matrix;
           matrix.rotate(90.0);
           image = image.transformed(matrix,Qt::FastTransformation);
            pix = pix.fromImage(image);
             ui->label->setPixmap( pix );
             update();

       }
       else
       {
       num_Roll++;
       image.load(stringlist.at(position));
       QMatrix matrix;
       matrix.rotate(90.0*num_Roll);
       image = image.transformed(matrix,Qt::FastTransformation);
       pix = pix.fromImage(image);
       ui->label->setPixmap( pix );
       update();
       }
}


//逆时针旋转图片
void imageview::on_pushButton_5_clicked()
{    ui->label->setScaledContents(true);
    if(0 == stringlist.size())
        {
            printf("get next image error \n");
            return ;
        }
        left=1;
        if(left==1&&right==1)
        {
            num_Roll--;
            QMatrix matrix;
            matrix.rotate(-90.0);
            image = image.transformed(matrix,Qt::FastTransformation);
            pix = pix.fromImage(image);
            ui->label->setPixmap( pix );
            update();

        }
        else
        {
        num_Roll++;
        image.load(stringlist.at(position));
        QMatrix matrix;
        matrix.rotate(-90.0*num_Roll);
        image = image.transformed(matrix,Qt::FastTransformation);
        pix = pix.fromImage(image);
        ui->label->setPixmap( pix );
        update();

}
}


//放大和还原图片
void imageview::on_pushButton_6_clicked()
{ui->label->setScaledContents(false);

    if(bigger==1)
    {   bigger=0;
        image.load(filepath);
        pix = pix.fromImage(image);
        pix=pix.scaled(pix.width(),pix.width(),Qt::KeepAspectRatio);
        ui->label->setScaledContents(true);
        ui->label->setPixmap( pix );

    }
    else
    { bigger=1;
 image.load(filepath);
 pix = pix.fromImage(image);
 width1 = pix.width();
 height1=pix.height();
 pix=pix.scaled(width1*2,height1*2,Qt::KeepAspectRatio);
 ui->label->setPixmap( pix );
    }
}



//缩小和还原图片
void imageview::on_pushButton_7_clicked()
{
    ui->label->setScaledContents(false);
    if(smaller==1)
    {smaller=0;
     image.load(filepath);
     pix = pix.fromImage(image);
     pix=pix.scaled(pix.width(),pix.width(),Qt::KeepAspectRatio);
     ui->label->setScaledContents(true);
     ui->label->setPixmap( pix );

    }
    else
        {
        smaller=1;
        image.load(filepath);
        pix = pix.fromImage(image);
        width1 = pix.width();
        height1=pix.height();
        pix=pix.scaled(width1*0.5,height1*0.5,Qt::KeepAspectRatio);
        ui->label->setPixmap( pix );
    }

}
