#ifndef T100ASSEMBLYTEST_H
#define T100ASSEMBLYTEST_H

#include "T100Test.h"


namespace T100Assembly{

class T100AssemblyTest : public T100Library::T100Test
{
    public:
        T100AssemblyTest(T100Test*);
        virtual ~T100AssemblyTest();

    protected:

    private:
};

}

#endif // T100ASSEMBLYTEST_H
