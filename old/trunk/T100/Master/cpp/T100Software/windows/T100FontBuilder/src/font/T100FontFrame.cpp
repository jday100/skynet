#include "T100FontFrame.h"

#include "gui/T100MessageBox.h"
#include "font/T100FontBuilder.h"
#include "extension/T100ExtensionMenu.h"
#include "extension/T100ExtensionFrame.h"

using namespace T100UNIVERSAL;

T100FontFrame::T100FontFrame() :
    T100Frame(),
    m_server()
{
    //ctor
}

T100FontFrame::~T100FontFrame()
{
    //dtor
    uninit();
}

T100VOID T100FontFrame::Create(T100Win32Application* application, T100FrameStyle* style)
{
    T100Frame::Create(application, style);
    init();

    CloseEvent();
    QuitMenu();
}

T100VOID T100FontFrame::init()
{
    m_server.Start();

    T100ExtensionFrame*     frame       = T100NEW T100ExtensionFrame();

    frame->Bind(this);
    m_server.CreateExtension(T100FONT_BUILDER_VIEW_MAIN_FRAME, frame);

    T100MenuBar*            menuBar     = T100NEW T100MenuBar();
    T100Menu*               fileMenu    = T100NEW T100Menu(menuBar, L"File");
    T100ExtensionMenu*      menu    = T100NEW T100ExtensionMenu();

    SetMenuBar(menuBar);
    menu->Bind(fileMenu, (T100EVENT_FUNCTION)&OnMainMenu, this);

    m_server.CreateExtension(T100FONT_BUILDER_VIEW_MAIN_MENU_FILE, menu);

    m_server.Load();
}

T100VOID T100FontFrame::uninit()
{
    m_server.DestroyExtension(T100FONT_BUILDER_VIEW_MAIN_MENU_FILE);
    m_server.DestroyExtension(T100FONT_BUILDER_VIEW_MAIN_FRAME);
    m_server.Stop();
}

T100VOID T100FontFrame::OnMainMenu(T100MenuEvent& event)
{
    T100ExtensionMenu*      menu    = dynamic_cast<T100ExtensionMenu*>(m_server.Find(T100FONT_BUILDER_VIEW_MAIN_MENU_FILE));

    if(!menu){
        return;
    }

    menu->Send(event);
}

T100VOID T100FontFrame::CloseEvent()
{
    T100ExtensionFrame*     thisFrame       = dynamic_cast<T100ExtensionFrame*>(m_server.Find(T100FONT_BUILDER_VIEW_MAIN_FRAME));

    if(!thisFrame){
        return;
    }

    thisFrame->SignIn(T100EVENT_WINDOW_DESTROY, (T100EVENT_FUNCTION)&OnClose, this);
}

T100VOID T100FontFrame::OnClose(T100WindowEvent& event)
{
    ShowMessageBox(this, L"Quit?");
}

T100VOID T100FontFrame::QuitMenu()
{
    T100ExtensionMenu*      thisMenu    = dynamic_cast<T100ExtensionMenu*>(m_server.Find(T100FONT_BUILDER_VIEW_MAIN_MENU_FILE));

    if(!thisMenu){
        return;
    }

    T100MenuItem*           quitItem    = T100NEW T100MenuItem(thisMenu->GetMenu(), 1, L"Quit");
    thisMenu->SignIn(1, (T100EVENT_FUNCTION)&OnQuit, this);
}

T100VOID T100FontFrame::OnQuit(T100MenuEvent& event)
{
    PostQuitMessage(0);
}
