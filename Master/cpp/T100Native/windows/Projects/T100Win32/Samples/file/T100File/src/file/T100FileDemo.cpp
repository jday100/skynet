#include "T100FileDemo.h"

#include "console/T100Console.h"
#include "storage/file/text/T100TextFile.h"

using namespace T100LIBRARY;

T100FileDemo::T100FileDemo()
{
    //ctor
}

T100FileDemo::~T100FileDemo()
{
    //dtor
}

void T100FileDemo::test()
{
    T100TextFile        text(L"demo.txt");

    if(text.IsExists()){
            text.Remove();
    }

    text.Create();

    if(text.IsExists()){

    }else{
        return;
    }

    T100TextFileWriterW*    writer      = T100NULL;

    writer  = text.CreateWriterW();

    *writer << L"hello world!";

    text.DestroyWriterW(writer);

    T100TextFileReaderW*    reader      = T100NULL;

    reader  = text.CreateReaderW();

    T100WSTRING         result;

    reader->Load(result);

    text.DestroyReaderW(reader);

    T100Console     console;

    console.OutLine(result);

}
