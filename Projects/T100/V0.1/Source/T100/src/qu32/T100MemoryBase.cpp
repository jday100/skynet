#include "T100MemoryBase.h"

namespace T100QU32{

T100MemoryBase::T100MemoryBase(T100QU32* host)
    :m_host(host)
{
    //ctor
}

T100MemoryBase::~T100MemoryBase()
{
    //dtor
}

T100QU32* T100MemoryBase::getHost()
{
    return m_host;
}

}
