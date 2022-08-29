#include "T100App.h"

#include <windows.h>
#include "T100Log.h"


T100APP_VECTOR          T100App::m_apps;
std::atomic_int         T100App::m_count;


T100App::T100App()
{
    //ctor
    create();
}

T100App::~T100App()
{
    //dtor
    destroy();
}

T100VOID T100App::create()
{
    m_count = 0;

    T100Log::start();

    open();
}

T100VOID T100App::destroy()
{
    T100Log::stop();

    close();
}

T100VOID T100App::quit()
{
    exit(0);
}

T100VOID T100App::wait()
{

}

T100VOID T100App::open()
{
    m_count++;
}

T100VOID T100App::close()
{
    m_count--;

    if(0 > m_count){
        wait();
    }
}

T100VOID T100App::getCmdLine(int& argc, wchar_t**& argv)
{
    argv = CommandLineToArgvW(GetCommandLineW(), &argc);
}
