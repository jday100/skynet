#ifndef T100LEAFTOKEN_H
#define T100LEAFTOKEN_H

#include "base/T100Token.h"

namespace T100LIBRARY{

class T100LeafToken : public T100Token
{
    public:
        T100LeafToken();
        virtual ~T100LeafToken();

        T100UINT            Type        = 0;

    protected:

    private:
};

}

#endif // T100LEAFTOKEN_H
