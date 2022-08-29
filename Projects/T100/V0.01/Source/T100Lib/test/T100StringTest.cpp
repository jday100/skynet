#include "T100StringTest.h"
#include "T100Log.h"
#include "T100LibTestHint.h"
#include "T100String.h"
#include "T100Unicode.h"


T100WSTRING         T100StringTest::m_name              = L"string";


T100StringTest::T100StringTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100StringTest::~T100StringTest()
{
    //dtor
}

T100BOOL T100StringTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_std8();
    if(!value){
        result = T100FALSE;
    }

    value = test_std16();
    if(!value){
        result = T100FALSE;
    }

    value = test_std32();
    if(!value){
        result = T100FALSE;
    }

    value = test_wstring();
    if(!value){
        result = T100FALSE;
    }

    value = test_string();
    if(!value){
        result = T100FALSE;
    }

    value = test_unicode();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100StringTest::test_std8()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_STD8_TEST_START);

    T100String  source;
    T100String  target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;
    }
    if(result){
        source  = u8"1";
        target  = u8"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;
    }
    if(result){
        if(source != target)result = T100FALSE;
    }
    if(result){
        source  = u8"2";
        target  = u8"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;
    }
    if(result){
        if(u8"2" != source)result = T100FALSE;
        if(u8"3" != target)result = T100FALSE;

        if(source != u8"2")result = T100FALSE;
        if(target != u8"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(u8"2" != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_STD8_TEST_STOP);
    return result;
}

T100BOOL T100StringTest::test_std16()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_STD16_TEST_START);

    T100String  source;
    T100String  target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;
    }
    if(result){
        source  = u"1";
        target  = u"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;
    }
    if(result){
        if(source != target)result = T100FALSE;
    }
    if(result){
        source  = u"2";
        target  = u"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;
    }
    if(result){
        if(u"2" != source)result = T100FALSE;
        if(u"3" != target)result = T100FALSE;

        if(source != u"2")result = T100FALSE;
        if(target != u"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(u"2" != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_STD16_TEST_STOP);
    return result;
}

T100BOOL T100StringTest::test_std32()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_STD32_TEST_START);

    T100String  source;
    T100String  target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;
    }
    if(result){
        source  = U"1";
        target  = U"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;
    }
    if(result){
        if(source != target)result = T100FALSE;
    }
    if(result){
        source  = U"2";
        target  = U"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;
    }
    if(result){
        if(U"2" != source)result = T100FALSE;
        if(U"3" != target)result = T100FALSE;

        if(source != U"2")result = T100FALSE;
        if(target != U"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(U"2" != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_STD32_TEST_STOP);
    return result;
}

T100BOOL T100StringTest::test_wstring()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_WSTRING_TEST_START);

    T100String  source;
    T100String  target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;
    }
    if(result){
        source  = L"1";
        target  = L"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(source != target)result = T100FALSE;
    }
    if(result){
        source  = L"2";
        target  = L"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(L"2" != source)result = T100FALSE;
        if(L"3" != target)result = T100FALSE;

        if(source != L"2")result = T100FALSE;
        if(target != L"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(L"2" != target)result = T100FALSE;
    }

    if(result){
        source.clear();
        target.clear();

        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    if(result){
        source  = L"hello world!";
        target  = L"hello world!";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(12 != source.length())result = T100FALSE;
        if(12 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_WSTRING_TEST_STOP);
    return result;
}

T100BOOL T100StringTest::test_string()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_CUSTOM_TEST_START);

    T100String  source;
    T100String  target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;
    }
    if(result){
        source  = "1";
        target  = L"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        //if(source != target)result = T100FALSE;
        if(target != source)result = T100FALSE;
    }
    if(result){
        source  = L"2";
        target  = L"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(L"2" != source)result = T100FALSE;
        if(L"3" != target)result = T100FALSE;

        if(source != L"2")result = T100FALSE;
        if(target != L"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(L"2" != target)result = T100FALSE;
    }

    if(result){
        source.clear();
        target.clear();

        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    if(result){
        source  = L"hello world!";
        target  = L"hello world!";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(12 != source.length())result = T100FALSE;
        if(12 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_CUSTOM_TEST_STOP);
    return result;
}

T100BOOL T100StringTest::test_unicode()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_UNICODE_TEST_START);

    T100STRING8     s8, t8;
    T100STRING16    s16, t16;
    T100STRING32    s32, t32;
    T100WSTRING     sw, tw;
    T100STRING      ss, ts;

    s8      = u8"ascii";
    s16     = T100Unicode::to_string16(s8);
    s32     = T100Unicode::to_string32(s16);
    sw      = T100Unicode::to_wstring(s32);
    ss      = T100String(sw.c_str());

    t8      = "ascii";
    t16     = u"ascii";
    t32     = U"ascii";
    tw      = L"ascii";
    ts      = T100String("ascii");

    if(s8 != t8)result = T100FALSE;
    if(s16 != t16)result = T100FALSE;
    if(s32 != t32)result = T100FALSE;
    if(sw != tw)result = T100FALSE;
    if(ss != ts)result = T100FALSE;


    show_result(result, T100TEST_HINT_LIB_STRING_UNICODE_TEST_STOP);
    return result;
}
