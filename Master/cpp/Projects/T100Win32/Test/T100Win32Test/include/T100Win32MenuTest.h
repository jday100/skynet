#ifndef T100WIN32MENUTEST_H
#define T100WIN32MENUTEST_H

#include "test/T100TestNode.h"

class T100Win32MenuTest : public T100TestNode
{
    public:
        T100Win32MenuTest(T100TestNode*);
        virtual ~T100Win32MenuTest();

        T100RESULT                  DoTest();

    protected:
        T100VOID                    AppThread();
        T100VOID                    TestThread();
        T100VOID                    ClickThread();
        T100VOID                    MsgBoxThread();

        T100RESULT                  test_menu();
        T100RESULT                  test_click();

    private:
        T100RESULT                  m_result;
};

#endif // T100WIN32MENUTEST_H
