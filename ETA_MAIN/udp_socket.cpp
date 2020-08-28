
#include "udp_socket.h"

#include "mainwindow.h"




UDPStatus::UDPStatus(QObject *parent)
{
            udpSocket =0;
            udpSocket_read=0;
            CANCEL = 1;
            PAUSE =0;
            packet_receved=0;

            sending_queue   = new udpqueue;
            sending_queue->start();

}

UDPStatus::~UDPStatus()
{
    CloseSocket();
    delete udpSocket;
    delete udpSocket_read;
}

int UDPStatus::initSocket(QString arrd,int port)
{
    int status=udpSocket_read->bind(QHostAddress(MainWindow::getInstance()->get_hotst_ip()),port, QUdpSocket::ReuseAddressHint);


     connect(udpSocket_read, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
     connect(MainWindow::getInstance(), SIGNAL( cancel_tx()), this, SLOT(cancel_transmision()));
     connect(MainWindow::getInstance(), SIGNAL( pause_tx(int)), this, SLOT(pause(int)));

    return status;
}


void UDPStatus::CloseSocket()
{
    udpSocket->close();
    udpSocket_read->close();
}

void UDPStatus::createSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket_read = new QUdpSocket(this);

}

void UDPStatus::deleteSocket()
{   if(udpSocket && udpSocket_read)
    CloseSocket();
    delete udpSocket;
    delete udpSocket_read;
}

void UDPStatus::make_sig_connection()
{

}

void UDPStatus::run()
{
    int ret;

       int PSIZE;
       int i;
       int data_index =0;
       QString sdr_ip;
       int write_delay;
       QString log;
       char *text_box_ptr;
       int packet_size ;
       int iter;
       int file_or_textbox_flag;
       QString data;
       QString data_file_path;
       QString train_file_path;
       QByteArray Data_Sym_Bytedata;
       QByteArray Tarin_Sym_Bytedata;
       while(1)
         {   emit send_button_upd(1);

             while(!( MainWindow::getInstance()->getThread_run_status()))
             {
                 QTest::qSleep(100);

             }
             CANCEL =1;
             packet_sent =0;
             packet_receved=0;
             data_file_path  = MainWindow::getInstance()->get_data_path();
             train_file_path = MainWindow::getInstance()->get_train_path();
             write_delay = MainWindow::getInstance()->getWriteDelay();
             packet_size =MainWindow::getInstance()->getPacketsize();
             sending_port = MainWindow::getInstance()->getSenderPort();
             file_or_textbox_flag  = MainWindow::getInstance()->data_from_file_or_box();
             if( file_or_textbox_flag ==2)
             {
             MainWindow::getInstance()->getTrainText( data);
             MainWindow::getInstance()->getDataText(data);
             }
             else if(file_or_textbox_flag ==1)
             {

                 QFile Data_Sym_File(data_file_path);
                 Data_Sym_File.open(QIODevice::ReadOnly |QIODevice::Text );
                 QFile train_Sym_File(train_file_path);
                 train_Sym_File.open(QIODevice::ReadOnly |QIODevice::Text );
                 Data_Sym_Bytedata       =   Data_Sym_File.read(10000);
                 Tarin_Sym_Bytedata      =   train_Sym_File.read(10000);
                 //data     =  QString::fromAscii(Tarin_Sym_Bytedata);
                 //data.append(QString::fromAscii(Data_Sym_Bytedata));

             }
             MainWindow::getInstance()->setThread_run_status(0);

             emit send_button_upd(0);
             emit update_lcd_packet_sent_sig(packet_sent);
             emit update_lcd_packet_recvd_sig(packet_receved);
             UDP_SEND_PACKET = (char*) malloc(packet_size );

             per=0;
             emit valueChanged(per);
             iter   = MainWindow::getInstance()->getIteration();
             while(iter && CANCEL)
             {
                 while(PAUSE);
             iter--;
             PSIZE= SIZE = data.size();
             per=0;
             emit valueChanged(per);
              while(SIZE  && CANCEL)
                {    QCoreApplication::processEvents(QEventLoop::AllEvents);
                   while(PAUSE);
                    if(SIZE >= packet_size)
                    {

                        for(i=0;i<packet_size;i++)
                        {
                   //       UDP_SEND_PACKET[i] =data.toAscii().data()[data_index++];

                        }

                         udpSocket->writeDatagram(UDP_SEND_PACKET,packet_size,QHostAddress(MainWindow::getInstance()->getSDR_IP()),sending_port);
                         packet_sent++;
                          emit update_lcd_packet_sent_sig(packet_sent);
                         SIZE-=packet_size;

                         per = ((double)100/PSIZE)*(PSIZE-SIZE);
                         emit valueChanged(per);
                         QTest::qSleep(write_delay);

                    }
                    else if(SIZE >0 && SIZE<packet_size)
                    {

                        for(i=0;i<packet_size;i++)
                        {
                            if(SIZE > 0)
                            {
                             SIZE--;
                             //UDP_SEND_PACKET[i] =data.toAscii().data()[data_index++];
                            }
                            else
                            {
                            UDP_SEND_PACKET[i] = 0;
                            }

                        }
                         SIZE=0;
                       udpSocket->writeDatagram(  UDP_SEND_PACKET,packet_size,QHostAddress(MainWindow::getInstance()->getSDR_IP()),sending_port);
                       packet_sent++;
                        emit update_lcd_packet_sent_sig(packet_sent);

                       per = ((double)100/PSIZE)*(PSIZE-SIZE);
                       emit valueChanged(per);

                      QTest::qSleep(write_delay);

                     }


                }

               data_index = 0;
            }
               data.clear();
               free(  UDP_SEND_PACKET);
            }




    }


void UDPStatus::readPendingDatagrams()
{
    char bufdata[2048]={0};
    int ss;
    QString data ;
    int packet_size = MainWindow::getInstance()->getPacketsize();
    QString eye_ip  = MainWindow::getInstance()->get_hotst_ip();
    int eye_port   = MainWindow::getInstance()->get_eye_d_port();
    int modulation  = MainWindow::getInstance()->is_cheaked_qpsk();
     int scatter_port   = MainWindow::getInstance()->get_scatter_plot_port();
     packet  *udp_packet ;
     short int *dptr;

    while(udpSocket_read->hasPendingDatagrams())
    {

        QByteArray datagram;
        QString log;
        QString data;



        ss=udpSocket_read->pendingDatagramSize();
        dptr= (short int*) malloc( ss + 10 );
        udp_packet  = (packet*) malloc(sizeof(packet));
        udp_packet->size = ss;
        udp_packet->p_ptr = (char*)dptr;
        udp_packet->modulation = !modulation;
        QHostAddress sender;
        quint16 senderPort;

         udpSocket_read->readDatagram((char*)dptr, ss,&sender, &senderPort);

         packet_receved++;
         emit update_lcd_packet_recvd_sig(packet_receved);
        // QTest::qSleep(1 );
         data = (char*)dptr;
         ((char*)dptr)[ss] =0;
        sending_queue->packet_queue->add((void*)udp_packet);
    //     QCoreApplication::processEvents(QEventLoop::AllEvents);
        //udpSocket_read->writeDatagram( (char*)dptr,ss,QHostAddress(eye_ip),eye_port);
        //udpSocket_read->writeDatagram( (char*)dptr,ss,QHostAddress(eye_ip),scatter_port);
      //  MainWindow::getInstance()->mys((char*)  dptr);


          //  log.sprintf("data receved...\n[size:%d]\n[port:%d]]\n[ip:]\n",ss,senderPort);
          //  MainWindow::getInstance()->update_logs(log);
         //   free(dptr);

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


/*
       while(1)
       {   emit send_button_upd(1);

           while(!( MainWindow::getInstance()->getThread_run_status()))
           {
               QTest::qSleep(100);

           }
           CANCEL =1;
           packet_sent =0;
           packet_receved=0;
           packet_size =MainWindow::getInstance()->getPacketsize();
           sending_port = MainWindow::getInstance()->getSenderPort();
           MainWindow::getInstance()->getTrainText( data);
           MainWindow::getInstance()->getDataText(data);
           MainWindow::getInstance()->setThread_run_status(0);
           emit send_button_upd(0);
           emit update_lcd_packet_sent_sig(packet_sent);
           emit update_lcd_packet_recvd_sig(packet_receved);
           UDP_SEND_PACKET = (char*) malloc(packet_size );

           per=0;
           emit valueChanged(per);
           iter   = MainWindow::getInstance()->getIteration();

           PSIZE= SIZE = data.size();
           text_box_ptr = (char*) malloc(SIZE);
           for(i=0;i<SIZE;i++)
           {
               text_box_ptr[i] =   data.toAscii().data()[i];
           }

           sdr_ip=MainWindow::getInstance()->getSDR_IP();
           while(iter && CANCEL)
           {
               while(PAUSE);
           iter--;

           per=0;
           emit valueChanged(per);
           PSIZE= SIZE = data.size();
            while(SIZE  && CANCEL)
              {
                 while(PAUSE);
                  if(SIZE >= packet_size)
                  {

                      for(i=0;i<packet_size;i++)
                      {
                        UDP_SEND_PACKET[i] =text_box_ptr[data_index++];

                      }

                       udpSocket->writeDatagram(UDP_SEND_PACKET,packet_size,QHostAddress(sdr_ip),sending_port);
                       packet_sent++;
                        emit update_lcd_packet_sent_sig(packet_sent);
                       SIZE-=packet_size;

                       per = ((double)100/PSIZE)*(PSIZE-SIZE);
                       emit valueChanged(per);

                       QTest::qSleep(300);

                  }
                  else if(SIZE >0 && SIZE<packet_size)
                  {

                      for(i=0;i<packet_size;i++)
                      {
                          if(SIZE > 0)
                          {
                           SIZE--;
                           UDP_SEND_PACKET[i] =text_box_ptr[data_index++];
                          }
                          else
                          {
                          UDP_SEND_PACKET[i] = 0;
                          }

                      }
                       SIZE=0;
                     udpSocket->writeDatagram(  UDP_SEND_PACKET,packet_size,QHostAddress(sdr_ip),sending_port);
                     packet_sent++;
                      emit update_lcd_packet_sent_sig(packet_sent);

                     per = ((double)100/PSIZE)*(PSIZE-SIZE);
                     emit valueChanged(per);

                     QTest::qSleep(300);

                   }


              }

             data_index = 0;
          }
                data.clear();
             free(  UDP_SEND_PACKET);
             free(  text_box_ptr);
          }
          */
