#ifndef T100ASM64LETTERTOKEN_H
#define T100ASM64LETTERTOKEN_H

#include "T100Token.h"


class T100Asm64LetterToken : public T100Token
{
    public:
        T100Asm64LetterToken();
        virtual ~T100Asm64LetterToken();

        T100WCHAR           value;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100ASM64LETTERTOKEN_H
