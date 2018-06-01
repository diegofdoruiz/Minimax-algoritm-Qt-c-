#include "duthread.hpp"

DuThread::DuThread(int miliseconds, QObject *parent) : QThread(parent)
{
    m_miliseconds = miliseconds;
}

void DuThread::run(){
    while(true){
        msleep(m_miliseconds);
        emit timeOut();
    }
}
