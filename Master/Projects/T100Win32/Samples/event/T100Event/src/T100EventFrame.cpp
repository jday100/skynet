#include "T100EventFrame.h"

#include "gui/dialog/T100MessageBox.h"

T100EventFrame::T100EventFrame() :
    T100Frame()
{
    //ctor
}

T100EventFrame::~T100EventFrame()
{
    //dtor
}

T100VOID T100EventFrame::Create(T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(label, width, height);
    Connect(T100EVENT_WINDOW_CREATE, (T100EVENT_CALL)&OnFrameCreate);

    init();
}

T100VOID T100EventFrame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       runMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_RUN, L"Run");

    T100MenuItem*       quitMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBarPtr(menuBarPtr);

    Connect(T100EVENT_MENU, T100MENU_ID_RUN, (T100EVENT_CALL)&T100EventFrame::OnMenuRun);
    Connect(T100EVENT_MENU, T100MENU_ID_QUIT, (T100EVENT_CALL)&T100EventFrame::OnMenuQuit);

    Connect(T100EVENT_WINDOW_DESTROY, (T100EVENT_CALL)&OnFrameDestroy);

    Connect(T100EVENT_WINDOW_CLOSE, (T100EVENT_CALL)&OnFrameClose);

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_CALL)&OnFrameResize);
}

T100VOID T100EventFrame::uninit()
{

}

T100VOID T100EventFrame::OnMenuRun(T100CommandEvent& event)
{
    ShowMessageBox(this, L"Run", L"MessageBox");
}

T100VOID T100EventFrame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}

T100VOID T100EventFrame::OnFrameCreate(T100WindowEvent& event)
{
    ShowMessageBox(this, L"WindowCreateEvent");
}

T100VOID T100EventFrame::OnFrameDestroy(T100WindowEvent& event)
{
    ShowMessageBox(this, L"WindowDestroyEvent");
}

T100VOID T100EventFrame::OnFrameClose(T100WindowEvent& event)
{
    ShowMessageBox(this, L"WindowCloseEvent");
}

T100VOID T100EventFrame::OnFrameResize(T100WindowEvent& event)
{
    ShowMessageBox(this, L"WindowResizeEvent");
}

