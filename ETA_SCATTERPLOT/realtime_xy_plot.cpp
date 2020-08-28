#include "realtime_xy_plot.h"
#include "ui_realtime_xy_plot.h"
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
RealTime_xy_plot  *RealTime_xy_plot::objRealTime_xy_plot;
RealTime_xy_plot::RealTime_xy_plot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RealTime_xy_plot)
{


    ui->setupUi(this);
    setWindowTitle("SCATTER PLOT [V:1.2.0]final");
    myudp      = new UDPStatus(this);
    myudp->initSocket(myhost.IP,myhost.port);
    plot_init();



}

RealTime_xy_plot::~RealTime_xy_plot()
{
    delete ui;
}

RealTime_xy_plot* RealTime_xy_plot::getInstance()
{

    if(!objRealTime_xy_plot)
    {
        objRealTime_xy_plot = new RealTime_xy_plot;
    }
    return objRealTime_xy_plot;
}

RealTime_xy_plot *RealTime_xy_plot::detInstance()
{
    delete objRealTime_xy_plot;
}

void RealTime_xy_plot::plot_init()
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
    ui->customplot->graph(0)->setBrush(QBrush(Qt::yellow)); // first graph will be filled with translucent blue
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QPen(Qt::yellow, 1), QBrush(Qt::yellow), 4));
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customplot->xAxis2->setVisible(true);
    ui->customplot->xAxis2->setTickLabels(false);
    ui->customplot->yAxis2->setVisible(true);
    ui->customplot->yAxis2->setTickLabels(false);
    ui->customplot->xAxis->setRange(-2, 2);
    ui->customplot->yAxis->setRange(-2,2);
    ui->customplot->addGraph();
    ui->customplot->xAxis->setLabel("I");
    ui->customplot->yAxis->setLabel("Q");
}

void RealTime_xy_plot::plotter(short int *ptr,int size)
{



   int count=0;
   int samples = size/2,si=0,loop;
   /*
     random number genereation;
    */
/*   double AWGN,j,k,AWGN1;

   srand(((*(ptr+si))));
   for(loop=0;8*samples >loop;loop++)
   {
        AWGN =((double)(short int)rand()/32768 ) * pn[rand()%2] ;
        j=   Hard_D_Data[rand()%2] + AWGN;
        AWGN1 =((double)(short int)rand()/32768 ) * pn[rand()%2] ;
        k=   Hard_D_Data[rand()%2] + AWGN1;
        if(((j<0.9  && j >0.5) ||( j>-0.9 &&j<-0.5)) && ((k<0.9  && k >0.5) ||( k>-0.9 &&k<-0.5)))
        {
        I.push_back(j);

        Q.push_back(k);
        count++;
        //((j<0.8  && j >0.3) ||( j>-0.8 &&j<-0.3))?j:0);
         }

          si++;
      }
   */
   if(myhost.modulation_tech == 0)
   {
   for(loop=0;samples >loop;loop++)
   {
       I.push_back(  (((double)(*(ptr+loop)))/32768));
       Q.push_back( 0);

   }
   }
   else
   {
       for(loop=0;samples >loop;loop++)
       {
           I.push_back(  (((double)(*(ptr+loop++)))/32768));
           Q.push_back((((double)(*(ptr+loop)))/32768));

       }
   }


    ui->customplot->graph(0)->removeEventFilter(this);
    ui->customplot->graph(0)->setData(I,Q);


    ui->customplot->replot();
    ui->customplot->update();
   QCoreApplication::processEvents(QEventLoop::AllEvents);
   if(myhost.modulation_tech == 0)
   {
   for(loop=0; samples >loop;loop++)
    {
        I.pop_front();
        Q.pop_front();
    }
   }
   else
   {

       for(loop=0; samples/2 >loop;loop++)
        {
            I.pop_front();
            Q.pop_front();
        }
   }
}




void RealTime_xy_plot::add(short int * item) {

    m_queue.push_back (item);

}
short int* RealTime_xy_plot::remove() {

    while (m_queue.size() == 0) {

    }
    short int *item = m_queue.front();
    m_queue.pop_front();

    return item;
}
int RealTime_xy_plot::size() {

    int size = m_queue.size();

    return size;
}

