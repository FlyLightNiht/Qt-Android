#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"cameracap.h"
#include "setthreshold.h"
#include "testform.h"
#include "carmusic.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow* mInstance;
    CarMusic *CarMusicpage;

private slots:
    void timeUpdate();

    void on_media_player_button_clicked();

    void on_data_button_clicked();

    void on_set_button_clicked();

    void on_video_button_clicked();
    
    void on_HighTempAlarm(bool flag,int t);
    void on_LowOilAlarm(bool flag, int t);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
