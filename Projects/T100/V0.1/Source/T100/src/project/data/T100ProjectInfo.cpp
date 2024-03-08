#include "T100ProjectInfo.h"

namespace T100PROJECT{

T100ProjectInfo::T100ProjectInfo()
{
    //ctor
}

T100ProjectInfo::~T100ProjectInfo()
{
    //dtor
}

T100VOID T100ProjectInfo::setName(T100STRING name)
{
    m_name  = name;
}

T100STRING T100ProjectInfo::getName()
{
    return m_name;
}

T100VOID T100ProjectInfo::setType(T100PROJECT_TYPE type)
{
    m_type  = type;
}

T100PROJECT_TYPE T100ProjectInfo::getType()
{
    return m_type;
}

}
