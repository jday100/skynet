#include "T100FileTest.h"

#include "storage/file/text/T100TextFile.h"

T100FileTest::T100FileTest()
{
    //ctor
}

T100FileTest::~T100FileTest()
{
    //dtor
}

T100INT T100FileTest::test()
{
    T100WSTRING         filename        = L"../../../build/textfile.txt";
    T100TextFile        text(filename);

    if(text.IsExists()){
        text.Remove();
    }

    if(text.IsExists()){
        return -1;
    }

    T100TextFileWriterW*        writer      = text.CreateWriterW();

    T100WSTRING                 value       = L"hello world!";
    T100WSTRING                 result;

    *writer << value;

    text.DestroyWriterW(writer);

    T100TextFileReaderW*        reader      = text.CreateReaderW();

    reader->Load(result);

    text.DestroyReaderW(reader);

    if(value == result){
        return 0;
    }
    return -1;
}
