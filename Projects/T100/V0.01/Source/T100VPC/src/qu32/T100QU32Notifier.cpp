#include "T100QU32Notifier.h"

#include "T100TestTools.h"


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
    //T100TestTools::Print(L"init");

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
    if(m_running){

    }else{
        m_running = T100TRUE;
        init();
        m_timer.start();
    }
}

T100BOOL T100QU32Notifier::stop()
{
    if(m_running){
        m_timer.stop();
        m_running = T100FALSE;
    }
}

T100VOID T100QU32Notifier::notify_register_cor()
{
    m_cor = T100TRUE;
}

T100VOID T100QU32Notifier::notify_register_cbr()
{
    //T100TestTools::Print(&m_cbr);

    //T100TestTools::Print(to_wstring(m_cbr));
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
