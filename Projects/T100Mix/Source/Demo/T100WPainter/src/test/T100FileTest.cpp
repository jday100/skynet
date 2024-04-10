#include "T100FileTest.h"

#include "T100File.h"

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
    T100BOOL            result;
    T100STRING          filename;
    T100WCHAR*          data;
    T100WORD            length;
    T100WORD            value;

    filename            = L"test.txt";

    T100File            reader(filename);

    data    = (T100WCHAR*)&value;
    length  = 2;

    result  = reader.open();
    if(result){
        result  = reader.read(data, length);

        result  = reader.close() ? result : T100FALSE;
    }
    return result;
}

T100BOOL T100FileTest::save()
{
    T100BOOL            result;
    T100STRING          filename;
    T100WCHAR*          data;
    T100WORD            length;
    T100WORD            value;

    filename            = L"test.txt";

    value   = 0xffffffff;
    data    = (T100WCHAR*)&value;
    length  = 2;

    T100File            writer(filename);

    result  = writer.open();

    if(result){
        result  = writer.write(data, length);

        result  = writer.close() ? result : T100FALSE;
    }
    return result;
}
