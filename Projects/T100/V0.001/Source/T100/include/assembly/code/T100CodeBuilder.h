#ifndef T100CODEBUILDER_H
#define T100CODEBUILDER_H


#include "T100CodeNew.h"


class T100CodeBuilder
{
    public:
        T100CodeBuilder();
        virtual ~T100CodeBuilder();

        virtual T100BOOL            save(T100STDSTRING, T100Code*)=0;

    protected:

    private:
};

#endif // T100CODEBUILDER_H
