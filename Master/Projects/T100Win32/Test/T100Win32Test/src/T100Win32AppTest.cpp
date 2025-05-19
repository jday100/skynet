#include "T100Win32AppTest.h"

#include "T100Win32Test.h"
#include "thread/T100Thread.h"
#include "win32/T100Win32Capture.h"
#include "gui/T100Win32Application.h"

T100Win32AppTest::T100Win32AppTest(T100TestNode* parent) :
    T100TestNode(L"App", parent),
    test_menu(this)
{
    //ctor
}

T100Win32AppTest::~T100Win32AppTest()
{
    //dtor
}

T100RESULT T100Win32AppTest::DoTest()
{
    T100Thread      appThread(&AppThread, this);
    T100Thread      testThread(&TestThread, this);

    appThread.Waiting();
    testThread.Waiting();

    return m_result;
}

T100VOID T100Win32AppTest::AppThread()
{
    T100Win32Application        app;

    T100Win32Test*      test    = dynamic_cast<T100Win32Test*>(GetRootPtr());

    T100Runner(app, test->m_hThisInstance, test->m_hPrevInstance, test->m_lpCmdLine, test->m_nCmdShow);
}

T100VOID T100Win32AppTest::TestThread()
{
    T100Win32Capture            capture;

    T100Thread::Sleep(100);

    HWND        hwnd            = capture.Find(L"T100Frame");

    if(hwnd){
        //CloseWindow(hwnd);
        PostQuitMessage(0);
        SendMessage(hwnd, WM_DESTROY, 0, 0);

        m_result    = T100RESULT_SUCCESS;
    }else{
        m_result    = T100RESULT_FAILURE;
    }
}
