#include "T100VirtualFileWriter.h"

namespace T100Assembly{

T100VirtualFileWriter::T100VirtualFileWriter(T100STRING file)
    :T100Component::T100ExecutableFileWriter(file)
{
    //ctor
}

T100VirtualFileWriter::~T100VirtualFileWriter()
{
    //dtor
}

T100BOOL T100VirtualFileWriter::save(T100VirtualInfo& info)
{
    return T100ExecutableFileWriter::save(info);
}

}
