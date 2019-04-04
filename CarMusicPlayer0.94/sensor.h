#ifndef SENSOR_H
#define SENSOR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <QString>
#include<QTimer>
#include <QObject>
#include<QDebug>

//#define ON_RASP_PI

#ifdef ON_RASP_PI
#include<wiringPi.h>
#endif

#define HIGH_TIME 32

#define SER_ERROR -1000
#define SER_ERROR_HW -1001
#define SER_ERROR_RW -1002
#define SER_ERROR_TEMP -2000
#define SER_ERROR_LIGHT -1002
//#define GuanMin    7

typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;

#include <QObject>

class sensor : public QObject
{
    Q_OBJECT
public:
    explicit sensor(QObject *parent = 0);

    static sensor* GetInstance();
    void InitAll();
    void DeinitAll();
    int GetHumi();
    int GetTemp();
    int GetLight();
    int GetLeftOil();
    int GetKph();
    int GetRev();
    void SetJDQ(bool onoff);

    uint8 read_dht11_dat();
    uint light_data();
private:
    void Dht11Init();
    void LightInit();
    void JDQInit();

    int mTemp;
    int mHumi;
    int mlight;
    int oilVolum;
    int KphVolum;
    int mKphDiffValue;
    int RevVolum;
    int count;
    float lightVolum;
    bool isDht11Initialized;
    bool isInitialized;


    const int mDht11PinNumber =1;
    const int mLightPinNumber =29;
    const int mJDQPinNumber =28;

    uint32 databuf;
    QTimer *mpUpdateTimer;

    static sensor* Instance;
    void UpdateOilVolum();
    void UpdateKph();
    void UpdateRev();
    void UpdateLight();
private slots:
    void updateSensorData();


};
#endif // SENSOR_H
