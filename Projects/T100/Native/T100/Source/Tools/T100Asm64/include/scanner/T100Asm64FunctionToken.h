#ifndef T100ASM64FUNCTIONTOKEN_H
#define T100ASM64FUNCTIONTOKEN_H

#include "T100Token.h"
#include "T100SentenceBase.h"


class T100Asm64FunctionToken : public T100Token
{
    public:
        T100Asm64FunctionToken();
        virtual ~T100Asm64FunctionToken();

        T100STRING                          name;
        T100ASM64_SENTENCE_VECTOR           value;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100ASM64FUNCTIONTOKEN_H
