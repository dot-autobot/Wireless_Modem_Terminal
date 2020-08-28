#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QMainWindow>
#include<stdio.h>
#include "udp_socket.h"



namespace Ui {
class MainWindow;
}


class MainWindow;


class MainWindow : public QMainWindow
{
    Q_OBJECT
protected :
     void closeEvent(QCloseEvent *eve);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow* getInstance( );
    char arr[200];
    void add(short int *  );
    short int* remove();
    int size();

    MainWindow* mys(char* p);
    int getPacketsize();
    char * getPacket();
    int getIteration();
    int  getWriteDelay();
    void getDataText(QString & );
    void getTrainText(QString & );
    QString get_hotst_ip();
    QString getSDR_IP();
    int is_cheaked_bpsk();
    int is_cheaked_qpsk();
    void update_logs(QString log);
    void up_p(int,int );
    int status_eyeD_plot();
    int get_eye_d_port();
    int get_eye_d_port_2();
    int get_timedomain_port();
    double get_alpha();
    int get_scatter_plot_port();
    int status_flag_plot();
    void set_output(QString output);
    int  getThread_run_status();
    int   data_from_file_or_box();
    QString &getData(int *);
    QString get_data_path();
    QString get_train_path();
    void  setThread_run_status(int);
    int getSenderPort();
signals :
    void  cancel_tx();
    void  pause_tx(int);
private  slots :
    void update_send_s(int i);
    void update_Progress(int a);
    void on_pushButton_clicked();
    void update_lcd_packet_sent(int);
    void update_lcd_packet_recvd(int);
    void _slot_show_output(packet *);





    void on_soket_init_clicked();




    void on_training_sym_radio_file_toggled(bool checked);

    void on_training_sym_radio_text_toggled(bool checked);



    void on_data_sym_radio_textbox_toggled(bool checked);

    void on_data_sym_radio_file_toggled(bool checked);



    void on_reset_clicked();

    void on_ply_pause_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_timedomain_clicked();

private :
    Ui::MainWindow *ui;

      UDPStatus  *myUdp;
      char network_mutex_flag;
      static  MainWindow *objMain ;
        int thread_run_flage;

       QString training_symbol_str;
       QString data_symbol_str;

};


//MainWindow  *objMainWindow;

#endif // MAINWINDOW_H
/*void MainWindow::realtimeDataSlot()
{QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
      y1[i] = qExp(-i/150.0);              // exponential envelope
    }
  static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  if (key-lastPointKey > 0.002) // at most add point every 2 ms
  {
    // add data to lines:
      ui->customPlot->graph(0)->setData(x, y0);
    //ui->customPlot->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
    //ui->customPlot->graph(1)->addData(key, qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364));
    // rescale value (vertical) axis to fit the current data:
    //ui->customPlot->graph(0)->rescaleValueAxis();
    //ui->customPlot->graph(1)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  ui->customPlot->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
          , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}
*/





