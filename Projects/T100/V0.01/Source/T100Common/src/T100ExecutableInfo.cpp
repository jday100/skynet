#include "T100ExecutableInfo.h"

#include "T100SegmentCode.h"
#include "T100SegmentData.h"


T100ExecutableInfo::T100ExecutableInfo()
{
    //ctor
    create();
}

T100ExecutableInfo::~T100ExecutableInfo()
{
    //dtor
    destroy();
}

T100VOID T100ExecutableInfo::create()
{
    //m_code = T100NEW T100SegmentCode();
    //m_data = T100NEW T100SegmentData();
}

T100VOID T100ExecutableInfo::destroy()
{

}
