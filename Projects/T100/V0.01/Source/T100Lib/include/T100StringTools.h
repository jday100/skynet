#ifndef T100STRINGTOOLS_H
#define T100STRINGTOOLS_H

#include "T100Common.h"


class T100StringTools
{
    public:
        T100StringTools();
        virtual ~T100StringTools();

        static T100BOOL         code_convert(T100STDSTRING, T100STDSTRING, T100STDCHAR*, size_t, T100STDCHAR*, size_t);

        static T100LONG         to_long(T100WSTRING);

        static T100FLOAT        to_float(T100WSTRING);

    protected:

    private:
};

#endif // T100STRINGTOOLS_H
