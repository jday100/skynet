#include "T100Thread.h"

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
    m_running   = T100FALSE;
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

    m_running   = T100FALSE;

    return T100TRUE;
}

T100BOOL T100Thread::running()
{
    return m_running;
}

T100VOID T100Thread::run()
{

}

