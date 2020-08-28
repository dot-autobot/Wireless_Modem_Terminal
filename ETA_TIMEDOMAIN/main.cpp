#include <QtGui/QApplication>
#include "header.h"
#include "realtime_timedomain.h"
host_info myhost;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

      if(argc !=3)
   {
      return 0;
   }
    myhost.port = atoi(argv[2]);

   strcpy(myhost.IP,argv[1]);
//    myhost.port = 5792;

//     strcpy(myhost.IP,"127.0.0.1");
    realtime_timedomain::getInstance()->show();
    return a.exec();
}
