#include "T100SegmentData.h"

T100SegmentData::T100SegmentData()
    :m_label_call()
{
    //ctor
}

T100SegmentData::~T100SegmentData()
{
    //dtor
}

T100BOOL T100SegmentData::addLabelCall(T100LABEL_CALL* c)
{
    T100Log::info("DATA add Label call");

    m_label_call.push_back(c);
    return T100TRUE;
}
