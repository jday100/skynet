#include "T100OSTest.h"

#include "T100TestTools.h"
#include "T100OSSetup.h"
#include "T100Assembly.h"


T100OSTest::T100OSTest()
{
    //ctor
}

T100OSTest::~T100OSTest()
{
    //dtor
}

T100BOOL T100OSTest::do_test()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = test_int();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100OSTest::test_int()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100String          source;
    T100String          target;
    T100String          confirm;

    T100WSTRING         s;
    T100WSTRING         t;

    T100Assembly        assembly;


    s  = T100OSSetup::getTestOS(L"test_int.txt").to_wstring();
    t  = T100OSSetup::getTestBuild(L"test_int.bin");

    value = assembly.run(s, t);
    if(!value){
        return T100FALSE;
    }

    if(result){
        value = T100TestTools::Exists(t);
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}
