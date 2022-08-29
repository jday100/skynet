#ifndef T100TESTTHREAD_H
#define T100TESTTHREAD_H

#include "T100Test.h"


class T100TestThread : public T100Test
{
    public:
        T100TestThread();
        virtual ~T100TestThread();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100BOOL                    test_thread();

        T100BOOL                    test_unit();

    private:
        static T100STDSTRING        m_unit;

        T100BOOL                    test_run();
};

#endif // T100TESTTHREAD_H
