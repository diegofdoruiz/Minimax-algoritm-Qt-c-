#ifndef DUTHREAD_HPP
#define DUTHREAD_HPP

#include<QThread>


class DuThread : public QThread
{
    Q_OBJECT
public:
    DuThread(int miliseconds, QObject *parent = nullptr);
signals:
    void timeOut();
private:
    int m_miliseconds;

protected:
    void run() override;
};

#endif // DUTHREAD_HPP
