#ifndef T100SCANNER_H
#define T100SCANNER_H

#include "T100State.h"
#include "T100Token.h"

class T100Scanner
{
    public:
        T100Scanner();
        virtual ~T100Scanner();

        virtual T100BOOL            next(T100State&, T100Token&) = 0;

    protected:

    private:
};

#endif // T100SCANNER_H
