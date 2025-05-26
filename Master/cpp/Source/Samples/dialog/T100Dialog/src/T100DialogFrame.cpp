#include "T100DialogFrame.h"

#include "gui/T100MessageBox.h"
#include "T100TestDialog.h"

T100DialogFrame::T100DialogFrame() :
    T100Frame()
{
    //ctor
}

T100DialogFrame::~T100DialogFrame()
{
    //dtor
}

T100VOID T100DialogFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    init();
}

T100VOID T100DialogFrame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       msgMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_MSGBOX, L"MessageBox");

    T100MenuItem*       dialogMenuPtr   = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_DIALOG, L"Dialog");

    T100MenuItem*       quitMenuPtr     = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBar(menuBarPtr);

    ConnectMenu(T100MENU_ID_MSGBOX, (T100EVENT_FUNCTION)&T100DialogFrame::OnMenuMsgBox);

    ConnectMenu(T100MENU_ID_DIALOG, (T100EVENT_FUNCTION)&T100DialogFrame::OnMenuDialog);

    ConnectMenu(T100MENU_ID_QUIT, (T100EVENT_FUNCTION)&T100DialogFrame::OnMenuQuit);
}

T100VOID T100DialogFrame::uninit()
{

}

T100VOID T100DialogFrame::OnMenuMsgBox(T100CommandEvent& event)
{
    T100INT result  = ShowMessageBox(this, L"Hello, world!", L"MessageBox");

    if(result == T100YES){
        ShowMessageBox(this, L"YES", L"Result");
    }else{
        ShowMessageBox(this, L"NO", L"Result");
    }
}

T100VOID T100DialogFrame::OnMenuDialog(T100CommandEvent& event)
{
    T100TestDialog      dialog;

    dialog.Create(this);

    dialog.Show();
}

T100VOID T100DialogFrame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}
