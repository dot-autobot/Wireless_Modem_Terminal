
#ifndef __wqueue_h__
#define __wqueue_h__

#include <QList>
#include <QMutex>
using namespace std;

 class wqueue
{
    QList<void*>          m_queue;
    QMutex mutex;


  public:
    wqueue();
    ~wqueue();
    void add(void* item);
    void* remove();
    int size();
};

#endif
