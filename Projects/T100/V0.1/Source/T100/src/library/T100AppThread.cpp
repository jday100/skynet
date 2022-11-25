#include "T100AppThread.h"

namespace T100Library{

T100AppThread::T100AppThread()
    :T100Thread()
{
    //ctor
}

T100AppThread::~T100AppThread()
{
    //dtor
}

T100VOID T100AppThread::run()
{
    std::unique_lock<std::mutex>        locker(m_mutex);
    m_condition.wait(locker);
    locker.unlock();
}

T100VOID T100AppThread::resume()
{
    m_condition.notify_all();
}

}
