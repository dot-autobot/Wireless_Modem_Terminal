#include <QtGui/QApplication>
#include "header.h"
#include "realtime_xy_plot.h"
host_info myhost;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc !=4)
   {
      return 0;
   }
    myhost.port = atoi(argv[2]);
    myhost.modulation_tech  =  atoi(argv[3]);
   strcpy(myhost.IP,argv[1]);

//    myhost.port = 5792;

//    strcpy(myhost.IP,"127.0.0.1");
    RealTime_xy_plot::getInstance()->show();
    return a.exec();
}
