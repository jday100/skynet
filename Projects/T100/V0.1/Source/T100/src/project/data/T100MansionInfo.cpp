#include "T100MansionInfo.h"

T100MansionInfo::T100MansionInfo()
{
    //ctor
    create();
}

T100MansionInfo::~T100MansionInfo()
{
    //dtor
    destroy();
}

T100VOID T100MansionInfo::create()
{
    m_name  = L"workspaces";
}

T100VOID T100MansionInfo::destroy()
{

}

T100VOID T100MansionInfo::setName(T100STRING name)
{
    m_name  = name;
}

T100STRING T100MansionInfo::getName()
{
    return m_name;
}
