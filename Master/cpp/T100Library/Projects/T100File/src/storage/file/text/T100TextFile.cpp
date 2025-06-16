#include "storage/file/text/T100TextFile.h"

namespace T100LIBRARY{

T100TextFile::T100TextFile(const T100WSTRING& name) :
    T100File(name)
{
    //ctor
}

T100TextFile::~T100TextFile()
{
    //dtor
}

T100TextFileReader& T100TextFile::CreateReader()
{

}

T100VOID T100TextFile::DestroyReader(T100TextFileReader& reader)
{

}

T100TextFileWriter& T100TextFile::CreateWriter()
{

}

T100VOID T100TextFile::DestroyWriter(T100TextFileWriter& writer)
{

}
T100TextFileAccessor& T100TextFile::CreateAccessor()
{

}

T100VOID T100TextFile::DestroyAccessor(T100TextFileAccessor& accessor)
{

}

}
