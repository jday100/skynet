#ifndef T100QU32NOTIFIER_H
#define T100QU32NOTIFIER_H

#include <atomic>
#include "T100QU32Timer.h"

namespace T100QU32{

class T100QU32Notifier
{
    friend class T100QU32Timer;
    friend class T100Executor32;
    public:
        T100QU32Notifier();
        virtual ~T100QU32Notifier();

        T100BOOL                start();
        T100BOOL                stop();

        T100VOID                notify_register_cor();
        T100VOID                notify_register_cbr();
        T100VOID                notify_register_ccr();

        T100VOID                notify_register_ssr();
        T100VOID                notify_register_spr();

        T100VOID                notify_register_aar();
        T100VOID                notify_register_abr();
        T100VOID                notify_register_acr();
        T100VOID                notify_register_adr();

        T100VOID                notify_register_acf();
        T100VOID                notify_register_amf();
        T100VOID                notify_register_aof();

        T100VOID                notify_cmt_update(T100WORD);
        T100VOID                notify_memory_update(T100WORD, T100WORD);
        T100VOID                notify_port_update(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100VOID                init();

    private:
        T100WORD                m_cmt_id;
        T100QU32Timer           m_timer;

        std::atomic_bool        m_running;

        std::atomic_bool        m_cmt;

        std::atomic_bool        m_cor;
        std::atomic_bool        m_cbr;
        std::atomic_bool        m_ccr;
        std::atomic_bool        m_ssr;
        std::atomic_bool        m_spr;
        std::atomic_bool        m_aar;
        std::atomic_bool        m_abr;
        std::atomic_bool        m_acr;
        std::atomic_bool        m_adr;
        std::atomic_bool        m_acf;
        std::atomic_bool        m_amf;
        std::atomic_bool        m_aof;

};

}

#endif // T100QU32NOTIFIER_H
