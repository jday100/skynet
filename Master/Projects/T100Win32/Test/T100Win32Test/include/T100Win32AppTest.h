#ifndef T100WIN32APPTEST_H
#define T100WIN32APPTEST_H

#include "test/T100TestNode.h"
#include "T100Win32MenuTest.h"

class T100Win32AppTest : public T100TestNode
{
    public:
        T100Win32AppTest(T100TestNode*);
        virtual ~T100Win32AppTest();

        T100RESULT              DoTest();

    protected:
        T100Win32MenuTest       test_menu;


        T100VOID                AppThread();
        T100VOID                TestThread();

    private:
        T100RESULT              m_result;
};

#endif // T100WIN32APPTEST_H
