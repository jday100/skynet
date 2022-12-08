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

T100VOID T100AppTestThread::unit(T100WSTRING name)
{
    m_name = name;

    start();
}

T100VOID T100AppTestThread::run()
{
    T100::T100ThisAppTest        test_app;

    if(m_name.empty()){
        test_app.test_all();
    }else{
        test_app.test_unit(m_name);
    }

    exit(0);
}

}
