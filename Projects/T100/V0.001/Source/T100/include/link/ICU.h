#ifndef ICU_H
#define ICU_H

#include "T100Common.h"
class IComputer;


class ICU
{
    friend class T100OrderJz;
    friend class T100OrderJnz;
    friend class T100OrderJump;
    friend class T100OrderLoop;
    friend class T100Interrupt32;
    friend class T100OrderRunner;
    public:
        ICU(IComputer*);
        virtual ~ICU();

        virtual T100WORD            getCOR()=0;
        virtual T100WORD            getCBR()=0;
        virtual T100WORD            getCCR()=0;

        virtual T100VOID            setCCR(T100WORD)=0;

        virtual T100WORD            step()=0;
        virtual T100WORD            getCurrent()=0;

    protected:
        IComputer*                  m_host              = T100NULL;

        virtual T100VOID            setCOR(T100WORD)=0;
        virtual T100VOID            setCBR(T100WORD)=0;

    private:

};

#endif // ICU_H
