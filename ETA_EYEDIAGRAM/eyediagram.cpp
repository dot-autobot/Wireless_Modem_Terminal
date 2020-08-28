#include "eyediagram.h"
#include "ui_eyediagram.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include "sinc_filters.h"
#include <QTime>
#include "udpsok.h"
extern host_info myhost;
EyeDiagram *EyeDiagram::obj =0;

EyeDiagram::EyeDiagram( QWidget *parent):
QMainWindow(parent),
ui(new Ui::EyeDiagram)
{
    ui->setupUi(this);
    setWindowTitle("EYE DIAGRAM [V:1.2.0]final");

    num_of_graph=0;



    plot_init();
    set_num_of_graph(1000);


    ui->ALPHA->setRange(0,10);
    ui->ALPHA->setValue(.6);
    ui->XMIN->setRange(-100,100);
    ui->XMAX->setRange(-100,100);
    ui->YMIN->setRange(-100,100);
    ui->YMAX->setRange(-100,100);
    ui->XMIN->setValue(0);
    ui->XMAX->setValue(20);
    ui->YMIN->setValue(-2);
    ui->YMAX->setValue(2);

    connect(this, SIGNAL(send_data_sig(int  ,QVector<double> * ,QVector<double> * )), this, SLOT(receve_data(int  , QVector<double> * , QVector<double>*)));
    connect(this, SIGNAL(   _sig_set_plot_num(int)), this, SLOT(_slot_set_num_of_graph(int )));
    connect(this, SIGNAL(   _sig_change_x_range(int,int)), this, SLOT( _slot_change_x_range(int,int)));
    connect(this, SIGNAL(   _sig_show_eye()), this, SLOT( _slot_show_eye()));
    eye_eng  = new eye_engine(540,10,1);
    eye_eng->start();
    udp      = new UDPStatus(this);
    udp->initSocket(myhost.IP,myhost.port);


}

EyeDiagram::~EyeDiagram()
{
    delete ui;
}
EyeDiagram *EyeDiagram::getInstence()
{
    if(obj == 0)
    {
        obj = new EyeDiagram;
    }
    return obj;
}

 QCustomPlot * EyeDiagram::eye_plot_graph(int i, QVector<double> x, QVector<double> y)
{
    if(i<num_of_graph)
    {
        ui->eyecutomplot->graph(i)->setData(x,y);

    }

    QCoreApplication::processEvents(QEventLoop::AllEvents);

    return ui->eyecutomplot;
 }

 void EyeDiagram::generate_graph(int i)
 {
    num_of_graph  = i;

    for(;i>0;i--)
    {
        ui->eyecutomplot->addGraph();
    }
 }

 void EyeDiagram::set_num_of_graph(int i)
 {
     int  ofset;

     if(i>num_of_graph)
     {
         ofset = i-num_of_graph;

         for(ofset;ofset>0;ofset--)
         {
               ui->eyecutomplot->addGraph();
         }
     }
     else
     {
         ofset = num_of_graph-i;

         for(ofset;ofset>0;ofset--)
         {
             ui->eyecutomplot->removeGraph(num_of_graph+ofset);
         }

     }

     num_of_graph = i;

     for(i=0;i<num_of_graph;i++)
     {
         ui->eyecutomplot->graph(i)->setPen(QPen(Qt::yellow)); // line color blue for first graph
         ui->eyecutomplot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot, QPen(Qt::green, 1), QBrush(Qt::green), 4));
         ui->eyecutomplot->graph(i)->setLineStyle(QCPGraph::lsLine);
     }

 }

void  EyeDiagram:: plot_init()
{

    ui->eyecutomplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->eyecutomplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->eyecutomplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->eyecutomplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->eyecutomplot->xAxis->grid()->setSubGridVisible(true);
    ui->eyecutomplot->yAxis->grid()->setSubGridVisible(true);
    ui->eyecutomplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->eyecutomplot->xAxis2->setVisible(true);
    ui->eyecutomplot->xAxis2->setTickLabels(false);
    ui->eyecutomplot->yAxis2->setVisible(true);
    ui->eyecutomplot->yAxis2->setTickLabels(false);
    ui->eyecutomplot->xAxis->setRange(0, 20);
    ui->eyecutomplot->yAxis->setRange(-1.5,1.5);
    ui->eyecutomplot->addGraph();
    ui->eyecutomplot->xAxis->setLabel("time");
    ui->eyecutomplot->yAxis->setLabel("Amplitude");

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->eyecutomplot->setBackground(plotGradient);

    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->eyecutomplot->axisRect()->setBackground(axisRectGradient);

}

 eye_engine* EyeDiagram::get_eye_engin()
{
    return eye_eng;
}

void EyeDiagram::call_back(int i, QVector<double> *x, QVector<double> *y)
{
    QCoreApplication::processEvents(QEventLoop::AllEvents);

    go_flag =1;
    emit  send_data_sig(i,x,y );
    while(go_flag);
}

void EyeDiagram::static_sig_set_plot(int i)
{
    emit _sig_set_plot_num(i);
}

void EyeDiagram::show_eye()
{
    emit _sig_show_eye();
}

double EyeDiagram::get_alpha_value()
{
    return ui->ALPHA->value();
}

double EyeDiagram::get_var()
{
    return ui->var->value();
}

void EyeDiagram::receve_data(int i, QVector<double> *x, QVector<double> *y)
{
    eye_plot_graph(i,*x,*y);
    go_flag =0;

}

void EyeDiagram::_slot_set_num_of_graph(int i)
{
    set_num_of_graph(i);
}

void EyeDiagram::_slot_change_x_range(int xmin, int xmax)
{
    ui->eyecutomplot->xAxis->setRange(xmin,xmax);
}

void EyeDiagram::_slot_show_eye()
{
    ui->eyecutomplot->update();
    ui->eyecutomplot->replot();
    QCoreApplication::processEvents(QEventLoop::AllEvents);

}

void EyeDiagram::on_pushButton_clicked()
{
    ui->eyecutomplot->xAxis->setRange(ui->XMIN->value(),ui->XMAX->value());
    ui->eyecutomplot->yAxis->setRange(ui->YMIN->value(),ui->YMAX->value());
}
