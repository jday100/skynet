#ifndef T100CLTEST_H
#define T100CLTEST_H

#include "T100Common.h"
#include "T100CLParser.h"
#include "T100CLAnalyzer.h"
#include "T100CLGenerator.h"

#include "T100CLCompiler.h"

class T100CLTest
{
    public:
        T100CLTest();
        virtual ~T100CLTest();

        T100BOOL            test();

    protected:

    private:
};

#endif // T100CLTEST_H
