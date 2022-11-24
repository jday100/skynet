#include "T100FullTest.h"

namespace T100{

T100WSTRING         T100FullTest::m_name                        = L"full";

T100FullTest::T100FullTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100FullTest::~T100FullTest()
{
    //dtor
}

T100BOOL T100FullTest::init()
{

    return T100FALSE;
}

T100BOOL T100FullTest::uninit()
{
    return T100TRUE;
}

T100BOOL T100FullTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = do_init();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = test_full();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = do_uninit();
        if(!value){
            result = T100FALSE;
        }
    }
    return result;
}

T100BOOL T100FullTest::test_full()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    return result;
}


}
