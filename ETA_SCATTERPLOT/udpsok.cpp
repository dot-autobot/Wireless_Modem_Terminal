
#include "udpsok.h"


#include "header.h"
#include "queue.h"
#include "realtime_xy_plot.h"
extern host_info myhost;
UDPStatus::UDPStatus(QObject *parent)
{

            udpSocket_read=0;
            createSocket();


}

UDPStatus::~UDPStatus()
{
    CloseSocket();

    delete udpSocket_read;
}

int UDPStatus::initSocket(QString arrd,int port)
{
    int status=udpSocket_read->bind(QHostAddress(arrd),port, QUdpSocket::ReuseAddressHint);

  connect(udpSocket_read, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

    return status;
}


void UDPStatus::CloseSocket()
{

    udpSocket_read->close();
}

void UDPStatus::createSocket()
{

    udpSocket_read = new QUdpSocket(this);

}

void UDPStatus::deleteSocket()
{   if( udpSocket_read)
    CloseSocket();

    delete udpSocket_read;
}

void UDPStatus::make_sig_connection()
{

}

void UDPStatus::run()
{



    }

void UDPStatus::readPendingDatagrams()
{
    char bufdata[2048]={0};
    int ss;
    QString data ;
    short int *dptr;
    while(udpSocket_read->hasPendingDatagrams())
    {

        QByteArray datagram;
        QString log;



        ss=udpSocket_read->pendingDatagramSize();
        dptr= (short int*) malloc(ss+10);
        QHostAddress sender;
        quint16 senderPort;

         udpSocket_read->readDatagram((char*)dptr, ss,&sender, &senderPort);


         QTest::qSleep(1 );


         ((char*)dptr)[ss] =0;

         QCoreApplication::processEvents(QEventLoop::AllEvents);
          RealTime_xy_plot::getInstance()->plotter(dptr,ss);
          free(dptr);


    }

}

void UDPStatus::cancel_transmision()
{
    CANCEL =0;
    per=0;
    packet_sent =0;
    packet_receved =0;

    emit valueChanged(per);
}

void UDPStatus::pause(int c)
{
    PAUSE =c;
}


