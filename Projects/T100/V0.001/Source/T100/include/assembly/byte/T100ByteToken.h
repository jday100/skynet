#ifndef T100BYTETOKEN_H
#define T100BYTETOKEN_H

#include "T100Token.h"


class T100ByteToken : public T100Token
{
    public:
        T100ByteToken();
        virtual ~T100ByteToken();

        T100BYTE        data        = 0;

        T100VOID        clear();

    protected:

    private:
};

#endif // T100BYTETOKEN_H
