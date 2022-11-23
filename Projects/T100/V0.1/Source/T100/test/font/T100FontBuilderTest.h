#ifndef T100FONTBUILDERTEST_H
#define T100FONTBUILDERTEST_H

#include "T100Test.h"

namespace T100Font{

class T100FontBuilderTest : public T100Library::T100Test
{
    public:
        T100FontBuilderTest(T100Test*);
        virtual ~T100FontBuilderTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_font();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100FONTBUILDERTEST_H
