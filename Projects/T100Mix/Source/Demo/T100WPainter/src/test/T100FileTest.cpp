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

}

T100BOOL T100FileTest::save()
{
    T100BOOL            result;
    T100STRING          filename;
    T100WCHAR*          data;
    T100WORD            length;

    filename            = L"test.txt";


    T100File            writer(filename);

    result  = writer.open();

    if(result){
        result  = writer.write(data, length);

        result  = writer.close() ? result : T100FALSE;
    }
    return result;
}
