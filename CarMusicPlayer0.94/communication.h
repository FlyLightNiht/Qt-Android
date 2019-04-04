#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include"udpreceiver.h"
#include"udpsender.h"
#include<QDebug>
#include <QSettings>
enum MediaControlType{
    PLAY_START,
    PLAY_PAUSE,
    PLAY_STOP,
    PLAY_NEXT,
    PLAY_PREV,
    PLAY_REPEAT_ONE,
    PLAY_REPEAT_LIST,
    PLAY_REPEAT_RANDOM,
    PLAY_REPEAT_ONETIME
};


class Communication : public QObject
{
    Q_OBJECT
public:
    explicit Communication(QObject *parent = nullptr);

    static Communication* getInstance();

    UDPSender *pSender;
    UDPReceiver *pReceiver;
    void Open();
    void Close();
    void CheckAlarm();//检查信号是否做出判断
    QSettings* m_IniFile;


private:
    static Communication* Instance;

    QTimer *mTimer;
    bool HighTempAlarmFlag;
    bool LowOilAlarmFlag;

signals:
    //警报
    void HighTempAlarm(bool,int);
    void LowOilAlarm(bool,int);
    //控制指令
    void MediaControlCmd(MediaControlType cmdtype);

public slots:
    void ReceivedData(QString);
    void SendData();

};
#endif // COMMUNICATION_H
