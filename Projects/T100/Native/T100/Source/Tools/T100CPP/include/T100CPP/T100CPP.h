#ifndef T100CPP_H
#define T100CPP_H

#include "T100Common.h"

class T100CPP
{
    public:
        T100CPP();
        virtual ~T100CPP();

        T100BOOL            compile();

        T100BOOL            decompile();

    protected:

    private:
};

#endif // T100CPP_H
