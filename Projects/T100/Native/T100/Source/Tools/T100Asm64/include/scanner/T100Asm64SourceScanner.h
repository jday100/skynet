#ifndef T100ASM64SOURCESCANNER_H
#define T100ASM64SOURCESCANNER_H

#include "T100Scanner.h"
#include "T100Asm64FunctionToken.h"
#include "T100Asm64FunctionScanner.h"
#include "T100Asm64SourceToken.h"


class T100Asm64SourceScanner : public T100Scanner
{
    public:
        T100Asm64SourceScanner();
        virtual ~T100Asm64SourceScanner();

        T100VOID            setSource(T100Scanner*);
        T100Scanner*        getSource();

        T100BOOL            next(T100Token&);

    protected:
        T100Asm64SourceToken*       m_token         = T100NULL;
        T100Asm64FunctionToken      m_item;

        T100BOOL            append();
        T100BOOL            classify();

    private:
        T100Asm64FunctionScanner*   m_scanner       = T100NULL;
};

#endif // T100ASM64SOURCESCANNER_H
