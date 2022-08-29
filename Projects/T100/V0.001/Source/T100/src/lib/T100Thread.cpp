#include "T100Thread.h"

#include "T100Log.h"


T100Thread::T100Thread()
{
    //ctor
}

T100Thread::~T100Thread()
{
    //dtor
}

T100BOOL T100Thread::start()
{
    T100Log::info("start");

    m_thread = new std::thread(&T100Thread::run, this);

    return T100FALSE;
}

T100BOOL T100Thread::stop()
{
    T100Log::info("stop");

    return T100FALSE;
}

T100BOOL T100Thread::run()
{
    T100Log::info("running...");

    return T100FALSE;
}

T100BOOL T100Thread::wait()
{
    if(m_thread){
        m_thread->join();
    }
    return T100FALSE;
}

T100BOOL T100Thread::detach()
{
    if(m_thread){
        m_thread->detach();
    }
    return T100FALSE;
}

T100BOOL T100Thread::sleep()
{
    return T100FALSE;
}

T100BOOL T100Thread::wakeup()
{
    return T100FALSE;
}
