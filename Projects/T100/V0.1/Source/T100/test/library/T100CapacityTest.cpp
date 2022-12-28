#include "T100CapacityTest.h"

#include "T100LibraryTestHint.h"
#include "T100CapacityTools.h"


namespace T100Library{

T100WSTRING         T100CapacityTest::m_name                        = L"library.capacity";

T100CapacityTest::T100CapacityTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100CapacityTest::~T100CapacityTest()
{
    //dtor
}

T100BOOL T100CapacityTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_capacity();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CapacityTest::test_capacity()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_LIBRARY_CAPACITY_TEST_START);

    T100WSTRING     source;
    T100WSTRING     target;
    T100WORD        source_word;
    T100WORD        target_word;
    T100DWORD       source_dword;
    T100DWORD       target_dwrod;

    value = T100CapacityTools::to_word(source, target_word);
    if(value){
        result = T100FALSE;
    }

    if(result){
        source_word = 0;
        target = T100CapacityTools::to_wstring(source_word);
        if(L"0" == target){

        }else{
            result = T100FALSE;
        }
    }

    if(result){
        source  = L"0";
        value   = T100CapacityTools::to_word(source, target_word);
        if(!value){
            result = T100FALSE;
        }
    }
    if(result){
        target  = T100CapacityTools::to_wstring(target_word);
        if(source == target){

        }else{
            result = T100FALSE;
        }
    }


    show_result(result, T100TEST_HINT_LIBRARY_CAPACITY_TEST_STOP);
    return result;
}

}
