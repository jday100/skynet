#include "T100FileDemo.h"

#include "console/T100Console.h"
#include "file/text/T100TextFile.h"

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

    T100TextFileWriter*     writer      = T100NULL;

    writer  = text.GetWriter();

    writer->Write(L"hello world!");

    text.FreeWriter(writer);

    T100TextFileReader*     reader      = T100NULL;

    reader  = text.GetReader();

    T100WSTRING         result;

    reader->Read(result);

    text.FreeReader(reader);

    T100Console     console;

    console.OutLine(result);

}
