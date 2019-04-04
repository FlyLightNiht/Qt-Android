#include "communication.h"
#include "mainwindow.h"
#include"qmessagebox.h"
#include"sensor.h"
#include"carmusic.h"
#include"setthreshold.h"
Communication* Communication::Instance=nullptr;
Communication::Communication(QObject *parent) : QObject(parent)
{
     sensor::GetInstance()->InitAll();
     HighTempAlarmFlag = false;
     LowOilAlarmFlag = false;
}

 void Communication::CheckAlarm(){

	int t = sensor::GetInstance()->GetTemp();

    //TODO:获取阈值
      m_IniFile = new QSettings("./test1.ini", QSettings::IniFormat);
      int value2=m_IniFile->value("settings/temperature").toInt();
      int value5=m_IniFile->value("settings/oil").toInt();
     if(t>=value2 && !HighTempAlarmFlag)
     {
         //发送高温警报
         HighTempAlarmFlag = true;
         emit HighTempAlarm(HighTempAlarmFlag,t);
         sensor::GetInstance()->SetJDQ(true);
     }else if(t<value2 && HighTempAlarmFlag){
         //发送高温警报
         HighTempAlarmFlag = false;
         emit HighTempAlarm(HighTempAlarmFlag,t);
         sensor::GetInstance()->SetJDQ(false);
     }

     int o = sensor::GetInstance()->GetLeftOil();
     if(o<=value5 && !LowOilAlarmFlag)
     {
         LowOilAlarmFlag = true;
         emit LowOilAlarm(LowOilAlarmFlag,o);
     }
     else if(o>value5 && LowOilAlarmFlag){
         LowOilAlarmFlag = false;
         emit LowOilAlarm(LowOilAlarmFlag,o);
     }

     //发送烟雾警报
     //emit SmokeAlarm();
 }

 void Communication::SendData()
 {
     qDebug()<<"Communication: SendData";
    //1. 获取传感器数据,发送数据给APP
     QString strToSend = QString("TEMP=%1;").arg(sensor::GetInstance()->GetTemp())
             .append(QString("HUM=%1;").arg(sensor::GetInstance()->GetHumi()))
             .append(QString("LIGHT=%1;").arg(sensor::GetInstance()->GetLight()))
             .append(QString("OIL=%1;").arg(sensor::GetInstance()->GetLeftOil()));

    pSender->send(strToSend);
//     int temp= sensor::GetInstance()->GetTemp();
//     pSender->send(QString("TEMP=%1;").arg(temp) );

//      int humi = sensor::GetInstance()->GetHumi();
//     pSender->send(QString("HUM=%1;").arg(humi));

//     int light = sensor::GetInstance()->GetLight();
//     pSender->send(QString("LIGHT=%1;").arg(light));

//    int oil = sensor::GetInstance()->GetLeftOil();
//     pSender->send(QString("OIL=%1;").arg(oil));

//    int kph = sensor::GetInstance()->GetKph();
//     pSender->send(QString("KPH=%1;").arg(kph));

//     int rev = sensor::GetInstance()->GetRev();
//      pSender->send(QString("REV=%1;").arg(rev));

     //2. 判断数据是否超出阈值，以及是否需要发出警
     CheckAlarm();
 }


Communication* Communication::getInstance()
{
    if(Instance==nullptr){
        Instance=new Communication();
    }
    return Instance;
}

void Communication::Open()
{    m_IniFile = new QSettings("./test1.ini", QSettings::IniFormat);
     QString value = m_IniFile->value("settings/ip").toString();
    //获取存储的ip地址
    //QString ip = Storage::getIPAddress();
    pSender = new UDPSender(this, value, 6001);
    pSender->openSocket();

    pReceiver = new UDPReceiver(this, 6002);
    pReceiver->openSocket();
    connect(pReceiver,&UDPReceiver::received,this,&Communication::ReceivedData);

    //启动定时器
    mTimer = new QTimer();
    mTimer->start(2000);
    connect(mTimer,&QTimer::timeout,this,&Communication::SendData);
}

void Communication::Close()
{
    pSender->closeSocket();
    pReceiver->closeSocket();
    //mTimer->stop();

}

void Communication::ReceivedData(QString data)
{


    //接收数据，并做处理
    qDebug()<<"Communication: ReceivedData"<<data;

    //指令解析，并发送相应信号
    if(data.contains("PLAY_START"))
        emit MediaControlCmd(PLAY_START);
    else if(data.contains("PLAY_PAUSE"))
        emit MediaControlCmd(PLAY_PAUSE);
    else if(data.contains("PLAY_STOP"))
        emit MediaControlCmd(PLAY_STOP);
    else if(data.contains("PLAY_NEXT"))
        emit MediaControlCmd(PLAY_NEXT);
    else if(data.contains("PLAY_PREV"))
        emit MediaControlCmd(PLAY_PREV);
    else if(data.contains("PLAY_REPEAT_ONETIME"))
        emit MediaControlCmd(PLAY_REPEAT_ONETIME);
    else if(data.contains("PLAY_REPEAT_ONE"))
        emit MediaControlCmd(PLAY_REPEAT_ONE);
    else if(data.contains("PLAY_REPEAT_LIST"))
        emit MediaControlCmd(PLAY_REPEAT_LIST);
    else if(data.contains("PLAY_REPEAT_RANDOM"))
        emit MediaControlCmd(PLAY_REPEAT_RANDOM);

}
