#include "T100ThisAppManager.h"

#include "T100Log.h"
#include "T100LogFile.h"
#include "T100LogConsole.h"
#include "T100AppTest.h"

#include "T100ThisAppCmdLineParser.h"



T100ThisAppManager::T100ThisAppManager()
    :T100WxWidgets::T100WxAppManager(),
    m_info()
{
    //ctor
    create();
}

T100ThisAppManager::~T100ThisAppManager()
{
    //dtor
    destroy();
}

T100VOID T100ThisAppManager::create()
{

}

T100VOID T100ThisAppManager::destroy()
{

}

T100BOOL T100ThisAppManager::start()
{
    T100Library::T100Log::append(T100NEW T100Library::T100LogConsole());
    T100Library::T100Log::start();

    if(m_info.TEST){
        T100AppTest         test;

        test.run();
    }

    return T100TRUE;
}

T100BOOL T100ThisAppManager::stop()
{
    T100Library::T100Log::stop();
    return T100TRUE;
}

T100BOOL T100ThisAppManager::parse(int& argc, wxChar** argv)
{
    T100ThisAppCmdLineParser    cmd;

    return cmd.parse(argc, argv, m_info);
}
