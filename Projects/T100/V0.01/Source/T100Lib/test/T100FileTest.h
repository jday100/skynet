#ifndef T100FILETEST_H
#define T100FILETEST_H

#include "T100Test.h"


class T100FileTest : public T100Test
{
    public:
        T100FileTest(T100Test*);
        virtual ~T100FileTest();

    protected:
        T100BOOL                        do_test();

        T100BOOL                        test_file();

    private:
        static T100WSTRING              m_name;

};

#endif // T100FILETEST_H
