#include "T100FileStream.h"

namespace T100Library{

T100FileStream::T100FileStream(T100WSTRING file)
    :T100Stream(), m_file(file)
{
    //ctor
}

T100FileStream::~T100FileStream()
{
    //dtor
}

}
