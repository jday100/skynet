#ifndef T100TESTTOOLS_H
#define T100TESTTOOLS_H

#include "T100Common.h"
#include "T100StringTypes.h"
#include "T100File.h"

namespace T100Library{

class T100TestTools
{
    public:
        T100TestTools();
        virtual ~T100TestTools();

        static T100BOOL         Exists(T100WSTRING);

        static T100BOOL         Remove(T100WSTRING);

        static T100BOOL         CleanAndCreate(T100File&);

        static T100BOOL         Print(T100WORD_VECTOR&);

        static T100STDSTRING    Hex(T100WORD&);

        static T100BOOL         Print(T100WSTRING);

        static T100BOOL         Print(void*);

    protected:

    private:
};

}

#endif // T100TESTTOOLS_H
