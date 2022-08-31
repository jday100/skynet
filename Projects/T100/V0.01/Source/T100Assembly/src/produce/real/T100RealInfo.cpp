#include "T100RealInfo.h"

T100RealInfo::T100RealInfo()
{
    //ctor
    create();
}

T100RealInfo::~T100RealInfo()
{
    //dtor
    destroy();
}

T100VOID T100RealInfo::create()
{
    m_code.getMem().resize(0);
    m_data.getMem().resize(0);
}

T100VOID T100RealInfo::destroy()
{

}

T100SegmentCode& T100RealInfo::getCode()
{
    return m_code;
}

T100SegmentData& T100RealInfo::getData()
{
    return m_data;
}
