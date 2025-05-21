#include "T100EventFrame.h"

#include "gui/T100FillLayout.h"
#include "gui/T100Button.h"
#include "gui/T100MessageBox.h"
#include "gui/T100FileDialog.h"

#include "gui/T100FontDialog.h"


T100EventFrame::T100EventFrame() :
    T100Frame()
{
    //ctor
    init();
}

T100EventFrame::~T100EventFrame()
{
    //dtor
    uninit();
}

T100VOID T100EventFrame::init()
{
    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnFrameResize);
    ConnectMenu(10001, (T100EVENT_FUNCTION)&OnMenuOpen);
    ConnectMenu(10002, (T100EVENT_FUNCTION)&OnMenuQuit);
}

T100VOID T100EventFrame::uninit()
{

}

T100VOID T100EventFrame::Create(T100Win32Application* app, T100FrameStyle* style)
{
    T100Frame::Create(app, style);
    CreateMenu();
    CreatePanel();
}

T100VOID T100EventFrame::OnFrameResize(T100WindowEvent& event)
{

}

T100VOID T100EventFrame::CreateMenu()
{
    T100MenuBar*        menuBar         = T100NEW T100MenuBar();
    T100Menu*           fileMenu        = T100NEW T100Menu(menuBar, L"File");
    T100MenuItem*       newItem         = T100NEW T100MenuItem(fileMenu, 10000, L"New");
    T100MenuItem*       openItem        = T100NEW T100MenuItem(fileMenu, 10001, L"Open");
    T100MenuItem*       quitItem        = T100NEW T100MenuItem(fileMenu, 10002, L"Quit");

    SetMenuBar(menuBar);
}

T100VOID T100EventFrame::OnMenuNew(T100MenuEvent& event)
{
    T100FontDialog      dialog(this);
}

T100VOID T100EventFrame::OnMenuOpen(T100MenuEvent& event)
{
    T100FileDialog      dialog;

}

T100VOID T100EventFrame::OnMenuQuit(T100MenuEvent& event)
{
    PostQuitMessage(0);
}

T100VOID T100EventFrame::CreatePanel()
{
    T100Panel*  panel1   = T100NEW T100Panel(this);
    T100Panel*  panel2   = T100NEW T100Panel(this);
    T100Panel*  panel3   = T100NEW T100Panel(this);

    panel1->Show();
    panel2->Show();
    panel3->Show();

    T100Button*     button  = T100NEW T100Button(panel1, L"OK");

    button->Show();

    T100FillLayout*     layout      = T100NEW T100FillLayout;

    SetLayout(layout);

    button->Connect(T100EVENT_COMMAND, (T100EVENT_FUNCTION)&OnButtonClick, this);
}

T100VOID T100EventFrame::OnButtonClick(T100WindowEvent& event)
{
    if(ShowMessageBox(this, L"Quit?") == T100YES){
        PostQuitMessage(0);
    }
}
