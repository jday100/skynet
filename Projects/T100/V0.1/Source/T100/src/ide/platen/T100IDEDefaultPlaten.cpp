#include "T100IDEDefaultPlaten.h"

#include <wx/stockitem.h>
#include "T100IDEMainFrame.h"

namespace T100IDE{

T100IDEDefaultPlaten::T100IDEDefaultPlaten(T100IDEView* view)
    :T100IDEPlatenBase(view)
{
    //ctor
}

T100IDEDefaultPlaten::~T100IDEDefaultPlaten()
{
    //dtor
    destroy();
}

T100BOOL T100IDEDefaultPlaten::create()
{
    T100BOOL        result;

    result = create_menu();

    return result;
}

T100VOID T100IDEDefaultPlaten::destroy()
{

}

T100BOOL T100IDEDefaultPlaten::show()
{
    return T100TRUE;
}

T100BOOL T100IDEDefaultPlaten::hide()
{
    return T100TRUE;
}

T100BOOL T100IDEDefaultPlaten::create_menu()
{
    T100IDEMainFrame* frame     = T100NULL;

    if(!m_view)return T100FALSE;

    frame = m_view->getFrame();
    if(!frame)return T100FALSE;

    wxMenuBar*  menuBar     = T100NEW wxMenuBar();
    wxMenu*     menuFile    = T100NEW wxMenu();
    wxMenu*     menuTools   = T100NEW wxMenu();
    wxMenu*     menuHelp    = T100NEW wxMenu();

    m_menu_view     = T100NEW wxMenu();

    //File
    menuFile->Append(wxID_NEW);
    menuFile->Append(wxID_OPEN);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuBar->Append(menuFile, wxGetStockLabel(wxID_FILE));

    /*
    //View
    m_menu_view->Append(T100IDE_EVENT_MAIN_MENU_ID_VIEW_PROJECTS, wxT("Projects"), wxEmptyString, T100TRUE);

    menuBar->Append(m_menu_view, wxT("View"));

    menuTools->Append(T100IDE_EVENT_MAIN_MENU_ID_TOOLS_FONT_BUILDER, wxT("Font builder…"));
    menuTools->Append(T100IDE_EVENT_MAIN_MENU_ID_TOOLS_VDISK_MANAGER, wxT("VDisk manager…"));

    menuBar->Append(menuTools, wxT("Tools"));
    */

    //Help
    menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuHelp, wxGetStockLabel(wxID_HELP));

    //MenuBar
    frame->SetMenuBar(menuBar);

    return T100TRUE;
}

wxMenuBar* T100IDEDefaultPlaten::CreateMainMenuBar()
{
    wxMenuBar*  menuBar     = T100NEW wxMenuBar();
    wxMenu*     menuFile    = T100NEW wxMenu();
    wxMenu*     menuHelp    = T100NEW wxMenu();

    //File
    menuFile->Append(wxID_NEW);
    menuFile->Append(wxID_OPEN);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuBar->Append(menuFile, wxGetStockLabel(wxID_FILE));

    //Help
    menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuHelp, wxGetStockLabel(wxID_HELP));

    return menuBar;
}

}
