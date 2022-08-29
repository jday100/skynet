#ifndef T100TESTLOG_H
#define T100TESTLOG_H

#include "T100Test.h"


class T100TestLog : public T100Test
{
    public:
        T100TestLog();
        virtual ~T100TestLog();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();
        T100BOOL                    test_log();

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100TESTLOG_H
