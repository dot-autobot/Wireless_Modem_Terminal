#include<queue.h>
#include <QtTest/QTest>

wqueue::wqueue() {

}
wqueue::~wqueue() {

}
void wqueue::add(void* item) {
    mutex.lock();
    m_queue.push_back(item);

  mutex.unlock();
}
void* wqueue::remove() {

    while ( size() == 0) {
//while(1);
//                   //     QTest::qSleep(50);

                          }
    mutex.lock();
    void* item = m_queue.front();
    m_queue.pop_front();
     mutex.unlock();
    return item;
}
int wqueue::size() {
   mutex.lock();
    int size = m_queue.size();
    mutex.unlock();
    return size;
}
