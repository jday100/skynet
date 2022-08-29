#ifndef T100TOKEN_H
#define T100TOKEN_H

#include "T100Common.h"
#include "T100String.h"


#define     T100TOKEN_TYPE              T100WORD
#define     T100TOKEN_NONE              0

#define     T100ERROR_TYPE              T100WORD
#define     T100ERROR_NONE              0


class T100Token
{
    public:
        T100Token();
        virtual ~T100Token();

        T100TOKEN_TYPE          type        = T100TOKEN_NONE;
        T100BOOL                eof         = T100FALSE;
        T100ERROR_TYPE          err         = T100ERROR_NONE;
        T100WORD                row         = 0;

        virtual T100VOID        clear();

    protected:

    private:
};

#endif // T100TOKEN_H
