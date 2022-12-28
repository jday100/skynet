#include "T100QU32Notifier.h"

namespace T100QU32{

T100QU32Notifier::T100QU32Notifier()
{
    //ctor
    create();
}

T100QU32Notifier::~T100QU32Notifier()
{
    //dtor
    destroy();
}

T100VOID T100QU32Notifier::create()
{
    m_running = T100FALSE;
}

T100VOID T100QU32Notifier::destroy()
{

}

T100VOID T100QU32Notifier::init()
{
    m_cmt       = T100FALSE;

    m_cor       = T100FALSE;
    m_cbr       = T100FALSE;
    m_ccr       = T100FALSE;
    m_ssr       = T100FALSE;
    m_spr       = T100FALSE;
    m_aar       = T100FALSE;
    m_abr       = T100FALSE;
    m_acr       = T100FALSE;
    m_adr       = T100FALSE;
    m_acf       = T100FALSE;
    m_amf       = T100FALSE;
    m_aof       = T100FALSE;
}

T100BOOL T100QU32Notifier::start()
{
    if(m_running){

    }else{
        m_running = T100TRUE;
        init();
        m_timer.start();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100QU32Notifier::stop()
{
    if(m_running){
        m_timer.stop();
        m_running = T100FALSE;
        return T100TRUE;
    }
    return T100FALSE;
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

T100VOID T100QU32Notifier::notify_register_ssr()
{
    m_ssr = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_spr()
{
    m_spr = T100TRUE;
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

T100VOID T100QU32Notifier::notify_cmt_update(T100WORD value)
{
    m_cmt_id    = value;
    m_cmt       = T100TRUE;
}

T100VOID T100QU32Notifier::notify_memory_update(T100WORD offset, T100WORD value)
{

}

T100VOID T100QU32Notifier::notify_port_update(T100WORD offset, T100WORD value)
{

}

}
