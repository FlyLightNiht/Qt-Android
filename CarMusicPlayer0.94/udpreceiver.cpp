#include "udpreceiver.h"

//UDPReceiver::UDPReceiver(QObject *parent) : QObject(parent)
//{
//}
UDPReceiver::UDPReceiver(QObject *parent, int Port) : QObject(parent){
    this->mPort = Port;
}
void UDPReceiver::openSocket(){
    this->openSocket(mPort);
}

void UDPReceiver::openSocket(int Port){
    try {
        if(pSocket != nullptr && pSocket->isValid() && mPort==Port){
            return;
        }
        if(pSocket != nullptr && pSocket->isValid()){
            disconnect(this);
            pSocket->close();
        }
        mPort=Port;
        pSocket = new QUdpSocket();
        pSocket->bind(mPort);
        connect(pSocket, SIGNAL(readyRead()), this, SLOT(receive()));
    }catch (QException e){
        qDebug()<<TAG<<"openSocket error.";
    }
}

void UDPReceiver::receive()
{
    QByteArray ba;
    while(pSocket->hasPendingDatagrams())
    {
        ba.resize(pSocket->pendingDatagramSize());
        pSocket->readDatagram(ba.data(), ba.size());
        QString data = QString::fromLocal8Bit(ba);
        emit received(data+"\n");

        qDebug()<<TAG<< data;
    }
}

void UDPReceiver::closeSocket(){

    try {
        if(pSocket != nullptr && pSocket->isValid()){
            disconnect(this);
            pSocket->close();
            pSocket = nullptr;
        }
    }catch (QException e){
        qDebug()<< TAG <<"closeSocket error.";
    }
}

void UDPReceiver::setPort(int Port)
{
    mPort=Port;
    if(pSocket != nullptr){
        openSocket();
    }
}

UDPReceiver::~UDPReceiver()
{
    closeSocket();
}
