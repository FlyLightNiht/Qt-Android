#include "sensor.h"


sensor* sensor::Instance=nullptr;
sensor::sensor(QObject *parent) : QObject(parent)
{
    isDht11Initialized = false;
    mpUpdateTimer=new QTimer();
     mpUpdateTimer->start(500);
    connect(mpUpdateTimer,&QTimer::timeout,this,&sensor::updateSensorData);

    oilVolum = 10000;
    KphVolum = 0;
    mKphDiffValue = 1;
    RevVolum = 0;
    mlight = 1;

	isInitialized=false;
}
sensor* sensor::GetInstance()
{
    if(Instance==nullptr){
        Instance=new sensor();

    }
    return Instance;
}
void sensor::InitAll()  //初始化
{
    if(isInitialized)return;
    Dht11Init();
    LightInit();
    JDQInit();
    isInitialized = true;
}

void sensor::Dht11Init()
{
    printf("Use GPIO1 to read data!\n");
#ifdef ON_RASP_PI
    if (-1 == wiringPiSetup()) {
    printf("Setup wiringPi failed!");
    isDht11Initialized = false;
    return;
    }

    pinMode(mDht11PinNumber, OUTPUT); // set mode to output
    digitalWrite(mDht11PinNumber, 1); // output a high level
    isDht11Initialized = true;
    printf("Enter OS-------\n");
#endif
}

void sensor::LightInit()
{
    printf("Use GPIO29 to read data!\n");
#ifdef ON_RASP_PI
    if (-1 == wiringPiSetup()) {
    printf("Setup wiringPi failed!");
    return;
    }

    pinMode(mLightPinNumber, OUTPUT); // set mode to output
    digitalWrite(mLightPinNumber, 1); // output a high level

    printf("Enter OS-------\n");
#endif
}

void sensor::JDQInit()
{
    printf("Use GPIO2 to read data!\n");
#ifdef ON_RASP_PI
    if (-1 == wiringPiSetup()) {
    printf("Setup wiringPi failed!");
    //return;
    }

    pinMode(mJDQPinNumber, OUTPUT); // set mode to output
    //digitalWrite(mJDQPinNumber,HIGH); // output a high level
    printf("Enter OS-------\n");
#endif
}

void sensor::updateSensorData()
{
    qDebug()<<"sensor:"<<"updateSensorData";
    read_dht11_dat();
    UpdateOilVolum();
    UpdateKph();
    UpdateRev();
    UpdateLight();
    //SetJDQ();
    //GetLight();
    //GetKph();
    //GetRev();
}

void sensor::DeinitAll()
{
    isDht11Initialized = false;
    isInitialized = false;
}

uint8 sensor::read_dht11_dat()
{
#ifdef ON_RASP_PI
    uint8 crc;
    uint8 i;
    int j;

    if(!isDht11Initialized){
        mTemp = SER_ERROR_HW;
        mHumi = SER_ERROR_HW;
        return 0;
    }

    pinMode(mDht11PinNumber,OUTPUT); // set mode to output
    digitalWrite(mDht11PinNumber, 0); // output a high level
    delay(25);
    digitalWrite(mDht11PinNumber, 1); // output a low level
    pinMode(mDht11PinNumber, INPUT); // set mode to input
    pullUpDnControl(mDht11PinNumber,PUD_UP);

    delayMicroseconds(27);
    if(digitalRead(mDht11PinNumber)==0) //SENSOR ANS
    {
        for(j=1000;!digitalRead(mDht11PinNumber)&&j>0;j--); //wait to high
        if(j<=0)goto DHT11_ERROR;

        for(i=0;i<32;i++)
        {
            for(j=1000;digitalRead(mDht11PinNumber)&&j>0;j--); //wait to high
            if(j<=0)goto DHT11_ERROR;
            for(j=1000;!digitalRead(mDht11PinNumber)&&j>0;j--); //wait to high
            if(j<=0)goto DHT11_ERROR;
            delayMicroseconds(HIGH_TIME);
            databuf*=2;
            if(digitalRead(mDht11PinNumber)==1) //1
            {
                databuf++;
            }
        }
        for(i=0;i<8;i++)
        {
            for(j=1000;digitalRead(mDht11PinNumber)&&j>0;j--); //wait to high
            if(j<=0)goto DHT11_ERROR;
            for(j=1000;!digitalRead(mDht11PinNumber)&&j>0;j--); //wait to high
            if(j<=0)goto DHT11_ERROR;
            delayMicroseconds(HIGH_TIME);
            crc*=2;
            if(digitalRead(mDht11PinNumber)==1) //1
            {
                crc++;
            }
        }

        mTemp = (databuf>>8)&0xff;
        mHumi = (databuf>>24)&0xff;
        databuf=0;

        return 1;
    }
DHT11_ERROR:
    databuf=0;
    return 0;
#else
    return 1;
#endif

}

int sensor::GetTemp()
{
        if(mTemp > -10 && mTemp < 70)
            return mTemp;
        else
            return SER_ERROR_TEMP;
}
void sensor::UpdateLight()
{
#ifdef ON_RASP_PI
    pinMode(mLightPinNumber, INPUT);

    if(digitalRead(mLightPinNumber)==0)
   {
        mlight = 1;
   }
    else if(digitalRead(mLightPinNumber)==1)
   {
        mlight = 0;
   }
#endif
}
int sensor::GetLight()
{
    return mlight;
}

void sensor::SetJDQ(bool onoff)
{
#ifdef ON_RASP_PI
//pinMode(mJDQPinNumber, INPUT);
    if(onoff)
   {
      digitalWrite(mJDQPinNumber,LOW);
   }
    else
   {
      digitalWrite(mJDQPinNumber,HIGH);
   }
#endif
}

int sensor::GetHumi()
{

        if(mHumi >= 0 && mHumi <= 100)
            return mHumi;

      else
        return SER_ERROR_RW;

}

void sensor::UpdateOilVolum(){
    oilVolum = oilVolum - KphVolum*0.5;
    if(oilVolum <= 50)
        oilVolum=10000;
}

int sensor::GetLeftOil()
{
    return oilVolum/100;
}

void sensor::UpdateKph(){


    KphVolum = KphVolum + mKphDiffValue;
    if(mKphDiffValue>0 && KphVolum>=100){
        mKphDiffValue = -1;
    }else if(mKphDiffValue<0 && KphVolum<=0){
        mKphDiffValue = 1;
    }

}

int sensor::GetKph(){
    return KphVolum;
}
void sensor::UpdateRev(){
    RevVolum = KphVolum  * 0.08 + 1;
}
int sensor::GetRev(){
    return RevVolum;
}
