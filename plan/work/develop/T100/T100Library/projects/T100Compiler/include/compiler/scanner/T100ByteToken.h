#ifndef T100BYTETOKEN_H
#define T100BYTETOKEN_H

#include "compiler/base/T100LeafToken.h"

namespace T100LIBRARY{

class T100ByteToken : public T100LeafToken
{
    public:
        T100ByteToken();
        virtual ~T100ByteToken();

        T100BYTE            Value       = 0;

    protected:

    private:
};

}

#endif // T100BYTETOKEN_H
