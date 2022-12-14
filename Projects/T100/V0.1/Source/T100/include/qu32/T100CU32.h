#ifndef T100CU32_H
#define T100CU32_H

#include "T100Register32.h"

namespace T100QU32{
class T100QU32;


class T100CU32
{
    friend class T100QU32;
    friend class T100Order;
    friend class T100OrderJz;
    friend class T100OrderJnz;
    friend class T100OrderJump;
    friend class T100OrderLoop;
    friend class T100OrderBase;
    friend class T100OrderOrigin;
    friend class T100OrderOperator;
    friend class T100Gdt32;
    friend class T100QU32Timer;
    friend class T100Executor32;
    friend class T100Interrupt32;
    public:
        T100CU32(T100QU32*);
        virtual ~T100CU32();

        T100WORD                    getCOR();
        T100WORD                    getCBR();
        T100WORD                    getCCR();

        T100WORD                    getGDR();

        T100VOID                    setCCR(T100WORD);

        T100VOID                    setSSR(T100WORD);
        T100WORD                    getSSR();

        T100VOID                    setSPR(T100WORD);
        T100WORD                    getSPR();

        T100WORD                    step();
        T100WORD                    getCurrent();

        T100QU32*                   getHost();

        T100BOOL                    push(T100WORD);
        T100BOOL                    pop(T100WORD&);

    protected:
        T100VOID                    setCOR(T100WORD);
        T100VOID                    setCBR(T100WORD);

        T100VOID                    setGDR(T100WORD);

    private:
        T100QU32*                   m_host          = T100NULL;

        T100Register32              m_cbr;          //Base
        T100Register32              m_cor;          //Order

        T100Register32              m_scr;          //Code
        T100Register32              m_sdr;          //Data

        T100Register32              m_dsr;          //Source
        T100Register32              m_dtr;          //Target

        T100Register32              m_ccr;          //Count

        T100Register32              m_ssr;          //ss
        T100Register32              m_spr;          //sp

        T100Register32              m_gdr;

};

}

#endif // T100CU32_H
