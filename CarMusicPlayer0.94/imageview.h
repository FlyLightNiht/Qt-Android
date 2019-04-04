#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QMainWindow>

namespace Ui {
class imageview;
}

class imageview : public QMainWindow
{
    Q_OBJECT

public:
    explicit imageview(QWidget *parent = 0);
    ~imageview();
    QString filepath;
    QString folderpath;
    QStringList filelist;
    QStringList stringlist;
    QImage image;
    QImage image1;
    QPixmap pix;
    int position;//图片在文件夹中的位置
    int num_Roll;//旋转次数，通过旋转次数来得到旋转角度
    int width1;
    int height1;
    bool bigger=0;
    bool smaller=0;
    bool left;
    bool right;
    void Open_File(QString);
    void getposition(QStringList);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::imageview *ui;
};

#endif // IMAGEVIEW_H
