#ifndef T100STRINGTOKEN_H
#define T100STRINGTOKEN_H

#include "T100Token.h"


class T100StringToken : public T100Token
{
    public:
        T100StringToken();
        virtual ~T100StringToken();

        T100String          data;
        T100BYTE_VECTOR     bytes;

        T100VOID            clear();

    protected:

    private:
};

#endif // T100STRINGTOKEN_H
