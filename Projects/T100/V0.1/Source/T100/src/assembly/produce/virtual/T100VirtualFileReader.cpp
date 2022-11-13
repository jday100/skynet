#include "T100VirtualFileReader.h"

namespace T100Assembly{

T100VirtualFileReader::T100VirtualFileReader(T100STRING file)
    :T100Component::T100ExecutableFileReader(file)
{
    //ctor
}

T100VirtualFileReader::~T100VirtualFileReader()
{
    //dtor
}

}
