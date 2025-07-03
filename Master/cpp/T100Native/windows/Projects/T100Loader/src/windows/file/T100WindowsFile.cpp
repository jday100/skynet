#include "T100WindowsFile.h"

#include "T100WindowsFileDecoder.h"

namespace T100WINDOWS{

T100WindowsFile::T100WindowsFile(const T100WSTRING& file) :
    T100BinaryFile(file)
{
    //ctor
}

T100WindowsFile::~T100WindowsFile()
{
    //dtor
}

T100BOOL T100WindowsFile::Load()
{
    T100WindowsFileInfo             info;
    T100WindowsFileDecoder          decoder(this);

    decoder.Decode(info);
}

}
