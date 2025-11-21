#ifndef T100CPU64BASE_H
#define T100CPU64BASE_H

#include "T100CPU.h"
#include "T100Instruct.h"
#include "T100Register64.h"
#include "T100Register128.h"

class T100Host64;

class T100CPU64Base : public T100CPU
{
    public:
        T100CPU64Base(T100Host64*);
        virtual ~T100CPU64Base();

        T100BOOL                    Pulse();

        T100Register64              m_rax;
        T100Register64              m_rbx;
        T100Register64              m_rcx;
        T100Register64              m_rdx;

        T100Register64              m_rsi;
        T100Register64              m_rdi;
        T100Register64              m_rbp;
        T100Register64              m_rsp;

        T100Register64              m_rip;
        T100Register64              m_cs;
        T100Register64              m_ss;
        T100Register64              m_ds;
        T100Register64              m_es;
        T100Register64              m_fs;
        T100Register64              m_gs;
        T100Register64              m_fsBase;
        T100Register64              m_gsBase;
        T100Register64              m_kGsBase;

        T100Register64              m_r8;
        T100Register64              m_r9;
        T100Register64              m_r10;
        T100Register64              m_r11;

        T100Register64              m_r12;
        T100Register64              m_r13;
        T100Register64              m_r14;
        T100Register64              m_r15;

        T100Register64              m_eflags;

        T100Register64              m_cr0;
        T100Register64              m_cr2;
        T100Register64              m_cr3;
        T100Register64              m_cr4;
        T100Register64              m_cr8;

        T100Register64              m_efer;
        T100Register64              m_mxcsr;

        T100Register128             m_xmm[16];

    protected:
        std::atomic_bool            m_flag;
        std::atomic_uint            m_delay;
        std::atomic_uint            m_count;
        T100Host64*                 m_host      = T100NULL;
        T100INSTRUCT_HASH           m_instructs;

        T100UINT64                  GetAddress();

    private:
};

#endif // T100CPU64BASE_H
