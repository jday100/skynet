#ifndef T100FILETEST_H
#define T100FILETEST_H

#include "T100Test.h"

class T100FileTest : public T100Test
{
    public:
        T100FileTest();
        virtual ~T100FileTest();

        T100BOOL            run();

    protected:
        T100BOOL            text_test();
        T100BOOL            binary_test();

    private:
};

#endif // T100FILETEST_H
