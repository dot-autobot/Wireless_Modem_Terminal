#include"header.h"
#include <QApplication>
#include "eyediagram.h"
#include <string>
#include <QtTest/QTest>

#include <QtTest/QTest>
host_info myhost;
int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
   //  if(argc !=3)
    //{
     // return 0;
   // }
   // myhost.port = atoi(argv[2]);
   //strcpy(myhost.IP,argv[1]);
   // QTest::qSleep(100);

 //  myhost.port = 5791;

 //strcpy(myhost.IP,"127.0.0.1");
   EyeDiagram::getInstence()->show();
    

          return a.exec();
}
