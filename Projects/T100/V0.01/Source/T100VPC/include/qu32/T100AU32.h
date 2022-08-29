#ifndef T100AU32_H
#define T100AU32_H

#include "T100Register32.h"
class T100QU32;


class T100AU32
{
    friend class T100Order;
    public:
        T100AU32(T100QU32*);
        virtual ~T100AU32();

        T100VOID                Add();
        T100VOID                Sub();
        T100VOID                Mul();
        T100VOID                Div();
        //
        T100VOID                And();
        T100VOID                Or();
        T100VOID                Not();
        T100VOID                Xor();
        //

        T100VOID                setAAR(T100WORD);
        T100WORD                getAAR();
        T100VOID                setABR(T100WORD);
        T100WORD                getABR();
        T100VOID                setACR(T100WORD);
        T100WORD                getACR();
        T100VOID                setADR(T100WORD);
        T100WORD                getADR();

        T100WORD                getACF();
        T100WORD                getAMF();
        T100WORD                getAOF();

    protected:
        T100VOID                setACF(T100WORD);
        T100VOID                setAMF(T100WORD);
        T100VOID                setAOF(T100WORD);

    private:
        T100QU32*               m_host          = T100NULL;

        T100Register32          m_aar;
        T100Register32          m_abr;
        T100Register32          m_acr;
        T100Register32          m_adr;
        //
        T100Register32          m_acf;          //carry
        T100Register32          m_amf;          //minus
        T100Register32          m_aof;          //overflow

};

#endif // T100AU32_H
