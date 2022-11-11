#ifndef T100CHARTOKEN_H
#define T100CHARTOKEN_H

#include "T100Token.h"

namespace T100Assembly{

class T100CharToken : public T100Token
{
    public:
        T100CharToken();
        virtual ~T100CharToken();

        T100CHAR            value           = 0;

        T100VOID            clear();

    protected:

    private:
};

}

#endif // T100CHARTOKEN_H
