#include "T100AU32.h"

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
}

T100WORD T100AU32::getAAR()
{
    return m_aar.getValue();
}

T100VOID T100AU32::setABR(T100WORD value)
{
    m_abr.setValue(value);
}

T100WORD T100AU32::getABR()
{
    return m_abr.getValue();
}

T100VOID T100AU32::setACR(T100WORD value)
{
    m_acr.setValue(value);
}

T100WORD T100AU32::getACR()
{
    return m_acr.getValue();
}

T100VOID T100AU32::setADR(T100WORD value)
{
    m_adr.setValue(value);
}

T100WORD T100AU32::getADR()
{
    return m_adr.getValue();
}

T100VOID T100AU32::setACF(T100WORD value)
{
    m_acf.setValue(value);
}

T100WORD T100AU32::getACF()
{
    return m_acf.getValue();
}

T100VOID T100AU32::setAMF(T100WORD value)
{
    m_amf.setValue(value);
}

T100WORD T100AU32::getAMF()
{
    return m_amf.getValue();
}

T100VOID T100AU32::setAOF(T100WORD value)
{
    m_aof.setValue(value);
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

    m_acr.setValue(value.WORD_LOW.WORD);
    m_adr.setValue(value.WORD_HIGH.WORD);

    if(value.WORD_HIGH.WORD > 0){
        m_acf.setValue(1);
    }else{
        m_acf.setValue(0);
    }
}

T100VOID T100AU32::Sub()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    if(a >= b){
        c = a - b;
        m_amf.setValue(0);
    }else{
        c = b - a;
        m_amf.setValue(1);
    }
    d = 0;

    m_acr.setValue(c);
    m_adr.setValue(d);
}

T100VOID T100AU32::Mul()
{
    T100WORD a, b;
    T100DWORD_BITS value;

    a = m_aar.getValue();
    b = m_abr.getValue();

    value.DWORD = (T100DWORD)a * b;

    m_acr.setValue(value.WORD_LOW.WORD);
    m_adr.setValue(value.WORD_HIGH.WORD);

    if(value.WORD_HIGH.WORD > 0){
        m_aof.setValue(1);
    }else{
        m_aof.setValue(0);
    }
}

T100VOID T100AU32::Div()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = a / b;
    d = a % b;

    m_acr.setValue(c);
    m_adr.setValue(d);

    m_aof.setValue(0);
}

T100VOID T100AU32::And()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = a & b;
    d = 0;

    m_acr.setValue(c);
    m_adr.setValue(d);
}

T100VOID T100AU32::Or()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = a | b;
    d = 0;

    m_acr.setValue(c);
    m_adr.setValue(d);
}

T100VOID T100AU32::Not()
{
    T100WORD a, b, c, d;

    a = m_aar.getValue();
    b = m_abr.getValue();

    c = !a;
    d = 0;

    m_acr.setValue(c);
    m_adr.setValue(d);
}

T100VOID T100AU32::Xor()
{

}
