#ifndef T100TOKEN_H
#define T100TOKEN_H

#include "T100Error.h"
#include "T100TokenTypes.h"

#define     T100TOKEN_TYPE                      T100WORD
#define     T100TOKEN_NONE                      0

namespace T100Component{


class T100Token : public T100Library::T100Class
{
    public:
        T100Token();
        virtual ~T100Token();

        T100TOKEN_TYPE          type            = T100TOKEN_NONE;
        T100BOOL                eof             = T100FALSE;
        T100ERROR_TYPE          err             = T100ERROR_NONE;
        T100WORD                row             = 0;

        virtual T100VOID        clear();

    protected:

    private:
};

}

#endif // T100TOKEN_H
