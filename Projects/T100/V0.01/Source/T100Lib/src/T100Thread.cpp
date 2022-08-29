#include "T100Thread.h"

#include <chrono>


T100Thread::T100Thread()
{
    //ctor
    create();
}

T100Thread::~T100Thread()
{
    //dtor
    destroy();
}

T100VOID T100Thread::create()
{
    m_running = T100FALSE;
}

T100VOID T100Thread::destroy()
{

}

T100BOOL T100Thread::start()
{
    if(m_running){
        return T100FALSE;
    }

    m_thread    = T100NEW std::thread(&T100Thread::run, this);
    m_running   = T100TRUE;

    return T100TRUE;
}

T100BOOL T100Thread::stop()
{
    if(!m_running){
        return T100FALSE;
    }

    wait();
    T100SAFE_DELETE(m_thread);
    m_running = T100FALSE;

    return T100TRUE;
}

T100BOOL T100Thread::running()
{
    return m_running;
}

T100VOID T100Thread::run()
{

}

T100BOOL T100Thread::detach()
{
    if(m_thread){
        m_thread->detach();
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Thread::hangup()
{

}

T100BOOL T100Thread::wait()
{
    if(m_thread){
        m_thread->join();
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Thread::wakeup()
{

}

T100VOID T100Thread::sleep(T100WORD value)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(value));
}
