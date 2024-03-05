#ifndef T100ASM64SENTENCETOKEN_H
#define T100ASM64SENTENCETOKEN_H

#include "T100Token.h"
#include "T100SentenceBase.h"


class T100Asm64SentenceToken : public T100Token
{
    public:
        T100Asm64SentenceToken();
        virtual ~T100Asm64SentenceToken();

        T100SentenceBase*       value           = T100NULL;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100ASM64SENTENCETOKEN_H
