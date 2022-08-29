#ifndef T100TESTHELP_H
#define T100TESTHELP_H

#include "T100Test.h"


class T100TestHelp : public T100Test
{
    public:
        T100TestHelp();
        virtual ~T100TestHelp();

        T100BOOL                    test_all();

    protected:

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100TESTHELP_H
