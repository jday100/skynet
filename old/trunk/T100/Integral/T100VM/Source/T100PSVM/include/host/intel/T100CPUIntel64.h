#ifndef T100CPUINTEL64_H
#define T100CPUINTEL64_H

#include "T100CPU.h"
#include "T100Instruct.h"
#include "T100Register64.h"
#include "T100Register128.h"

class T100BusIntel64;

class T100CPUIntel64 : public T100CPU
{
    public:
        T100CPUIntel64();
        virtual ~T100CPUIntel64();

        virtual T100VOID            SetBus(T100Bus*);

        virtual T100BOOL            Pulse();

        virtual T100VOID            Info(T100DebugFrame*);

        T100BOOL                    Read(T100BYTE*);
        T100BOOL                    Read(T100UINT16*);
        T100BOOL                    Read(T100UINT32*);


        T100UINT16                  GetAL();

        T100VOID                    SetRIP(T100UINT64);
        T100UINT64                  GetRIP();

        T100VOID                    SetEflags(T100UINT64);
        T100UINT64                  GetEflags();

    protected:
        T100BusIntel64*             m_bus       = T100NULL;
        T100INSTRUCT_HASH           m_instructs;

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

    private:
        T100VOID                    Add();

        T100VOID                    Parse0F();
        T100VOID                    Parse20();

    private:
        T100UINT64                  GetAddress();
        T100VOID                    Execute(T100BYTE);

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100CPUINTEL64_H
