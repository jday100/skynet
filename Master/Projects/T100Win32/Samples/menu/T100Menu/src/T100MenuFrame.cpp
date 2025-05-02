#include "T100MenuFrame.h"

T100MenuFrame::T100MenuFrame() :
    T100Frame()
{
    //ctor
}

T100MenuFrame::~T100MenuFrame()
{
    //dtor
}

T100VOID T100MenuFrame::Create(T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(label, width, height);

    init();
}

T100VOID T100MenuFrame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       runMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_RUN, L"Run");

    T100MenuItem*       quitMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBarPtr(menuBarPtr);

    Connect(T100EVENT_MENU, T100MENU_ID_RUN, (T100EVENT_CALL)&T100MenuFrame::OnMenuRun);

    Connect(T100EVENT_MENU, T100MENU_ID_QUIT, (T100EVENT_CALL)&T100MenuFrame::OnMenuQuit);
}

T100VOID T100MenuFrame::uninit()
{

}

T100VOID T100MenuFrame::OnMenuRun(T100CommandEvent& event)
{

}

T100VOID T100MenuFrame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}
