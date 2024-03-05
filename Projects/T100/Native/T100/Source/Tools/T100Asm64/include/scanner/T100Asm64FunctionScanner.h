#ifndef T100ASM64FUNCTIONSCANNER_H
#define T100ASM64FUNCTIONSCANNER_H

#include "T100Scanner.h"
#include "T100Asm64SentenceToken.h"
#include "T100Asm64SentenceScanner.h"
#include "T100Asm64FunctionToken.h"


class T100Asm64FunctionScanner : public T100Scanner
{
    public:
        T100Asm64FunctionScanner();
        virtual ~T100Asm64FunctionScanner();

        T100VOID            setSource(T100Scanner*);
        T100Scanner*        getSource();

        T100BOOL            next(T100Token&);

    protected:
        T100Asm64FunctionToken*         m_token         = T100NULL;
        T100Asm64SentenceToken          m_item;

        T100BOOL            read();

        T100BOOL            parse();

    private:
        T100Asm64SentenceScanner*       m_scanner       = T100NULL;
};

#endif // T100ASM64FUNCTIONSCANNER_H
