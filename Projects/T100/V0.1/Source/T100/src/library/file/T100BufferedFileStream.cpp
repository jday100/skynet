#include "T100BufferedFileStream.h"

namespace T100Library{

T100BufferedFileStream::T100BufferedFileStream(T100WSTRING file)
    :T100FileStream(file)
{
    //ctor
}

T100BufferedFileStream::~T100BufferedFileStream()
{
    //dtor
}

}
