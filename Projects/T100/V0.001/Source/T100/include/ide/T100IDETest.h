#ifndef T100IDETEST_H
#define T100IDETEST_H

#include "T100Test.h"


class T100IDETest : public T100Test
{
    public:
        T100IDETest();
        virtual ~T100IDETest();

    protected:

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100IDETEST_H
