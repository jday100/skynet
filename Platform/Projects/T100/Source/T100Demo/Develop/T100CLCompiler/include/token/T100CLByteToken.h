#ifndef T100CLBYTETOKEN_H
#define T100CLBYTETOKEN_H

#include "state/T100Token.h"

class T100CLByteToken : public T100Token
{
    public:
        T100CLByteToken();
        virtual ~T100CLByteToken();

        T100BYTE            value;

    protected:

    private:
};

#endif // T100CLBYTETOKEN_H
