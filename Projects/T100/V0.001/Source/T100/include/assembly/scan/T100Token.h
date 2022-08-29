#ifndef T100TOKEN_H
#define T100TOKEN_H

#include "T100Common.h"
#include "IToken.h"


class T100Token : public IToken
{
    public:
        T100Token();
        virtual ~T100Token();

        virtual T100VOID        clear();
        virtual T100STDSTRING   tostring();

    protected:

    private:
};

#endif // T100TOKEN_H
