#ifndef EYEDIAGRAM_H
#define EYEDIAGRAM_H
#include <QtTest/QTest>
#include <QMainWindow>
#include "header.h"
#include "matrix_engin.h"
#include "sinc_filters.h"
 #include "qcustomplot.h"
#include "eye_engine.h"
 #include "udpsok.h"
namespace Ui {
class EyeDiagram;
}

class EyeDiagram : public QMainWindow
{
    Q_OBJECT


public:
 eye_engine  *eye_eng;
    explicit EyeDiagram( QWidget *parent = 0);
    ~EyeDiagram();
    QCustomPlot *   eye_plot_graph(int i, QVector<double> x, QVector<double> y);
    void generate_graph(int i);
    void set_num_of_graph(int i);
    void   plot_init();
    eye_engine *get_eye_engin();
    void  call_back(int i  ,QVector<double> * ,QVector<double> *);
    void  static_sig_set_plot(int i);
    void  show_eye();
    double  get_alpha_value();
    double get_var();
    static EyeDiagram* getInstence();

signals:
     void send_data_sig(int  ,QVector<double> * ,QVector<double> * );
     void _sig_set_plot_num(int);
     void _sig_change_x_range(int,int);
     void _sig_show_eye();

private  slots :
   void receve_data(int i, QVector<double> *, QVector<double> *);
   void _slot_set_num_of_graph(int );
   void _slot_change_x_range(int,int);
   void _slot_show_eye();
   void on_pushButton_clicked();

private:


    Ui::EyeDiagram *ui;
    static EyeDiagram *obj;
    UDPStatus  *udp;
    int go_flag;
    int num_of_graph;
};

#endif // EYEDIAGRAM_H
