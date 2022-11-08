#ifndef T100CONSOLESTRINGTOKEN_H
#define T100CONSOLESTRINGTOKEN_H

#include "T100Token.h"

namespace T100Library{

class T100ConsoleStringToken : public T100Component::T100Token
{
    public:
        T100ConsoleStringToken();
        virtual ~T100ConsoleStringToken();

        T100WSTRING         value;

        T100VOID            clear();

    protected:

    private:
};

}

#endif // T100CONSOLESTRINGTOKEN_H
