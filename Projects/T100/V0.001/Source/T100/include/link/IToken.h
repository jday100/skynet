#ifndef ITOKEN_H
#define ITOKEN_H

#include "T100AsmCommon.h"
#include "T100TokenTypes.h"


class IToken
{
    public:
        IToken();
        virtual ~IToken();

        T100TOKEN_TYPE      type        = T100TOKEN_NONE;
        T100BOOL            eof         = T100FALSE;
        T100ERROR_TYPE      err         = T100ERROR_NONE;
        T100WORD            row         = 0;

        virtual T100VOID    clear()=0;

    protected:

    private:
};

#endif // ITOKEN_H
