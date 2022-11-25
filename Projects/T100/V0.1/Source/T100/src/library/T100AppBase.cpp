#include "T100AppBase.h"

#include <windows.h>
#include "T100Log.h"
#include "T100AppThread.h"

namespace T100Library{

T100APP_VECTOR          T100AppBase::m_apps;
std::atomic_int         T100AppBase::m_count = 0;

T100AppBase::T100AppBase(T100AppManager* obj)
    :m_manager(obj)
{
    //ctor
    create();
}

T100AppBase::~T100AppBase()
{
    //dtor
    destroy();
}

T100VOID T100AppBase::create()
{
    m_count = 0;

    open();
}

T100VOID T100AppBase::destroy()
{
    close();
}

T100VOID T100AppBase::quit()
{
    exit(0);
}

T100VOID T100AppBase::wait()
{
    if(!m_thread){
        m_thread = T100NEW T100AppThread();
    }

    if(m_thread){
        m_thread->start();
    }
}

T100VOID T100AppBase::open()
{
    m_count++;
}

T100VOID T100AppBase::close()
{
    m_count--;

    if(0 < m_count){
        wait();
    }
}

T100VOID T100AppBase::getCmdLine(int& argc, wchar_t**& argv)
{
    argv = CommandLineToArgvW(GetCommandLineW(), &argc);
}

}
