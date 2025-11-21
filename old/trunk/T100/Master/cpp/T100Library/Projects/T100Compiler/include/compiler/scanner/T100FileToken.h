#ifndef T100FILETOKEN_H
#define T100FILETOKEN_H

#include "compiler/base/T100LeafToken.h"

namespace T100LIBRARY{

class T100FileToken : public T100LeafToken
{
    public:
        T100FileToken();
        virtual ~T100FileToken();

        T100BYTE*           Data        = T100NULL;
        T100INT             Length      = -1;

    protected:

    private:
};

}

#endif // T100FILETOKEN_H
