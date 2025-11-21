#include "T100VMServe.h"

#include "T100Thread.h"
#include "T100VM64.h"
#include "T100VMIntel64.h"

T100VMServe::T100VMServe(T100PSVMServe& psvm) :
    m_psvm(psvm)
{
    //ctor
}

T100VMServe::~T100VMServe()
{
    //dtor
}

T100VM* T100VMServe::GetVM()
{
    return m_vm;
}

T100BOOL T100VMServe::Start()
{
    if(m_vm){
        return T100FALSE;
    }

    m_vm    = T100NEW T100VM64();
    if(m_vm){
        m_vm->Start();
    }
    return T100TRUE;
}

T100BOOL T100VMServe::Stop()
{
    if(!m_vm){
        return T100FALSE;
    }
    if(m_vm->IsRunning()){
        m_vm->Stop();
    }
    T100SAFE_DELETE(m_vm)
    return T100TRUE;
}

T100BOOL T100VMServe::DebugStart()
{
    if(m_vm){
        return T100FALSE;
    }

    m_vm    = T100NEW T100VM64();
    if(m_vm){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100VMServe::DebugStop()
{
    if(!m_vm){
        return T100FALSE;
    }
    if(m_vm->IsRunning()){
        m_vm->Stop();
    }
    T100SAFE_DELETE(m_vm)
    return T100TRUE;
}
