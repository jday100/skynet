#ifndef T100ASM64STRINGTOKEN_H
#define T100ASM64STRINGTOKEN_H

#include "T100Token.h"


class T100Asm64StringToken : public T100Token
{
    public:
        T100Asm64StringToken();
        virtual ~T100Asm64StringToken();

        T100STRING                      value;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100ASM64STRINGTOKEN_H
