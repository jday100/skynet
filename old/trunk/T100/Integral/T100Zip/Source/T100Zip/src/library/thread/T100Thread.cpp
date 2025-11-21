#include "T100Thread.h"

#include <chrono>

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
    T100SAFE_DELETE(m_thread);
}

T100VOID T100Thread::Start()
{
    if(m_running){
        return;
    }
    m_thread    = T100NEW std::thread(&T100Thread::Run, this);
    m_running   = T100TRUE;
}

T100VOID T100Thread::Stop()
{
    if(!m_running){
        return;
    }
    m_running   = T100FALSE;
}

T100VOID T100Thread::Detach()
{
    if(m_thread){
        m_thread->detach();
    }
}

T100VOID T100Thread::Run()
{

}

T100VOID T100Thread::Waiting()
{
    if(m_thread){
        m_thread->join();
    }
}

T100VOID T100Thread::Sleep(T100UINT32 value)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(value));
}
