#include "T100PSVMServe.h"

#include "T100PSVMConfig.h"

T100PSVMServe::T100PSVMServe() :
    m_vm(*this)
{
    //ctor
    m_opened        = T100FALSE;
    m_dirty         = T100FALSE;
}

T100PSVMServe::~T100PSVMServe()
{
    //dtor
}

T100VOID T100PSVMServe::SetDirty(T100BOOL value)
{
    m_dirty     = value;
}

T100PSVMInfo* T100PSVMServe::GetPSVMInfo()
{
    return m_info;
}

T100VMServe& T100PSVMServe::GetVMServe()
{
    return m_vm;
}

T100BOOL T100PSVMServe::IsOpened()
{
    return m_opened;
}

T100BOOL T100PSVMServe::IsDirty()
{
    return m_dirty;
}

T100BOOL T100PSVMServe::Create(T100PSVMInfo*& info)
{
    info    = T100NEW T100PSVMInfo();

    if(info){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100PSVMServe::Open(T100PSVMInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100PSVMConfig::m_firmware      = info->m_firmware;

    m_info      = info;
    m_opened    = T100TRUE;
    return T100TRUE;
}

T100BOOL T100PSVMServe::Close()
{
    if(!m_info){
        return T100FALSE;
    }

    T100SAFE_DELETE(m_info)
    m_opened    = T100FALSE;
    return T100TRUE;
}
