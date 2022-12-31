#ifndef T100TRANSDUCERTEST_H
#define T100TRANSDUCERTEST_H

#include "T100Test.h"

namespace T100Library{

class T100TransducerTest : public T100Test
{
    public:
        T100TransducerTest(T100Test*);
        virtual ~T100TransducerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_trans();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100TRANSDUCERTEST_H
