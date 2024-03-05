#ifndef T100TOKEN_H
#define T100TOKEN_H

#include "T100Common.h"
#include "T100Asm64Common.h"


class T100Token
{
    public:
        T100Token();
        virtual ~T100Token();

        T100ASM64_TOKEN_TYPE            type            = T100TOKEN_NONE;

    protected:
        T100VOID            clear();

    private:
};

#endif // T100TOKEN_H
