#ifndef realtime_timedomain_H
#define realtime_timedomain_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "udpsok.h"
namespace Ui {
class realtime_timedomain;
}

class realtime_timedomain : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit realtime_timedomain(QWidget *parent = 0);
    ~realtime_timedomain();
    static  realtime_timedomain* getInstance( );
      static  realtime_timedomain*detInstance( );
    void plot_init();
    void plotter(short int *,int size);


    void add(short int *  );
    short int* remove();
    int size();

private slots:


    void on_xmax_var_valueChanged(int value);

    void on_xmin_var_valueChanged(int value);

    void on_pushButton_clicked();

    void on_push_play_pause_clicked();

    void on_scalling_factor_valueChanged(double arg1);

private:
  Ui::realtime_timedomain *ui;
  static  realtime_timedomain  *objrealtime_timedomain;
  double *time_domain_samples;
  int    time;
  int pause_play;
   UDPStatus *myudp;
  QVector<double> X, Y;
  double scale;
  QList<short int*>      m_queue;
};

#endif // realtime_timedomain_H
