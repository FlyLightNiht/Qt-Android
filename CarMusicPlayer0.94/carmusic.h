#ifndef CARMUSIC_H
#define CARMUSIC_H

#include <QMainWindow>
#include<QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
#include<QMovie>
#include<QToolTip>
#include<communication.h>
namespace Ui {
class CarMusic;
}

class CarMusic : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarMusic(QWidget *parent = 0);
    ~CarMusic();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void on_pushButton_2_clicked();
    void clearPlaylist();
    void deletePlaylistItem();
    void playStart();
    void updateMediaInfo(bool available);
    void updatePlayPosition(int p);
     void positionupdate(qint64 p);
    void scrollCaption();
    //void savemusicdir();
    void on_tableWidget_playlist_doubleClicked(const QModelIndex &index);

    void on_tableWidget_playlist_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_below_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_mode_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_deleteal_clicked();

    void on_HighTempAlarm(bool flag,int t);
    void on_LowOilAlarm(bool flag, int t);
    void music_operation(MediaControlType cmdtype);

private:
    Ui::CarMusic *ui;
    QMediaPlayer * player;
    QVideoWidget * videoWidget;
    QMediaPlaylist * playlist;
    QString currentMediaFile;
    QMenu *playlistMenu;
    QLabel *m_pLabel;
    QTimer *pTimer;
    QToolTip *m_tip;
    QString fpath;
};

#endif // CARMUSIC_H
