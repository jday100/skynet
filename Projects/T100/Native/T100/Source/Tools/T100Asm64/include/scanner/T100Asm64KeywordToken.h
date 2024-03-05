#ifndef T100ASM64KEYWORDTOKEN_H
#define T100ASM64KEYWORDTOKEN_H

#include "T100Token.h"


class T100Asm64KeywordToken : public T100Token
{
    public:
        T100Asm64KeywordToken();
        virtual ~T100Asm64KeywordToken();

        T100STRING          value;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100ASM64KEYWORDTOKEN_H
