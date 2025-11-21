#include "T100NTFile.h"

namespace T100LIBRARY{

T100NTFile::T100NTFile(const T100WSTRING& label) :
    T100BinaryFile(label)
{
    //ctor
}

T100NTFile::~T100NTFile()
{
    //dtor
}

T100BOOL T100NTFile::Save()
{
    T100BinaryFileWriter*       writer      = this->CreateWriter();



    this->DestroyWriter(writer);
}

}
