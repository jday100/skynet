#include "T100PartFile.h"
#include "T100String.h"


T100PartFile::T100PartFile(T100String file)
    :T100File(file.to_wstring())
{
    //ctor
}

T100PartFile::~T100PartFile()
{
    //dtor
}

T100PartFileReader* T100PartFile::getReader()
{
    T100PartFileReader*         result          = T100NULL;

    result = T100NEW T100PartFileReader(getName());

    return result;
}

T100PartFileWriter* T100PartFile::getWriter()
{
    T100PartFileWriter*         result          = T100NULL;

    result = T100NEW T100PartFileWriter(getName());

    return result;
}
