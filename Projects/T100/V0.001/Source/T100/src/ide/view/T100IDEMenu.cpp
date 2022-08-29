#include "T100IDEMenu.h"

#include <wx/frame.h>
#include "T100IDECallbackMenu.h"
#include "T100IDEFrameNew.h"
#include "T100IDEView.h"


const long T100IDEMenu::ID_MENUITEM_NEW     = wxNewId();
const long T100IDEMenu::ID_MENUITEM_OPEN    = wxNewId();
const long T100IDEMenu::ID_MENUITEM_CLOSE   = wxNewId();
const long T100IDEMenu::ID_MENUITEM_QUIT    = wxNewId();


T100IDEMenu::T100IDEMenu(wxFrame* frame)
    :m_frame(frame)
{
    //ctor
}

T100IDEMenu::~T100IDEMenu()
{
    //dtor
    destroy();
}

T100BOOL T100IDEMenu::create()
{
    T100IDEFrameNew*    frame     = T100NULL;

    frame = dynamic_cast<T100IDEFrameNew*>(m_frame);

    if(!frame){
        return T100FALSE;
    }

    m_menu_bar = T100NEW wxMenuBar();
    frame->SetMenuBar(m_menu_bar);

    create_main();

    return T100TRUE;
}

T100VOID T100IDEMenu::destroy()
{

}

T100VOID T100IDEMenu::create_main()
{
    /*
    wxMenu*         menu    = T100NEW wxMenu();

    wxMenuItem*     item    = T100NEW wxMenuItem(menu, ID_MENUITEM_NEW, _("New"), wxEmptyString, wxITEM_NORMAL);

    menu->Append(item);
    menu->AppendSeparator();

    item = T100NEW wxMenuItem(menu, ID_MENUITEM_OPEN,   _("Open"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item = T100NEW wxMenuItem(menu, ID_MENUITEM_CLOSE,  _("Close"), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    menu->AppendSeparator();
    item = T100NEW wxMenuItem(menu, ID_MENUITEM_QUIT,   _("Quit"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);


    m_menu_bar->Append(menu, _("File"));

    m_frame->Connect(ID_MENUITEM_NEW,   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEMenu::OnMenuNewSelected);
    m_frame->Connect(ID_MENUITEM_OPEN,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEMenu::OnMenuOpenSelected);
    m_frame->Connect(ID_MENUITEM_CLOSE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEMenu::OnMenuCloseSelected);
    m_frame->Connect(ID_MENUITEM_QUIT,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEMenu::OnMenuQuitSelected);

    m_frame->SetMenuBar(m_menu_bar);
    */

    T100BOOL            result;
    T100IDEFrameNew*    frame     = T100NULL;

    frame = dynamic_cast<T100IDEFrameNew*>(m_frame);

    if(!frame){
        return;
    }

    result = frame->getView()->getProject()->create_menu();
    result = frame->getView()->getFile()->create_menu();
    result = frame->getView()->getEdit()->create_menu();
    result = frame->getView()->getView()->create_menu();
    result = frame->getView()->getSearch()->create_menu();
    result = frame->getView()->getBuild()->create_menu();
    result = frame->getView()->getDebug()->create_menu();
    result = frame->getView()->getSetup()->create_menu();
    result = frame->getView()->getHelp()->create_menu();

}

void T100IDEMenu::OnMenuNewSelected(wxCommandEvent& event)
{
    T100IDECallbackMenu::frame_menu_new();
}

void T100IDEMenu::OnMenuOpenSelected(wxCommandEvent& event)
{
    T100IDECallbackMenu::frame_menu_open();
}

void T100IDEMenu::OnMenuCloseSelected(wxCommandEvent& event)
{
    T100IDECallbackMenu::frame_menu_close();
}

void T100IDEMenu::OnMenuQuitSelected(wxCommandEvent& event)
{
    T100IDECallbackMenu::frame_menu_quit();
}
