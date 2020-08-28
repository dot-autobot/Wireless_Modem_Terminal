#ifndef UDPSTATUS_H
#define UDPSTATUS_H

//#include <QThread>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QtNetwork/QUdpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QtTest/QTest>
#include <QtNetwork/qtcpserver.h>
#include <QtNetwork/qtcpsocket.h>
#include "udpqueue.h"
class UDPStatus: public  QThread  {
    Q_OBJECT
public:
    udpqueue     *sending_queue;
    UDPStatus(QObject *parent);
    virtual ~UDPStatus();
    int initSocket(QString arrd,int port);
    void CloseSocket();
    void createSocket();
    void deleteSocket();
    void make_sig_connection();
     void  run();
    int writedata(QByteArray datagram,int sendign_port);
signals:
     void valueChanged(int newValue);
     void send_button_upd(int value);
     void update_lcd_packet_sent_sig(int);
     void update_lcd_packet_recvd_sig(int);
private slots:

    void readPendingDatagrams();
    void cancel_transmision();
    void pause(int );

private:
    char * UDP_SEND_PACKET;
    int sending_port;
    int packet_sent;
      int  SIZE;
      int CANCEL;
        int per;
        int PAUSE;
    int packet_receved;
    QUdpSocket *udpSocket;
    QUdpSocket  *udpSocket_read;


    //QTcpServer *m_tcpServer;
    // QUdpSocket *m_SockConnection ;

};
#endif // UDPSTATUS_H

