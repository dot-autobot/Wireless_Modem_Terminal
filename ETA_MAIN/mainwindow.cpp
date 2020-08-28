
#include<stdio.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow * MainWindow::objMain;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    setWindowTitle("WESEE SDR HOST [V:1.2.0]final");

    myUdp = new UDPStatus(this);

    ui->sdr_ip->setText("127.0.0.1");
    ui->host_ip->setText( "127.0.0.1"  );
    ui->udp_recv_port->setRange(0,0xffff);
    ui->udp_recv_port->setValue(5790);
    ui->udp_tx_port->setRange(0,0xffff);
    ui->udp_tx_port->setValue(5789);
    ui->eye_d_port->setRange(0,10000);
    ui->eye_d_port->setValue(5791);
    ui->eye_d_port_2->setRange(0,10000);
    ui->eye_d_port_2->setValue(5792);
    ui->time_domain_port->setRange(0,10000);
    ui->time_domain_port->setValue(5794);
    ui->scater_plot->setRange(0,10000);
    ui->scater_plot->setValue(5793);
    ui->write_delay->setRange(1,10000);
    ui->write_delay->setValue(500);
    ui->size_packet->setRange(0,0xffff);
    ui->size_packet->setValue(536);
    ui->iteratoor->setRange(1,0xffff);
    ui->iteratoor->setValue(1);
    ui->lcd_packet_recvd->display(0);
    ui->lcd_packet_sent->display(0);
    ui->lineEdit_DATA_Get_File->setDisabled(1);
    ui->lineEdit_TRAINING_Get_File->setDisabled(1);
    ui->training_sym->setDisabled(1);
    ui->data_sym->setDisabled(1);
    ui->training_sym_radio_text->setChecked(1);
    ui->data_sym_radio_textbox->setChecked(1);
    ui->BPSK->setChecked(1);
    ui->progressBar->setValue(0);
    ui->pushButton->setFocus();


    connect(myUdp, SIGNAL(  valueChanged(int)), this, SLOT(update_Progress(int)));
    connect(myUdp, SIGNAL(  send_button_upd(int)), this, SLOT(update_send_s(int  )));
    connect(myUdp, SIGNAL(  update_lcd_packet_sent_sig(int)), this, SLOT(update_lcd_packet_sent(int)));
    connect(myUdp, SIGNAL(  update_lcd_packet_recvd_sig(int)), this, SLOT(update_lcd_packet_recvd(int)));
    connect(myUdp->sending_queue, SIGNAL(_sig_show_output(packet *)), this, SLOT(_slot_show_output(packet *) ));

    myUdp->start();
    network_mutex_flag =0;
    thread_run_flage=0;

}

void MainWindow::update_logs(QString log)
{
    //ui->log_window->insertPlainText(log);

}

void MainWindow::update_Progress(int a)
{
    ui->progressBar->setValue(a);
}


QString MainWindow::getSDR_IP()
{
    return ui->sdr_ip->text();
}


MainWindow* MainWindow::mys(char * p)
{
    ui->output->insertPlainText(p);
    return objMain;
}

int MainWindow::getPacketsize()
{
    return ui->size_packet->text().toInt();
}

MainWindow::~MainWindow()
{
    delete myUdp;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{   int flage =0;

    thread_run_flage =0;
    if(ui->data_sym_radio_textbox->isChecked()&&ui->data_sym_radio_textbox->isChecked())
    {
         flage =1;
    }
    else if(ui->data_sym_radio_file->isChecked() &&ui->training_sym_radio_file->isChecked())
    {
        flage =1;
    }
    else
    {
      // Msg_Dialog::getInstence(" no data source found!!!")->show();
         return;
    }

    if( !flage )
    {
       // Msg_Dialog::getInstence(" no data source found!!!")->show();
          return;
    }
    if( network_mutex_flag ==11)
    {
       thread_run_flage =1;
   //  myUdp->writedata(training_symbol_str.toAscii(),ui->sending_port->text().toInt());
    }
    else
    {
        //Msg_Dialog::getInstence(" Network Uninitialized")->show();

    }


}

void MainWindow::update_lcd_packet_sent(int c)
{
    ui->lcd_packet_sent->display(c);
}

void MainWindow::update_lcd_packet_recvd(int c)
{
    ui->lcd_packet_recvd->display(c);
}

void MainWindow::_slot_show_output(packet *o)
{

 //ui->output->insertPlainText(o->p_ptr);
 free(o->p_ptr);
 free(o);

}



MainWindow*  MainWindow::getInstance()
{
    if(!objMain)
    {
        objMain  = new   MainWindow  ;
    }

    return  objMain;
}

void MainWindow::on_soket_init_clicked()
{
     static int i=0;

     network_mutex_flag =0;
     myUdp->deleteSocket();
     myUdp->createSocket();

     QString log = "udp socket created...\n";
     update_logs(log);

     myUdp->initSocket("192.168.1.7",ui->udp_recv_port->value());

     log = "udp socket binding sucessful...\n";
     update_logs(log);

     network_mutex_flag =11;

}


QString &MainWindow::getData(int  *size)
{
    *size = training_symbol_str.size();
    return training_symbol_str;

}

QString MainWindow::get_data_path()
{
    return ui->lineEdit_DATA_Get_File->text();
}

QString MainWindow::get_train_path()
{
    return ui->lineEdit_TRAINING_Get_File->text();
}


void MainWindow::on_training_sym_radio_file_toggled(bool checked)
{
    if(ui->training_sym_radio_file->isChecked())
    {
         ui->lineEdit_TRAINING_Get_File->setEnabled(1);
    }
    else
    {
        ui->lineEdit_TRAINING_Get_File->setDisabled(1);
    }
}

void MainWindow::on_training_sym_radio_text_toggled(bool checked)
{
    if(ui->training_sym_radio_text->isChecked())
    {
         ui->training_sym->setEnabled(1);
    }
    else
    {
         ui->training_sym->setDisabled(1);
    }
}


void MainWindow::on_data_sym_radio_textbox_toggled(bool checked)
{
    if(ui->data_sym_radio_textbox->isChecked())
    {
         ui->data_sym->setEnabled(1);
    }
    else
    {
        ui->data_sym->setDisabled(1);
    }
}

void MainWindow::on_data_sym_radio_file_toggled(bool checked)
{
    if(ui->data_sym_radio_file->isChecked())
    {
         ui->lineEdit_DATA_Get_File->setEnabled(1);
    }
    else
    {
        ui->lineEdit_DATA_Get_File->setDisabled(1);
    }
}

  int  MainWindow::getThread_run_status()
  {
      return  thread_run_flage ;
  }

  int MainWindow::data_from_file_or_box()
  {
      int i;
      if(ui->training_sym_radio_file->isChecked() && ui->data_sym_radio_file->isChecked() )
      {
       return 1;
      }
      else if(ui->data_sym_radio_textbox->isChecked() && ui->training_sym_radio_text->isChecked())
       {
          return 2;
      }
      else
      {
          return 0;
      }
  }

  void  MainWindow::setThread_run_status(int a)
  {
        thread_run_flage =a;
  }

int MainWindow::getSenderPort()
{
    return ui->udp_tx_port->value();
}

void MainWindow::getDataText(QString &data)
{
   data.append( ui->data_sym->toPlainText());
}

void MainWindow::getTrainText(QString &data)
{
    data = ( ui->training_sym->toPlainText());
}

QString MainWindow::get_hotst_ip()
{
    return ui->host_ip->text();
}

int MainWindow::getIteration()
{
    return ui->iteratoor->text().toInt();
}

int MainWindow::getWriteDelay()
{
    return ui->write_delay->value();
}

void MainWindow::update_send_s(int i)
{
    if(i)
    {
        ui->pushButton->setEnabled(1);
    }
    else
        ui->pushButton->setDisabled(1);
}

void MainWindow::on_reset_clicked()
{
    ui->data_sym->clear();
    ui->training_sym->clear();
    ui->output->clear();
    emit cancel_tx();
    ui->lcd_packet_recvd->display(0);
    ui->lcd_packet_sent->display(0);
}
void MainWindow::on_ply_pause_clicked()
{
    static int i = 0;

    if(!i)
    {   i=1;
        emit pause_tx(1);
        ui->ply_pause->setText("START");
    }
    else
    {
        i=0;
        emit pause_tx(0);
        ui->ply_pause->setText("PAUSE");
    }

}




int MainWindow::get_eye_d_port()
{
    return ui->eye_d_port->value();
}

int MainWindow::get_eye_d_port_2()
{return ui->eye_d_port_2->value();
}

int MainWindow::get_timedomain_port()
{
    return ui->time_domain_port->value();
}

void MainWindow::on_pushButton_3_clicked()
{
     char  process_string[57] ,process_string_2[57] ;
     QProcess  eye;
     QProcess  eye_2;
     if(ui->QPSK->isChecked())
     {
     sprintf(process_string,"eye_diagram_module.exe %s %d\0",MainWindow::getInstance()->get_hotst_ip().toAscii().data(),MainWindow::getInstance()->get_eye_d_port());
     eye.startDetached(process_string);
     QCoreApplication::processEvents(QEventLoop::AllEvents);
     QTest::qSleep(100);
     sprintf(process_string_2 ,"eye_diagram_module.exe %s %d\0 ",MainWindow::getInstance()->get_hotst_ip().toAscii().data(),MainWindow::getInstance()->get_eye_d_port_2());
     eye_2.startDetached(process_string_2 );
     }
     else
     {
         sprintf(process_string,"eye_diagram_module.exe %s %d\0",MainWindow::getInstance()->get_hotst_ip().toAscii().data(),MainWindow::getInstance()->get_eye_d_port());
         eye.startDetached(process_string);
     }
}

int MainWindow::get_scatter_plot_port()
{
    return ui->scater_plot->value();
}

void MainWindow::on_pushButton_4_clicked()
{
    char process_string[50];
     QProcess  scatter_plot;
     if(ui->QPSK->isChecked())
     {
    sprintf(process_string,"scatter_plot %s %d %d\0",MainWindow::getInstance()->get_hotst_ip().toAscii().data(),MainWindow::getInstance()->get_scatter_plot_port(),1);
    scatter_plot.startDetached(process_string);
     }
     else
     {
         sprintf(process_string,"scatter_plot %s %d %d\0",MainWindow::getInstance()->get_hotst_ip().toAscii().data(),MainWindow::getInstance()->get_scatter_plot_port(),0);
         scatter_plot.startDetached(process_string);
     }
}

int  MainWindow::is_cheaked_qpsk()
{
    return ui->QPSK->isChecked();
}
int MainWindow::is_cheaked_bpsk()
{
    return  ui->BPSK->isChecked();
}

void MainWindow::on_timedomain_clicked()
{
    char process_string[50];
     QProcess  TimeDomain;
    sprintf(process_string,"timedomain %s %d",MainWindow::getInstance()->get_hotst_ip().toAscii().data(),MainWindow::getInstance()->get_timedomain_port());
    TimeDomain.startDetached(process_string);
}

void MainWindow::closeEvent(QCloseEvent *eve)
{

    system("TASKKILL /F /IM  TimeDomain.exe");

    system("TASKKILL /F /IM eye_diagram_module.exe");

    system("TASKKILL /F /IM scatter_plot.exe");
    printf("bye bye");

}

void MainWindow::set_output(QString output)
{
     ui->output->insertPlainText(output);;
}
