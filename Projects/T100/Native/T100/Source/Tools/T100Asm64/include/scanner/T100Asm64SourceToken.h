#ifndef T100ASM64SOURCETOKEN_H
#define T100ASM64SOURCETOKEN_H

#include "T100Token.h"
#include "T100SentenceBase.h"


class T100Asm64SourceToken : public T100Token
{
    public:
        T100Asm64SourceToken();
        virtual ~T100Asm64SourceToken();

        T100STRING                      name;
        T100ASM64_SENTENCE_VECTOR       value;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100ASM64SOURCETOKEN_H
