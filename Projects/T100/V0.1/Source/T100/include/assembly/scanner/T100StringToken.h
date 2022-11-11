#ifndef T100STRINGTOKEN_H
#define T100STRINGTOKEN_H

#include "T100Token.h"

namespace T100Assemby{

class T100StringToken : public T100Token
{
    public:
        T100StringToken();
        virtual ~T100StringToken();

        T100STRING          value;

        T100VOID            clear();

    protected:

    private:
};

}

#endif // T100STRINGTOKEN_H
