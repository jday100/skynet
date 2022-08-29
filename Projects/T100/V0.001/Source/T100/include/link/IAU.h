#ifndef IAU_H
#define IAU_H

#include "T100Common.h"
class IComputer;


class IAU
{
    public:
        IAU(IComputer*);
        virtual ~IAU();

        virtual T100VOID            Add()=0;
        virtual T100VOID            Sub()=0;
        virtual T100VOID            Mul()=0;
        virtual T100VOID            Div()=0;
        //
        virtual T100VOID            And()=0;
        virtual T100VOID            Or()=0;
        virtual T100VOID            Not()=0;
        virtual T100VOID            Xor()=0;
        //
        virtual T100VOID            setAAR(T100WORD)=0;
        virtual T100WORD            getAAR()=0;
        virtual T100VOID            setABR(T100WORD)=0;
        virtual T100WORD            getABR()=0;
        virtual T100VOID            setACR(T100WORD)=0;
        virtual T100WORD            getACR()=0;
        virtual T100VOID            setADR(T100WORD)=0;
        virtual T100WORD            getADR()=0;
        //
        virtual T100WORD            getACF()=0;
        virtual T100WORD            getAMF()=0;
        virtual T100WORD            getAOF()=0;

    protected:
        virtual T100VOID            setACF(T100WORD)=0;
        virtual T100VOID            setAMF(T100WORD)=0;
        virtual T100VOID            setAOF(T100WORD)=0;

    private:
        IComputer*                  m_host              = T100NULL;
};

#endif // IAU_H
