#include "T100VirtualFile.h"
#include "T100String.h"


T100VirtualFile::T100VirtualFile(T100STRING file)
    :T100ProduceFile(file.to_wstring())
{
    //ctor
}

T100VirtualFile::~T100VirtualFile()
{
    //dtor
}

T100VirtualFileReader* T100VirtualFile::getReader()
{
    T100VirtualFileReader*      result      = T100NULL;

    result = T100NEW T100VirtualFileReader(getName());

    return result;
}

T100VirtualFileWriter* T100VirtualFile::getWriter()
{
    T100VirtualFileWriter*      result      = T100NULL;

    result = T100NEW T100VirtualFileWriter(getName());

    return result;
}
