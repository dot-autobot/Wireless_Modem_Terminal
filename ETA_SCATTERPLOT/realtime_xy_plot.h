#ifndef REALTIME_XY_PLOT_H
#define REALTIME_XY_PLOT_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "udpsok.h"
namespace Ui {
class RealTime_xy_plot;
}

class RealTime_xy_plot : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RealTime_xy_plot(QWidget *parent = 0);
    ~RealTime_xy_plot();
    static  RealTime_xy_plot* getInstance( );
      static  RealTime_xy_plot*detInstance( );
    void plot_init();
    void plotter(short int *,int size);


    void add(short int *  );
    short int* remove();
    int size();

private:
  Ui::RealTime_xy_plot *ui;
  static  RealTime_xy_plot  *objRealTime_xy_plot;
   UDPStatus *myudp;
  QVector<double> I, Q  ;
  QList<short int*>      m_queue;
};

#endif // REALTIME_XY_PLOT_H
