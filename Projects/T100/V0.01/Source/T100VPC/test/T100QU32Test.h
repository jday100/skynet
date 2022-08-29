#ifndef T100QU32TEST_H
#define T100QU32TEST_H

#include "T100Test.h"


class T100QU32Test : public T100Test
{
    public:
        T100QU32Test(T100Test*);
        virtual ~T100QU32Test();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_qu32();

    private:
        static T100WSTRING          m_name;

};

#endif // T100QU32TEST_H
