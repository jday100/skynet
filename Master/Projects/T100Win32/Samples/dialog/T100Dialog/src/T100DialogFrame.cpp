#include "T100DialogFrame.h"

#include "gui/dialog/T100MessageBox.h"

T100DialogFrame::T100DialogFrame() :
    T100Frame()
{
    //ctor
}

T100DialogFrame::~T100DialogFrame()
{
    //dtor
}

T100VOID T100DialogFrame::Create(T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(label, width, height);

    init();
}

T100VOID T100DialogFrame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       runMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_RUN, L"Run");

    T100MenuItem*       quitMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBarPtr(menuBarPtr);

    Connect(T100EVENT_MENU, T100MENU_ID_RUN, (T100EVENT_CALL)&T100DialogFrame::OnMenuRun);

    Connect(T100EVENT_MENU, T100MENU_ID_QUIT, (T100EVENT_CALL)&T100DialogFrame::OnMenuQuit);
}

T100VOID T100DialogFrame::uninit()
{

}

T100VOID T100DialogFrame::OnMenuRun(T100CommandEvent& event)
{
    T100INT result  = ShowMessageBox(this, L"Hello, world!", L"MessageBox");

    if(result == T100YES){
        ShowMessageBox(this, L"YES", L"Result");
    }else{
        ShowMessageBox(this, L"NO", L"Result");
    }
}

T100VOID T100DialogFrame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}
