#ifndef T100BYTETOKEN_H
#define T100BYTETOKEN_H

#include "T100Token.h"

namespace T100Assembly{

class T100ByteToken : public T100Component::T100Token
{
    public:
        T100ByteToken();
        virtual ~T100ByteToken();

        T100VOID            clear();

    protected:

    private:
};

}

#endif // T100BYTETOKEN_H
