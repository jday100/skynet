#ifndef T100CLFILETOKEN_H
#define T100CLFILETOKEN_H

#include "state/T100Token.h"

class T100CLFileToken : public T100Token
{
    public:
        T100CLFileToken();
        virtual ~T100CLFileToken();

        T100WChar       value[1024];
        T100WORD        length          = 1024;

    protected:

    private:
};

#endif // T100CLFILETOKEN_H
