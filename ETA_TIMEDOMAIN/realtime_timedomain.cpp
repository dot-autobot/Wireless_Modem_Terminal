#include "realtime_timedomain.h"
#include "ui_realtime_timedomain.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "udpsok.h"
using namespace std;
double Hard_D_Data[50] = {0.7,-0.7};
double pn[2] = {-1,1};
extern host_info myhost;
realtime_timedomain  *realtime_timedomain::objrealtime_timedomain;
realtime_timedomain::realtime_timedomain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::realtime_timedomain)
{


    ui->setupUi(this);
    setWindowTitle("TIME DOMAIN [V:1.2.0]final ");

    plot_init();
    time =2000;
    scale =1;
    time_domain_samples = (double *)malloc(sizeof(double)*(time+100));
    pause_play = 1;
  ui->xmin_var->setRange(0,time);
  ui->xmax_var->setRange(0,time);
  ui->xmin_var->setValue(0);
  ui->xmax_var->setValue(time);
  ui->scalling_factor->setValue(1);
  myudp      = new UDPStatus(this);
  myudp->initSocket(myhost.IP,myhost.port);

}

realtime_timedomain::~realtime_timedomain()
{
    delete ui;
}

realtime_timedomain* realtime_timedomain::getInstance()
{

    if(!objrealtime_timedomain)
    {
        objrealtime_timedomain = new realtime_timedomain;
    }
    return objrealtime_timedomain;
}

realtime_timedomain *realtime_timedomain::detInstance()
{
    delete objrealtime_timedomain;
}

void realtime_timedomain::plot_init()
{
    ui->customplot->addGraph();
    // line color blue for first graph

   ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
   ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
        ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
   QLinearGradient plotGradient;
   plotGradient.setStart(0, 0);
   plotGradient.setFinalStop(0, 350);
   plotGradient.setColorAt(0, QColor(80, 80, 80));
   plotGradient.setColorAt(1, QColor(50, 50, 50));
     ui->customplot->setBackground(plotGradient);
   QLinearGradient axisRectGradient;
   axisRectGradient.setStart(0, 0);
   axisRectGradient.setFinalStop(0, 350);
   axisRectGradient.setColorAt(0, QColor(80, 80, 80));
   axisRectGradient.setColorAt(1, QColor(30, 30, 30));
  ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->graph(0)->setPen(QPen(Qt::yellow)); // line color blue for first graph
 //   ui->customplot->graph(0)->setBrush(QBrush(Qt::yellow)); // first graph will be filled with translucent blue
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QPen(Qt::yellow, 1), QBrush(Qt::yellow), 4));
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot->xAxis2->setVisible(true);
    ui->customplot->xAxis2->setTickLabels(false);
    ui->customplot->yAxis2->setVisible(true);
    ui->customplot->yAxis2->setTickLabels(false);
    ui->customplot->xAxis->setRange(0, 50);
    ui->customplot->yAxis->setRange(-2, 2);

    ui->customplot->addGraph();
    ui->customplot->xAxis->setLabel("T");
    ui->customplot->yAxis->setLabel("A");
}

void realtime_timedomain::plotter(short int *ptr,int size)
{
  static int static_i=0;
  if(pause_play)
   {
   ui->customplot->xAxis->setRange(0, size/2);

   int count=0;
   int samples = size/2,si=0,loop;

   for(loop=0;samples >loop;loop++)
   {
     Y.push_back(  (((double)(*(ptr+si)))/32768)*scale);
     X.push_back(loop);
       si++;
   }

   if(static_i<time)
   {
   for(loop=0;samples >loop;loop++)
   {
       time_domain_samples[static_i++]=  Y.at(loop);
       if(static_i>time)
          break;

   }
   }

    ui->customplot->graph(0)->removeEventFilter(this);
    ui->customplot->graph(0)->setData(X,Y);


    ui->customplot->replot();
    ui->customplot->update();
   QCoreApplication::processEvents(QEventLoop::AllEvents);
    for(loop=0; samples >loop;loop++)
    {
       X.pop_front();
        Y.pop_front();
    }
  }
}




void realtime_timedomain::add(short int * item) {

    m_queue.push_back (item);

}
short int* realtime_timedomain::remove() {

    while (m_queue.size() == 0) {

    }
    short int *item = m_queue.front();
    m_queue.pop_front();

    return item;
}
int realtime_timedomain::size() {

    int size = m_queue.size();

    return size;
}



void realtime_timedomain::on_xmax_var_valueChanged(int value)
{


    ui->customplot->xAxis->setRange(ui->xmin_var->value(), ui->xmax_var->value());

    for(int loop=0;time >loop;loop++)
    {   QCoreApplication::processEvents(QEventLoop::AllEvents);
        Y.push_back(time_domain_samples[loop]  );
      X.push_back(loop);

    }

    ui->customplot->graph(0)->removeEventFilter(this);

    ui->customplot->graph(0)->setData(X,Y);


    ui->customplot->replot();
    ui->customplot->update();
       QCoreApplication::processEvents(QEventLoop::AllEvents);
    for(int loop=0; time >loop;loop++)
    {   QCoreApplication::processEvents(QEventLoop::AllEvents);
       X.pop_front();
        Y.pop_front();
    }

}

void realtime_timedomain::on_xmin_var_valueChanged(int value)
{

    ui->customplot->xAxis->setRange(ui->xmin_var->value(), ui->xmax_var->value());

    for(int loop=0;time >loop;loop++)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents);
        Y.push_back(time_domain_samples[loop]  );
        X.push_back(loop);

    }

    ui->customplot->graph(0)->removeEventFilter(this);

    ui->customplot->graph(0)->setData(X,Y);


    ui->customplot->replot();
    ui->customplot->update();
       QCoreApplication::processEvents(QEventLoop::AllEvents);
    for(int loop=0; time >loop;loop++)
    {   QCoreApplication::processEvents(QEventLoop::AllEvents);
       X.pop_front();
        Y.pop_front();
    }
}

void realtime_timedomain::on_pushButton_clicked()
{


}

void realtime_timedomain::on_push_play_pause_clicked()
{ pause_play = !pause_play;

    if(pause_play)
     {
        ui->push_play_pause->setText("pause");
     }
    else
    {
        ui->push_play_pause->setText("play");
    }

}

void realtime_timedomain::on_scalling_factor_valueChanged(double arg1)
{
    scale = arg1;
}
