#include "T100RealInfo.h"

T100RealInfo::T100RealInfo()
{
    //ctor
}

T100RealInfo::~T100RealInfo()
{
    //dtor
}

T100SegmentCode& T100RealInfo::getCode()
{
    return m_code;
}

T100SegmentData& T100RealInfo::getData()
{
    return m_data;
}
