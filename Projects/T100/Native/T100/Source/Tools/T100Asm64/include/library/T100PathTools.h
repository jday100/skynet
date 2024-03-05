#ifndef T100PATHTOOLS_H
#define T100PATHTOOLS_H

#include "T100Common.h"


class T100PathTools
{
    public:
        T100PathTools();
        virtual ~T100PathTools();

        static T100STRING           getCwd();
        static T100BOOL             format(T100STRING, T100STRING&, T100STRING&);
        static T100BOOL             full(T100STRING, T100STRING&);
        static T100BOOL             split(T100STRING, T100STRING&, T100STRING&);
        static T100BOOL             chdir(T100STRING);

    protected:

    private:
};

#endif // T100PATHTOOLS_H
