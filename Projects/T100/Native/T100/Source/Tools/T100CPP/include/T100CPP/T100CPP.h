#ifndef T100CPP_H
#define T100CPP_H

#include "T100Common.h"
#include "T100WString.h"

class T100CPP
{
    public:
        T100CPP();
        virtual ~T100CPP();

        T100BOOL            compile(T100WString);

        T100BOOL            decompile(T100WString);

    protected:

    private:
};

#endif // T100CPP_H
