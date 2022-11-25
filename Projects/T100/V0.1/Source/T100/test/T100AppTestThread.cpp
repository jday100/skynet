#include "T100AppTestThread.h"

#include "T100ThisAppTest.h"

namespace T100{

T100AppTestThread::T100AppTestThread()
    :T100Library::T100Thread()
{
    //ctor
}

T100AppTestThread::~T100AppTestThread()
{
    //dtor
}

T100VOID T100AppTestThread::run()
{
    T100::T100ThisAppTest        test_app;

    test_app.test_all();
}

}
