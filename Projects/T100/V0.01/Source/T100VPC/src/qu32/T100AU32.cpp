#include "T100AU32.h"
#include "T100QU32Setup.h"
#include "T100OrderTypes.h"
#include "T100QU32.h"
#include "T100QU32Interface.h"
#include "T100QU32Notifier.h"


T100AU32::T100AU32(T100QU32* host)
    :m_host(host)
{
    //ctor
}

T100AU32::~T100AU32()
{
    //dtor
}

T100VOID T100AU32::setAAR(T100WORD value)
{
    m_aar.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100AAR, value);
        m_host->getNotifier().notify_register_aar();
    }
}

T100WORD T100AU32::getAAR()
{
    return m_aar.getValue();
}

T100VOID T100AU32::setABR(T100WORD value)
{
    m_abr.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100ABR, value);
        m_host->getNotifier().notify_register_abr();
    }
}

T100WORD T100AU32::getABR()
{
    return m_abr.getValue();
}

T100VOID T100AU32::setACR(T100WORD value)
{
    m_acr.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100ACR, value);
        m_host->getNotifier().notify_register_acr();
    }
}

T100WORD T100AU32::getACR()
{
    return m_acr.getValue();
}

T100VOID T100AU32::setADR(T100WORD value)
{
    m_adr.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100ADR, value);
        m_host->getNotifier().notify_register_adr();
    }
}

T100WORD T100AU32::getADR()
{
    return m_adr.getValue();
}

T100VOID T100AU32::setACF(T100WORD value)
{
    m_acf.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100ACF, value);
        m_host->getNotifier().notify_register_acf();
    }
}

T100WORD T100AU32::getACF()
{
    return m_acf.getValue();
}

T100VOID T100AU32::setAMF(T100WORD value)
{
    m_amf.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100AMF, value);
        m_host->getNotifier().notify_register_amf();
    }
}

T100WORD T100AU32::getAMF()
{
    return m_amf.getValue();
}

T100VOID T100AU32::setAOF(T100WORD value)
{
    m_aof.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100AOF, value);
        m_host->getNotifier().notify_register_aof();
    }
}

T100WORD T100AU32::getAOF()
{
    return m_aof.getValue();
}
//
T100VOID T100AU32::Add()
{
    T100WORD a, b, c, d;
    T100DWORD_BITS value;

    a = m_aar.getValue();
    b = m_abr.getValue();

    value.DWORD = (T100DWORD)a + b;

    setACR(value.WORD_LOW.WORD);
    setADR(value.WORD_HIGH.WORD);

    if(value.WORD_HIGH.WORD > 0){
        setACF(1);
    }else{
        setACF(0);
    }
}

T100VOID T100AU32::Sub()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    if(1023 == a){
        a = 1023;
    }

    if(a >= b){
        c = a - b;
        setAMF(0);
    }else{
        c = b - a;
        setAMF(1);
    }
    d = 0;

    setACR(c);
    setADR(d);
}

T100VOID T100AU32::Mul()
{
    T100WORD a, b;
    T100DWORD_BITS value;

    a = m_aar.getValue();
    b = m_abr.getValue();

    value.DWORD = (T100DWORD)a * b;

    setACR(value.WORD_LOW.WORD);
    setADR(value.WORD_HIGH.WORD);

    if(value.WORD_HIGH.WORD > 0){
        setAOF(1);
    }else{
        setAOF(0);
    }
}

T100VOID T100AU32::Div()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = a / b;
    d = a % b;

    setACR(c);
    setADR(d);

    setAOF(0);
}

T100VOID T100AU32::And()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = a & b;
    d = 0;

    setACR(c);
    setADR(d);
}

T100VOID T100AU32::Or()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = a | b;
    d = 0;

    setACR(c);
    setADR(d);
}

T100VOID T100AU32::Not()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = !a;
    d = 0;

    setACR(c);
    setADR(d);
}

T100VOID T100AU32::Xor()
{

}
