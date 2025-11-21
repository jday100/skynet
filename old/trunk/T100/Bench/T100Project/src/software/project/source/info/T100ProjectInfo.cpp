#include "T100ProjectInfo.h"

T100ProjectInfo::T100ProjectInfo() :
    m_projectData(L"")
{
    //ctor
}

T100ProjectInfo::~T100ProjectInfo()
{
    //dtor
}

T100VOID T100ProjectInfo::SetProjectData(const T100Project& data)
{
    m_projectData       = data;
}

const T100Project& T100ProjectInfo::GetProjectData()
{
    return m_projectData;
}
