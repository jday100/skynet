#include "T100ExecutableFile.h"

namespace T100Component{

T100ExecutableFile::T100ExecutableFile(T100STRING file)
    :T100Library::T100File(file.to_wstring())
{
    //ctor
}

T100ExecutableFile::~T100ExecutableFile()
{
    //dtor
}

T100ExecutableFileReader* T100ExecutableFile::getReader()
{
    T100ExecutableFileReader*       result          = T100NULL;

    result = T100NEW T100ExecutableFileReader(getName());

    return result;
}

T100ExecutableFileWriter* T100ExecutableFile::getWriter()
{
    T100ExecutableFileWriter*       result          = T100NULL;

    result = T100NEW T100ExecutableFileWriter(getName());

    return result;
}

}
