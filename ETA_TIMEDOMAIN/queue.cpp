#include<queue.h>


wqueue::wqueue() {

}
wqueue::~wqueue() {

}
double* wqueue::add(double* item) {
    mutex.lock();
    m_queue.push_back(item);

  mutex.unlock();
}
double* wqueue::remove() {

    while ( size() == 0) {



                          }
    mutex.lock();
    double* item = m_queue.front();
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
