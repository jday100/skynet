#include "T100FileTest.h"

T100FileTest::T100FileTest()
{
    //ctor
}

T100FileTest::~T100FileTest()
{
    //dtor
}

T100BOOL T100FileTest::load()
{

}

T100BOOL T100FileTest::save()
{
    T100BOOL            result;
    T100STRING          filename;
    T100WCHAR*          data;
    T100WORD            length;

    filename    = L"test.txt";

    T100File            writer(filename);

    T100WORD            value;

    value   = 0xffffffff;
    value   = 1;

    data    = (T100WCHAR*)&value;
    data    = L"你好";
    length  = 2;

    if(writer.open()){
        result  = writer.write(data, length);
        result  = writer.close() ? result : T100FALSE;
    }else{
        result  = T100FALSE;
    }

    return result;
}

T100BOOL T100FileTest::std_save()
{
    T100BOOL            result;
    T100STRING          filename;
    T100CHAR*           data;
    T100WORD            length;
    T100WORD            value;

    filename            = L"test.txt";

    value   = 0xffffffff;
    data    = (T100CHAR*)&value;
    length  = 4;

    T100StdFile         writer(filename);

    if(writer.open()){
        result  = writer.write(data, length);
        result  = writer.close() ? result : T100FALSE;
    }else{
        result  = T100FALSE;
    }

    return result;
}
