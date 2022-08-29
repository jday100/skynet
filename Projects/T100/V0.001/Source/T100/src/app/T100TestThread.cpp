#include "T100TestThread.h"

#include "T100Log.h"
#include "T100Thread.h"
#include "T100ThreadCommon.h"

#include "T100TestUnit.h"


T100STDSTRING       T100TestThread::m_unit      = "lib.thread";


T100TestThread::T100TestThread()
    :T100Test(m_unit)
{
    //ctor
}

T100TestThread::~T100TestThread()
{
    //dtor
}

T100VOID T100TestThread::load()
{

}

T100BOOL T100TestThread::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_thread()){
        result = T100FALSE;
    }

    if(!test_unit()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestThread::test_thread()
{
    T100BOOL    result      = T100TRUE;

    T100ThreadCommon        test_common;

    test_common.start();

    test_common.wait();

    result = test_common.ok();

    if(result){
        T100Log::info("Thread OK!");
    }

    return result;
}

T100BOOL T100TestThread::test_unit()
{
    T100BOOL    result      = T100TRUE;

    T100TestUnit  unit((T100TEST_UNIT)&T100TestThread::test_run);

    return result;
}

T100BOOL T100TestThread::test_run()
{
    T100Log::info("test_run");

    return T100FALSE;
}
