#ifndef T100BUFFERTOKEN_H
#define T100BUFFERTOKEN_H

#include "compiler/base/T100LeafToken.h"

namespace T100LIBRARY{

class T100BufferToken : public T100LeafToken
{
    public:
        T100BufferToken();
        virtual ~T100BufferToken();

        T100BYTE            Value       = 0;

    protected:

    private:
};

}

#endif // T100BUFFERTOKEN_H
