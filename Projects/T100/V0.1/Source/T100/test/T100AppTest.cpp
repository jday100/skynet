#include "T100AppTest.h"

#include "T100AppTestThread.h"

T100AppTest::T100AppTest(T100WxWidgets::T100WxAppManager* obj)
    :T100WxWidgets::T100WxApp(obj)
{
    //ctor
}

T100AppTest::~T100AppTest()
{
    //dtor
}

T100BOOL T100AppTest::run()
{
    T100::T100AppTestThread*  thread = T100NEW T100::T100AppTestThread();

    thread->start();

    return T100FALSE;
}
