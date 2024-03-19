#include "T100ThreadTask.h"

#include <chrono>

T100ThreadTask::T100ThreadTask()
    :T100Task()
{
    //ctor
    create();
}

T100ThreadTask::~T100ThreadTask()
{
    //dtor
    destroy();
}

T100VOID T100ThreadTask::create()
{
    m_running   = T100FALSE;
}

T100VOID T100ThreadTask::destroy()
{

}

T100BOOL T100ThreadTask::start()
{
    if(m_running){
        return T100FALSE;
    }

    m_thread    = T100NEW std::thread(&T100ThreadTask::run, this, T100NULL);
    m_running   = T100TRUE;

    return T100TRUE;
}

T100BOOL T100ThreadTask::stop()
{
    if(!m_running){
        return T100FALSE;
    }

    m_running   = T100FALSE;

    return T100TRUE;
}

T100BOOL T100ThreadTask::running()
{
    return m_running;
}
