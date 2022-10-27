#include "T100ThisAppManager.h"

#include "T100Log.h"
#include "T100LogFile.h"
#include "T100LogConsole.h"
#include "T100AppTest.h"



T100ThisAppManager::T100ThisAppManager()
    :T100WxWidgets::T100WxAppManager()
{
    //ctor
}

T100ThisAppManager::~T100ThisAppManager()
{
    //dtor
}

T100BOOL T100ThisAppManager::start()
{
    T100Library::T100Log::append(T100NEW T100Library::T100LogConsole());
    T100Library::T100Log::start();

    T100AppTest         test;

    test.run();

    return T100TRUE;
}

T100BOOL T100ThisAppManager::stop()
{
    T100Library::T100Log::stop();
    return T100TRUE;
}
