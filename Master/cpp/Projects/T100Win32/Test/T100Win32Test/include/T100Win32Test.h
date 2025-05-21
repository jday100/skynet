#ifndef T100WIN32TEST_H
#define T100WIN32TEST_H

#include <windows.h>
#include "test/T100TestNode.h"
#include "T100Win32AppTest.h"

class T100Win32Test : public T100TestNode
{
    public:
        T100Win32Test(HINSTANCE, HINSTANCE, LPSTR, T100INT);
        virtual ~T100Win32Test();

        HINSTANCE                   m_hThisInstance;
        HINSTANCE                   m_hPrevInstance;
        LPSTR                       m_lpCmdLine;
        T100INT                     m_nCmdShow;

    protected:
        T100Win32AppTest            test_app;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100WIN32TEST_H
