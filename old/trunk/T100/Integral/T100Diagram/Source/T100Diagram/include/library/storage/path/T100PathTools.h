#ifndef T100PATHTOOLS_H
#define T100PATHTOOLS_H

#include "T100Common.h"

class T100PathTools
{
    public:
        T100PathTools();
        virtual ~T100PathTools();

        static const T100WSTRING            GetCwd();

        static T100BOOL                     Format(const T100WSTRING&, T100WSTRING&, T100WSTRING&);
        static T100BOOL                     FullPath(const T100WSTRING&, T100WSTRING&);
        static T100BOOL                     Split(const T100WSTRING&, T100WSTRING&, T100WSTRING&);

    protected:

    private:
};

#endif // T100PATHTOOLS_H
