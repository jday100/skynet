#include "T100LogTest.h"

#include "T100LibraryTestHint.h"
#include "T100Log.h"
#include "T100File.h"
#include "T100LogFile.h"
#include "T100ThisAppSetup.h"


namespace T100Library{

T100WSTRING         T100LogTest::m_name                     = L"log";

T100LogTest::T100LogTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100LogTest::~T100LogTest()
{
    //dtor
}

T100BOOL T100LogTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_log();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100LogTest::test_log()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_LIBRARY_LOG_TEST_START);

    T100WSTRING     name;
    T100LogBase*    log             = T100NULL;

    name    = T100ThisAppSetup::getTestWork(L"logs\\test.log").to_wstring();

    T100File        file(name);

    if(file.exists()){
        result = file.remove();
    }

    if(file.exists()){
        result = T100FALSE;
    }

    if(result){
        log     = T100NEW T100LogFile(name);

        if(!file.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        T100Log::append(log);

        T100Log::start();

        T100Log::info(L"test");

        T100Log::stop();

        T100Log::remove(log);

        T100SAFE_DELETE(log);

        if(!file.exists()){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_LIBRARY_LOG_TEST_STOP);
    return result;
}

}
