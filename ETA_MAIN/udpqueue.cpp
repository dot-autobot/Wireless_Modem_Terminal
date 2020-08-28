#include "udpqueue.h"
#include "mainwindow.h"

void get_iq(char*src,int size,short int *I,short int *Q);

udpqueue::udpqueue()
{
    packet_queue = new wqueue;
    udpSocket  = new QUdpSocket(this);
}



void udpqueue::CloseSocket()
{
    udpSocket->close();
}
void udpqueue::deleteSocket()
{
    if( udpSocket)
    CloseSocket();

    delete udpSocket;
}

void udpqueue::run()
{
    packet  *udp_packet ;
    /*short int I[10000];
    short int Q[10000];*/
    short int *I = (short*)malloc(5000);
    short int *Q = (short*)malloc(5000);;

    while(1)
    {

       if((udp_packet  = (packet*)packet_queue->remove())->size>5000)
       {

       }
       else
       {
             MainWindow::getInstance()->set_output(udp_packet->p_ptr);
          if(   udp_packet->modulation)
         {


           udpSocket->writeDatagram( (char*)udp_packet->p_ptr,udp_packet->size,QHostAddress(MainWindow::getInstance()->get_hotst_ip()),MainWindow::getInstance()->get_eye_d_port());
           udpSocket->writeDatagram( (char*)udp_packet->p_ptr,udp_packet->size,QHostAddress(MainWindow::getInstance()->get_hotst_ip()), MainWindow::getInstance()->get_scatter_plot_port());
           udpSocket->writeDatagram( (char*)udp_packet->p_ptr,udp_packet->size,QHostAddress(MainWindow::getInstance()->get_hotst_ip()),MainWindow::getInstance()->get_timedomain_port());
           free(udp_packet->p_ptr);
           free(udp_packet );
         }
        else
        {
           get_iq(udp_packet->p_ptr,udp_packet->size,(short *)I,(short*)Q);

           udpSocket->writeDatagram( (char*)I,udp_packet->size/2,QHostAddress(MainWindow::getInstance()->get_hotst_ip()),MainWindow::getInstance()->get_eye_d_port());

           udpSocket->writeDatagram( (char*)Q,udp_packet->size/2,QHostAddress(MainWindow::getInstance()->get_hotst_ip()),MainWindow::getInstance()->get_eye_d_port_2());

           udpSocket->writeDatagram( (char*)udp_packet->p_ptr,udp_packet->size,QHostAddress(MainWindow::getInstance()->get_hotst_ip()), MainWindow::getInstance()->get_scatter_plot_port());

           udpSocket->writeDatagram(  (char*)I,udp_packet->size/2,QHostAddress(MainWindow::getInstance()->get_hotst_ip()),MainWindow::getInstance()->get_timedomain_port());
           free(udp_packet->p_ptr);
           free(udp_packet );

        }
     }
    }
}

udpqueue::~udpqueue()
{
    CloseSocket();
    delete udpSocket;
}

void get_iq(char*src,int size,short int *I,short int *Q)
{
    int i,k;
        k=0;
    for(i=0;i<size/2;i++)
    {
        I[i]   =  ((short int*)src)[k++];
        Q[i]   =  ((short int*)src)[k++];

    }


    return ;
}
