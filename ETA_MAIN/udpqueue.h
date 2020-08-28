#ifndef UDPQUEUE_H
#define UDPQUEUE_H
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QtNetwork/QUdpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QtTest/QTest>
#include <QtNetwork/qtcpserver.h>
#include <QtNetwork/qtcpsocket.h>
#include <queue.h>
#include "header.h"
class udpqueue : public QThread
{
     Q_OBJECT
public:
    udpqueue();
     virtual   ~udpqueue();
void  CloseSocket();
void  deleteSocket();
void run();


wqueue      *packet_queue;
signals :

void _sig_show_output(packet *);
private:
       QUdpSocket *udpSocket;

};

#endif // UDPQUEUE_H
