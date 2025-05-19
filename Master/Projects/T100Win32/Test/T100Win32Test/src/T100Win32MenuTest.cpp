#include "T100Win32MenuTest.h"

#include "T100Win32Test.h"
#include "thread/T100Thread.h"
#include "win32/T100Win32Capture.h"
#include "gui/T100Win32Application.h"

T100Win32MenuTest::T100Win32MenuTest(T100TestNode* parent) :
    T100TestNode(L"menu", parent)
{
    //ctor
}

T100Win32MenuTest::~T100Win32MenuTest()
{
    //dtor
}

T100RESULT T100Win32MenuTest::DoTest()
{
    T100RESULT      result;
    T100RESULT      value;

    result  = test_menu();

    value   = test_click();

    if(value == T100RESULT_SUCCESS){

    }else{
        result  = value;
    }
}

T100RESULT T100Win32MenuTest::test_menu()
{
    T100Thread      appThread(&AppThread, this);
    T100Thread      testThread(&TestThread, this);

    appThread.Waiting();
    testThread.Waiting();

    return m_result;
}

T100VOID T100Win32MenuTest::AppThread()
{
    T100Win32Capture        capture;

    capture.Launch(L"..\\..\\Samples\\menu\\T100Menu\\bin\\Debug\\T100Menu.exe");
}

T100VOID T100Win32MenuTest::TestThread()
{
    T100Win32Capture            capture;

    T100Thread::Sleep(500);

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

T100RESULT T100Win32MenuTest::test_click()
{
    T100Thread      appThread(&AppThread, this);
    T100Thread      clickThread(&ClickThread, this);

    appThread.Waiting();
    clickThread.Waiting();

    return m_result;
}

T100VOID T100Win32MenuTest::ClickThread()
{
    T100Win32Capture            capture;

    T100Thread::Sleep(500);

    HWND        hwnd            = capture.Find(L"T100Frame");

    if(hwnd){
        HMENU   menu        = GetMenu(hwnd);
        HMENU   fileMenu    = GetSubMenu(menu, 0);

        UINT    id          = GetMenuItemID(fileMenu, 0);

        T100Thread      msgboxThread(&MsgBoxThread, this);

        SendMessage(hwnd, WM_COMMAND, id, 0);

        msgboxThread.Waiting();

        //CloseWindow(hwnd);
        PostQuitMessage(0);
        SendMessage(hwnd, WM_DESTROY, 0, 0);

        m_result    = T100RESULT_SUCCESS;
    }else{
        m_result    = T100RESULT_FAILURE;
    }
}

T100VOID T100Win32MenuTest::MsgBoxThread()
{
    T100Win32Capture            capture;

    T100Thread::Sleep(500);

    HWND        hwnd            = capture.Find(L"MessageBox");

    if(hwnd){
        HWND    button          = FindWindowEx(hwnd, NULL, L"button", NULL);

        SendMessage(button, WM_LBUTTONDOWN, 0, 0);
        SendMessage(button, WM_LBUTTONUP, 0, 0);

        m_result    = T100RESULT_SUCCESS;
    }else{
        m_result    = T100RESULT_FAILURE;
    }
}
