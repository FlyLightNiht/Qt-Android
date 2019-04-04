#include "udpsender.h"

//UDPSender::UDPSender()
//{
//}
UDPSender::UDPSender(QObject *parent, QString sip, int sport) : QObject(parent){
   if(isIP(sip)) mServerIP = sip;
   mServerPort = sport;
}

void UDPSender::openSocket(){

    try {
        pSocket = new QUdpSocket();
    }catch (QException e){
        qDebug()<<TAG<<"openSocket error.";
    }

}

void UDPSender::send(QString data)
{
    try {
        if(pSocket==nullptr)return;
        qDebug()<<TAG<<data;
        QByteArray msg = data.toLocal8Bit();
        pSocket->writeDatagram(msg,QHostAddress(mServerIP), mServerPort);
    }catch (QException e){
        qDebug()<<TAG<<"send error.";
    }
}

void UDPSender::closeSocket(){

    try {
        if(pSocket!=nullptr && pSocket->isOpen()){
            pSocket->close();
            pSocket=nullptr;
        }
    }catch (QException e){
        qDebug()<<TAG<<"closeSocket error.";
    }
}

void UDPSender::setServerPort(int ServerPort) {
    this->mServerPort = ServerPort;
}
QString UDPSender::getServerIP() {
    return mServerIP;
}

bool UDPSender::setServerIP(QString ServerIP) {
    if(isIP(ServerIP)) {
        this->mServerIP = ServerIP;
        qDebug()<<TAG<<"setServerIP to:"+mServerIP;
        return true;
    }
    return false;
}

bool UDPSender::isIP(QString ip){
    QHostAddress checkip;
    if(checkip.setAddress(ip))return true;
    else return false;
}
//void UDPSender::ThreshouldCheck(){

//   static int GetSmoke();
//  int a=1;
//}
