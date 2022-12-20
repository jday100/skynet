#include "T100AppBase.h"

#include <windows.h>
#include "T100Log.h"
#include "T100AppThread.h"
#include "T100AppManager.h"

namespace T100Library{

T100AppBase::T100AppBase(T100AppManager* obj, T100BOOL quit)
    :m_manager(obj), m_quit(quit)
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
    open();
}

T100VOID T100AppBase::destroy()
{
    close();
}

T100VOID T100AppBase::quit()
{

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
    m_manager->open();
}

T100VOID T100AppBase::close()
{
    m_manager->close();
}

T100VOID T100AppBase::getCmdLine(int& argc, wchar_t**& argv)
{
    argv = CommandLineToArgvW(GetCommandLineW(), &argc);
}

}
