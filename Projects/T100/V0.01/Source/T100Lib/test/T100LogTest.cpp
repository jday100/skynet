#include "T100LogTest.h"

#include "T100Log.h"
#include "T100File.h"
#include "T100LibTestHint.h"
#include "T100LogAppenderFile.h"


T100WSTRING         T100LogTest::m_name             = L"log";


T100LogTest::T100LogTest(T100Test* parent)
    :T100Test(parent, m_name)
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
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_LOG_TEST_START);

    T100WSTRING         name;
    T100LogAppender*    log         = T100NULL;

    name    = L"logs\\app.log";
    log     = T100NEW T100LogAppenderFile(name);

    T100File    file(name);

    if(!file.exists()){
        result = T100FALSE;
    }

    T100Log::append(log);

    T100Log::erase(log);

    T100SAFE_DELETE(log);

    show_result(result, T100TEST_HINT_LIB_LOG_TEST_STOP);
    return result;
}
