#include "T100PartFile.h"

namespace T100Assembly{

T100PartFile::T100PartFile(T100STRING file)
    :T100Library::T100File(file.to_wstring())
{
    //ctor
}

T100PartFile::~T100PartFile()
{
    //dtor
}

T100PartFileReader* T100PartFile::getReader()
{
    T100PartFileReader*     result          = T100NULL;

    result = T100NEW T100PartFileReader(getName());

    return result;
}

T100PartFileWriter* T100PartFile::getWriter()
{
    T100PartFileWriter*     result          = T100NULL;

    result = T100NEW T100PartFileWriter(getName());

    return result;
}


}
