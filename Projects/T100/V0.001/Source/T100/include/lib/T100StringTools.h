#ifndef T100STRINGTOOLS_H
#define T100STRINGTOOLS_H

#include "T100Common.h"


class T100StringTools
{
    public:
        T100StringTools();
        virtual ~T100StringTools();

        static T100String       format(T100String);

        static T100BOOL         copy(T100WORD*, T100WORD*, T100WORD);
        static T100String       to_string(T100WORD*, T100WORD);

        static T100BOOL         compare(T100WORD*, T100WORD, T100String);

        static T100BOOL         split(T100STDSTRING&, T100STDSTRING, T100STDSTRING_VECTOR&);

        static T100BOOL         code_convert(T100STDSTRING, T100STDSTRING, T100STDCHAR*, size_t, T100STDCHAR*, size_t);

        static T100STDSTRING    to_string(T100DWORD);

    protected:

    private:
};

#endif // T100STRINGTOOLS_H
