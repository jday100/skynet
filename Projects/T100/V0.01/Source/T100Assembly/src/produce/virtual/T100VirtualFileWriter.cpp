#include "T100VirtualFileWriter.h"
#include "T100String.h"


T100VirtualFileWriter::T100VirtualFileWriter(T100STRING file)
    :T100ExecutableFileWriter(file)
{
    //ctor
}

T100VirtualFileWriter::~T100VirtualFileWriter()
{
    //dtor
}

T100BOOL T100VirtualFileWriter::save(T100VirtualInfo& info)
{
    T100ExecutableInfo      exeInfo;

    return T100ExecutableFileWriter::save(exeInfo);
}
