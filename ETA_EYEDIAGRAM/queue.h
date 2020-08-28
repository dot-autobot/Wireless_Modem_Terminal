
#ifndef __wqueue_h__
#define __wqueue_h__

#include <QList>
#include <QMutex>
using namespace std;

 class wqueue
{
    QList<double*>          m_queue;
    QMutex mutex;


  public:
    wqueue();
    ~wqueue();
   double* add(double* item);
    double* remove();
    int size();
};

#endif
