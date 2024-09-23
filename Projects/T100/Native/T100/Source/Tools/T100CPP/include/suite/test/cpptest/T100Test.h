#ifndef T100TEST_H
#define T100TEST_H

#include "T100Common.h"

class T100Test
{
    public:
        T100Test();
        virtual ~T100Test();

        virtual T100BOOL            run();

    protected:

    private:
};

#endif // T100TEST_H
