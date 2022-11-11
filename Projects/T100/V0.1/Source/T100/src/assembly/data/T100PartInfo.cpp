#include "T100PartInfo.h"

namespace T100Assembly{

T100PartInfo::T100PartInfo()
{
    //ctor
}

T100PartInfo::~T100PartInfo()
{
    //dtor
}

T100VOID T100PartInfo::setName(T100STRING name)
{
    m_name = name;
}

T100STRING T100PartInfo::getName()
{
    return m_name;
}

T100ParseInfo& T100PartInfo::getParseInfo()
{
    return m_parse_info;
}

T100BuildInfo& T100PartInfo::getBuildInfo()
{
    return m_build_info;
}

}
