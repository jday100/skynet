#include "T100RealFile.h"

T100RealFile::T100RealFile(T100STRING name)
    :T100ProduceFile(name)
{
    //ctor
}

T100RealFile::~T100RealFile()
{
    //dtor
}

T100RealFileReader* T100RealFile::getReader()
{
    T100RealFileReader*         result          = T100NULL;

    result = T100NEW T100RealFileReader(getName());

    return result;
}

T100RealFileWriter* T100RealFile::getWriter()
{
    T100RealFileWriter*         result          = T100NULL;

    result = T100NEW T100RealFileWriter(getName());

    return result;
}
