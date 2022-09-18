#include "T100QU32Notifier.h"

T100QU32Notifier::T100QU32Notifier()
{
    //ctor
}

T100QU32Notifier::~T100QU32Notifier()
{
    //dtor
}

T100VOID T100QU32Notifier::init()
{
    m_cor   = T100FALSE;
    m_cbr   = T100FALSE;
    m_ccr   = T100FALSE;
    m_aar   = T100FALSE;
    m_abr   = T100FALSE;
    m_acr   = T100FALSE;
    m_adr   = T100FALSE;
    m_acf   = T100FALSE;
    m_amf   = T100FALSE;
    m_aof   = T100FALSE;
}

T100BOOL T100QU32Notifier::start()
{
    init();
    m_timer.start();
}

T100BOOL T100QU32Notifier::stop()
{
    m_timer.stop();
}

T100VOID T100QU32Notifier::notify_register_cor()
{
    m_cor = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_cbr()
{
    m_cbr = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_ccr()
{
    m_ccr = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_aar()
{
    m_aar = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_abr()
{
    m_abr = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_acr()
{
    m_acr = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_adr()
{
    m_adr = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_acf()
{
    m_acf = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_amf()
{
    m_amf = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_aof()
{
    m_aof = T100TRUE;
}

T100VOID T100QU32Notifier::notify_memory_update(T100WORD offset, T100WORD value)
{

}

T100VOID T100QU32Notifier::notify_port_update(T100WORD offset, T100WORD value)
{

}
