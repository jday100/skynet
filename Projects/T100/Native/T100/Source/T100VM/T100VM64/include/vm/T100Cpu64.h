#ifndef T100CPU64_H
#define T100CPU64_H

#include "T100Register64.h"
#include "T100Bus64.h"


class T100Cpu64
{
    public:
        T100Cpu64(T100Bus64*);
        virtual ~T100Cpu64();


        //
        T100Register64          RAX;
        T100Register64          RBX;
        T100Register64          RCX;
        T100Register64          RDX;

        T100Register64          RBP;
        T100Register64          RSP;
        T100Register64          RSI;
        T100Register64          RDI;

        T100Register64          R8;
        T100Register64          R9;
        T100Register64          R10;
        T100Register64          R11;

        T100Register64          R12;
        T100Register64          R13;
        T100Register64          R14;
        T100Register64          R15;

        T100Register64          CS;
        T100Register64          SS;
        T100Register64          DS;
        T100Register64          ES;
        T100Register64          FS;
        T100Register64          GS;

        T100Register64          EFLAGS;
        T100Register64          EIP;

        T100Register64          GDTR;
        T100Register64          IDTR;

        T100Register64          TR;
        T100Register64          LDTR;

        T100Register64          CR0;
        T100Register64          CR1;
        T100Register64          CR2;
        T100Register64          CR3;



    public:
        T100BOOL                run();


    protected:

    private:
        T100Bus64*              m_bus           = T100NULL;
};

#endif // T100CPU64_H
