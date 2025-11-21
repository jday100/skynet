#include "T100Thread.h"


T100Thread::T100Thread()
{
    //ctor
    init();
}

T100Thread::~T100Thread()
{
    //dtor
    uninit();
}

T100VOID T100Thread::init()
{
    m_running   = T100FALSE;
}

T100VOID T100Thread::uninit()
{

}

T100VOID T100Thread::Start()
{
    m_running   = T100TRUE;
    m_thread    = T100NEW std::thread(&T100Thread::run, this);
}

T100VOID T100Thread::Stop()
{
    m_running   = T100FALSE;
    Waiting();
}

T100VOID T100Thread::Waiting()
{
    std::unique_lock<std::mutex>        locker(m_mutex);
    m_condition.wait(locker);
    locker.unlock();
}

T100VOID T100Thread::run()
{
    while(m_running){
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    m_condition.notify_all();
}
