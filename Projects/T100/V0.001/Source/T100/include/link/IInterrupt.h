#ifndef IINTERRUPT_H
#define IINTERRUPT_H

#include "T100Common.h"
class IComputer;


class IInterrupt
{
    public:
        IInterrupt(IComputer*);
        virtual ~IInterrupt();

        virtual T100VOID            interrupt(T100BYTE)=0;

        virtual T100VOID            call(T100WORD, T100WORD)=0;
        virtual T100VOID            call(T100WORD)=0;
        virtual T100VOID            ret()=0;

        virtual T100VOID            icall(T100BYTE)=0;
        virtual T100VOID            iret()=0;

        virtual T100VOID            lock()=0;
        virtual T100VOID            unlock()=0;

    protected:
        virtual T100VOID            push()=0;
        virtual T100VOID            pop()=0;

    private:
        IComputer*                  m_host              = T100NULL;
};

#endif // IINTERRUPT_H
