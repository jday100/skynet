#include "T100ThisAppManager.h"

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
    T100AppTest         test;

    test.run();

    return T100TRUE;
}

T100BOOL T100ThisAppManager::stop()
{
    return T100TRUE;
}
