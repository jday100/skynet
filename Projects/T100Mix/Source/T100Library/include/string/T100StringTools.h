#ifndef T100STRINGTOOLS_H
#define T100STRINGTOOLS_H

#include "T100StringTypes.h"


class T100StringTools
{
    public:
        T100StringTools();
        virtual ~T100StringTools();

        static T100BOOL                     code_convert(T100STDSTRING, T100STDSTRING, T100STDCHAR*, size_t, T100STDCHAR*, size_t);


        static T100STDSTRING                utf8_to_gbk(T100STDSTRING&);
        static T100STDSTRING                gbk_to_utf8(T100STDSTRING&);


    protected:

    private:
};

#endif // T100STRINGTOOLS_H
