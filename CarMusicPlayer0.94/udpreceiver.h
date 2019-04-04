#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QException>

class UDPReceiver : public QObject
{
    Q_OBJECT

public:
    explicit UDPReceiver(QObject *parent = nullptr, int Port = 6001);
    ~UDPReceiver();
    void openSocket();
    void openSocket(int Port);
    void closeSocket();
    //void startReceiveData();
    int getPort();
    void setPort(int mPort);

public slots:
    void receive();

signals:
    void received(QString);


private:
    QString TAG = "UDPReceiver";
    int mPort = 6001;
    QString mTargetIP = "localhost";
    QUdpSocket *pSocket = NULL;
    QThread *pReceiveThread;
};

#endif // UDPRECEIVER_H
