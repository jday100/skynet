#ifndef T100LOGTEST_H
#define T100LOGTEST_H

#include "T100Test.h"

namespace T100Library{

class T100LogTest : public T100Library::T100Test
{
    public:
        T100LogTest(T100Test*);
        virtual ~T100LogTest();

    protected:

    private:
};

}

#endif // T100LOGTEST_H
