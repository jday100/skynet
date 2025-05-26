#include "T100MenuFrame.h"

#include "gui/T100MessageBox.h"

T100MenuFrame::T100MenuFrame() :
    T100Frame()
{
    //ctor
}

T100MenuFrame::~T100MenuFrame()
{
    //dtor
}

T100VOID T100MenuFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    init();
}

T100VOID T100MenuFrame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       runMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_RUN, L"Run");

    T100MenuItem*       quitMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBar(menuBarPtr);

    ConnectMenu(T100MENU_ID_RUN, (T100EVENT_FUNCTION)&T100MenuFrame::OnMenuRun);

    ConnectMenu(T100MENU_ID_QUIT, (T100EVENT_FUNCTION)&T100MenuFrame::OnMenuQuit);
}

T100VOID T100MenuFrame::uninit()
{

}

T100VOID T100MenuFrame::OnMenuRun(T100CommandEvent& event)
{
    ShowMessageBox(this, L"Run");
}

T100VOID T100MenuFrame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}
