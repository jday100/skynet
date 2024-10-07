#include "T100FileTest.h"

#include "T100CPPSetting.h"
#include "T100File.h"
#include "T100BinaryFileReader.h"

T100FileTest::T100FileTest()
    :T100Test()
{
    //ctor
}

T100FileTest::~T100FileTest()
{
    //dtor
}

T100BOOL T100FileTest::run()
{
    T100BOOL        result          = T100FALSE;

    result  = binary_test();
}

T100BOOL T100FileTest::text_test()
{

}

T100BOOL T100FileTest::binary_test()
{
    T100WString                 name;
    T100File                    file;
    T100BYTE*                   data        = T100NULL;
    T100INTEGER                 length      = 0;

    T100BinaryFileReader&       reader      = file.GetBinaryReader();

    //file.open();
    reader.open();

    reader.read(data, length);

    //file.close();
    reader.close();

    return T100FALSE;
}
