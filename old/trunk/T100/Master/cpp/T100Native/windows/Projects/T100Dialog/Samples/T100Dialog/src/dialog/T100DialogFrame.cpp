#include "T100DialogFrame.h"

#include "gui/T100ModalDialog.h"

using namespace T100DIALOG;

T100DialogFrame::T100DialogFrame() :
    T100Frame()
{
    //ctor
}

T100DialogFrame::~T100DialogFrame()
{
    //dtor
}

T100VOID T100DialogFrame::init()
{
    T100MenuBar*        menuBar         = T100NEW T100MenuBar();
    T100Menu*           fileMenu        = T100NEW T100Menu(menuBar, L"File");
    T100MenuItem*       dialogItem      = T100NEW T100MenuItem(fileMenu, 1, L"Dialog");

    ConnectMenu(1, (T100EVENT_FUNCTION)&OnDialog);

    SetMenuBar(menuBar);
}

T100VOID T100DialogFrame::uninit()
{

}

T100VOID T100DialogFrame::Create(T100Win32Application* application, T100FrameStyle* style)
{
    T100Frame::Create(application, style);

    init();
}

T100VOID T100DialogFrame::OnDialog(T100MenuEvent& event)
{
    T100ModalDialog         dialog;

    dialog.Create(this);
    dialog.Show();
}
