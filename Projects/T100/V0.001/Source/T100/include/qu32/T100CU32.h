#ifndef T100CU32_H
#define T100CU32_H

#include "ICU.h"
#include "T100Register32.h"
class T100QU32;


class T100CU32 : public ICU
{
    friend class T100QU32;
    friend class T100Order;
    friend class T100OrderJz;
    friend class T100OrderJnz;
    friend class T100OrderJump;
    friend class T100OrderLoop;
    friend class T100Interrupt32;
    friend class T100OrderRunner;
    friend class T100VPCDebugFrame;
    public:
        T100CU32(T100QU32*);
        virtual ~T100CU32();

        T100WORD                getCOR();
        T100WORD                getCBR();
        T100WORD                getCCR();

        T100VOID                setCCR(T100WORD);

        T100WORD                step();
        T100WORD                getCurrent();

        T100QU32*               getHost();

    protected:
        T100VOID                setCOR(T100WORD);
        T100VOID                setCBR(T100WORD);

    private:
        T100Register32          m_cbr;              //Base
        T100Register32          m_cor;              //Order

        T100Register32          m_scr;              //Code
        T100Register32          m_sdr;              //Data

        T100Register32          m_dsr;              //Source
        T100Register32          m_dtr;              //Target

        T100Register32          m_ccr;              //Count

};

#endif // T100CU32_H
