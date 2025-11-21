#include "T100BackInfo.h"

namespace T100LIBRARY{

T100BackInfo::T100BackInfo() :
    T100Class(),
    m_sources()
{
    //ctor
}

T100BackInfo::~T100BackInfo()
{
    //dtor
}

const T100WSTRING& T100BackInfo::GetFileName()
{
    return m_filename;
}


}
