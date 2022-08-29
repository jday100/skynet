#ifndef T100PATHTOOLS_H
#define T100PATHTOOLS_H

#include "T100Common.h"


class T100PathTools
{
    public:
        T100PathTools();
        virtual ~T100PathTools();

        static T100WSTRING              getCwd();
        static T100BOOL                 format(T100WSTRING, T100WSTRING&, T100WSTRING&);
        static T100BOOL                 full(T100WSTRING, T100WSTRING&);
        static T100BOOL                 split(T100WSTRING, T100WSTRING&, T100WSTRING&);
        static T100BOOL                 chdir(T100WSTRING);

    protected:

    private:
};

#endif // T100PATHTOOLS_H
