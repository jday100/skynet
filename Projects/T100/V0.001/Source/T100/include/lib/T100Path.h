#ifndef T100PATH_H
#define T100PATH_H

#include "T100Common.h"


class T100Path
{
    public:
        T100Path();
        virtual ~T100Path();

        static T100STDSTRING            getCwd();
        static T100BOOL                 format(T100STDSTRING, T100STDSTRING&, T100STDSTRING&);
        static T100BOOL                 full(T100STDSTRING, T100STDSTRING&);
        static T100BOOL                 split(T100STDSTRING, T100STDSTRING&, T100STDSTRING&);
        static T100BOOL                 chdir(T100STDSTRING);

    protected:

    private:
};

#endif // T100PATH_H
