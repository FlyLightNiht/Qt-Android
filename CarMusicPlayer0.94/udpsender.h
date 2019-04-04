#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QException>
#include <QTimer>

class UDPSender : public QObject
{
    Q_OBJECT

public:
    explicit UDPSender(QObject *parent = nullptr, QString sip="127.0.0.1", int sport=6001);
    void openSocket();
    void closeSocket();

    void setServerPort(int ServerPort);
    QString getServerIP();
    bool setServerIP(QString ServerIP);
    static bool isIP(QString ip);

public slots:
    void send(QString data);
    //void warningslot();//警告槽函数
signals:

private:
    int mServerPort;
    QString mServerIP;
    QUdpSocket *pSocket;
    QString TAG = "UDPSender";
};

#endif // UDPSENDER_H
