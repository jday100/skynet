#include "T100AppTest.h"

#include "T100ThisAppTest.h"

T100AppTest::T100AppTest()
{
    //ctor
}

T100AppTest::~T100AppTest()
{
    //dtor
}

T100BOOL T100AppTest::run()
{
    T100ThisAppTest::T100ThisAppTest        test_app;

    test_app.test_all();

    return T100FALSE;
}
