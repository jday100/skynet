#ifndef T100TYPETOOLS_H
#define T100TYPETOOLS_H

#include "T100Common.h"

class T100TypeTools
{
    public:
        T100TypeTools();
        virtual ~T100TypeTools();

        static T100STRING           to_string(T100UINT64);

    protected:

    private:
};

#endif // T100TYPETOOLS_H
