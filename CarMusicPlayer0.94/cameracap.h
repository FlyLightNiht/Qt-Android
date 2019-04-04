#ifndef CAMERACAP_H
#define CAMERACAP_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class cameracap;
}

class cameracap : public QDialog
{
    Q_OBJECT

public:
    explicit cameracap(QWidget *parent = 0);
    QString indexPhoto;
    ~cameracap();
private slots:
    void captureBtnResponded();
    void saveBtnResponded();
    void exitBtnResponded();
    void cameraImageCaptured(int id, QImage image);
    void pictureopen();
private:
    QCamera *camera;//系统摄像头设备
    QCameraViewfinder *cameraViewFinder;//摄像头取景器部件
    QCameraImageCapture *cameraImageCapture;//截图部件

    QPushButton *captureBtn;
    QPushButton *saveBtn;
    QPushButton *exitBtn;
    QPushButton *pictureBtn;
    QLabel *displayLabel;

    void translateLanguage();
};

#endif // CAMERACAP_H
