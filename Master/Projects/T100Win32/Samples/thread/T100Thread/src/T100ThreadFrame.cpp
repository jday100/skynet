#include "T100ThreadFrame.h"

T100ThreadFrame::T100ThreadFrame() :
    T100Frame()
{
    //ctor
}

T100ThreadFrame::~T100ThreadFrame()
{
    //dtor
}

T100VOID T100ThreadFrame::Create(T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(label, width, height);

    init();
}

T100VOID T100ThreadFrame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       runMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_RUN, L"Run");

    T100MenuItem*       quitMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBarPtr(menuBarPtr);

    Connect(T100EVENT_COMMAND, T100MENU_ID_RUN, (T100EVENT_CALL)&T100ThreadFrame::OnMenuRun);

    Connect(T100EVENT_COMMAND, T100MENU_ID_QUIT, (T100EVENT_CALL)&T100ThreadFrame::OnMenuQuit);
}

T100VOID T100ThreadFrame::uninit()
{

}

T100VOID T100ThreadFrame::OnMenuRun(T100CommandEvent& event)
{

}

T100VOID T100ThreadFrame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}
