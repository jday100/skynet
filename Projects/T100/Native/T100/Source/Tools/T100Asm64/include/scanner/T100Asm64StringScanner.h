#ifndef T100ASM64STRINGSCANNER_H
#define T100ASM64STRINGSCANNER_H

#include "T100Scanner.h"
#include "T100Asm64LetterToken.h"
#include "T100Asm64LetterScanner.h"
#include "T100Asm64StringToken.h"


class T100Asm64StringScanner : public T100Scanner
{
    public:
        T100Asm64StringScanner();
        virtual ~T100Asm64StringScanner();

        T100VOID            setSource(T100Scanner*);
        T100Scanner*        getSource();

        T100BOOL            next(T100Token&);

    protected:
        T100Asm64StringToken*       m_token         = T100NULL;
        T100Asm64LetterToken        m_item;

        T100BOOL            read();
        T100BOOL            append();
        T100VOID            clear();
        T100BOOL            classify();
        T100BOOL            isOperator();

    private:
        T100Asm64LetterScanner*     m_scanner       = T100NULL;
};

#endif // T100ASM64STRINGSCANNER_H
