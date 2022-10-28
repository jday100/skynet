#ifndef T100THISAPPTEST_H
#define T100THISAPPTEST_H

#include "T100Test.h"
#include "T100LibraryTest.h"
#include "T100AssemblyTest.h"


namespace T100ThisAppTest{

class T100ThisAppTest : public T100Library::T100Test
{
    public:
        T100ThisAppTest();
        virtual ~T100ThisAppTest();

    protected:
        T100Library::T100LibraryTest            test_library;
        T100Assembly::T100AssemblyTest          test_assembly;

    private:
};

}

#endif // T100THISAPPTEST_H
