#ifndef T100CHARTOKEN_H
#define T100CHARTOKEN_H

#include "compiler/base/T100LeafToken.h"

namespace T100LIBRARY{

class T100CharToken : public T100LeafToken
{
    public:
        T100CharToken();
        virtual ~T100CharToken();

        T100WCHAR           Value       = 0;

    protected:

    private:
};

}

#endif // T100CHARTOKEN_H
