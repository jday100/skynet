#ifndef T100TESTTOOLS_H
#define T100TESTTOOLS_H

#include "T100File.h"


class T100TestTools
{
    public:
        T100TestTools();
        virtual ~T100TestTools();

        static T100BOOL         CleanAndCreate(T100File&);

    protected:

    private:
};

#endif // T100TESTTOOLS_H
