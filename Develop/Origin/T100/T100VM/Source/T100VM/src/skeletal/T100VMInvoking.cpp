#include "T100VMInvoking.h"

#include "hyperv/T100HyperV.h"

T100HostBase*           T100VMInvoking::m_host                  = T100NULL;

T100VMInvoking::T100VMInvoking()
{
    //ctor
}

T100VMInvoking::~T100VMInvoking()
{
    //dtor
}

T100VOID T100VMInvoking::OnStart()
{
    m_host  = T100NEW T100HyperV();

    m_host->Start();
}

T100VOID T100VMInvoking::OnStop()
{
    if(m_host){
        m_host->Stop();
    }
}
