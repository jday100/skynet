#ifndef T100STRINGTOOLS_H
#define T100STRINGTOOLS_H

#include "T100Common.h"
#include "T100StringCommon.h"
#include "T100StringTypes.h"
#include "T100DataStructure.h"


namespace T100Library{

class T100StringTools
{
    public:
        T100StringTools();
        virtual ~T100StringTools();

        static T100BOOL                     startsWith(T100WSTRING, T100WSTRING);

        static T100BOOL                     endsWith(T100WSTRING, T100WSTRING);

        static T100BOOL                     split(T100WSTRING, T100WSTRING, T100WSTRING_VECTOR&);

        static T100BOOL                     code_convert(T100STDSTRING, T100STDSTRING, T100STDCHAR*, size_t, T100STDCHAR*, size_t);

        static T100LONG                     to_long(T100WSTRING);

        static T100FLOAT                    to_float(T100WSTRING);

        static T100STDSTRING                utf8_to_gbk(T100STDSTRING&);
        static T100STDSTRING                gbk_to_utf8(T100STDSTRING&);

        static T100STRING_CODED_TYPE        test(T100CHAR8*);

    protected:

    private:
};

}

#endif // T100STRINGTOOLS_H
