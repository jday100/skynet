#ifndef ISCAN_H
#define ISCAN_H

#include "T100Common.h"
#include "IToken.h"


class IScan
{
    public:
        IScan();
        virtual ~IScan();

        virtual T100BOOL    next(IToken&)=0;

        virtual T100BOOL    open(T100String&)=0;
        virtual T100BOOL    close()=0;

    protected:

    private:
};

#endif // ISCAN_H
