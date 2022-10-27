#ifndef T100LIBRARYTEST_H
#define T100LIBRARYTEST_H

#include "T100Test.h"
#include "T100StringTest.h"
#include "T100LogTest.h"


namespace T100Library{

class T100LibraryTest : public T100Test
{
    public:
        T100LibraryTest();
        virtual ~T100LibraryTest();

    protected:
        T100StringTest          test_string;
        T100LogTest             test_log;

    private:
};

}

#endif // T100LIBRARYTEST_H
