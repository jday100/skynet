#include "T100QU32Timer.h"

#include "T100OrderTypes.h"
#include "T100QU32Notifier.h"
#include "T100QU32.h"


T100QU32Timer::T100QU32Timer()
{
    //ctor
}

T100QU32Timer::~T100QU32Timer()
{
    //dtor
}

T100VOID T100QU32Timer::setHost(T100QU32* host)
{
    m_host = host;
}

T100QU32* T100QU32Timer::getHost()
{
    return m_host;
}

T100BOOL T100QU32Timer::OnTimer()
{
    T100WORD    value;

    if(m_host->getNotifier().m_cor){
        value = m_host->getCU32()->m_cor.getValue();
        m_host->getCallback()->notify_register_update(T100COR, value);
    }
    if(m_host->getNotifier().m_cbr){
        value = m_host->getCU32()->m_cbr.getValue();
        m_host->getCallback()->notify_register_update(T100CBR, value);
    }
    if(m_host->getNotifier().m_ccr){
        value = m_host->getCU32()->m_ccr.getValue();
        m_host->getCallback()->notify_register_update(T100CCR, value);
    }

    if(m_host->getNotifier().m_aar){
        value = m_host->getAU32()->getAAR();
        m_host->getCallback()->notify_register_update(T100AAR, value);
    }
    if(m_host->getNotifier().m_abr){
        value = m_host->getAU32()->getABR();
        m_host->getCallback()->notify_register_update(T100ABR, value);
    }
    if(m_host->getNotifier().m_acr){
        value = m_host->getAU32()->getACR();
        m_host->getCallback()->notify_register_update(T100ACR, value);
    }
    if(m_host->getNotifier().m_adr){
        value = m_host->getAU32()->getADR();
        m_host->getCallback()->notify_register_update(T100ADR, value);
    }
    if(m_host->getNotifier().m_acf){
        value = m_host->getAU32()->getACF();
        m_host->getCallback()->notify_register_update(T100ACF, value);
    }
    if(m_host->getNotifier().m_amf){
        value = m_host->getAU32()->getAMF();
        m_host->getCallback()->notify_register_update(T100AMF, value);
    }
    if(m_host->getNotifier().m_aof){
        value = m_host->getAU32()->getAOF();
        m_host->getCallback()->notify_register_update(T100AOF, value);
    }

    m_host->getNotifier().init();
    return T100FALSE;
}

T100VOID T100QU32Timer::run()
{
    while(running()){
        sleep(100);
        OnTimer();
    }
}
