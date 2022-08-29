#include "T100IDEViewHelp.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackHelp.h"

const long T100IDEViewHelp::ID_MENUITEM_HELP_ABOUT      = wxNewId();


T100IDEViewHelp::T100IDEViewHelp(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewHelp::~T100IDEViewHelp()
{
    //dtor
}

T100BOOL T100IDEViewHelp::create_menu()
{
    T100IDEFrameNew*    frame       = T100NULL;
    wxMenuBar*          menubar     = T100NULL;

    frame   = m_view->getFrame();

    if(!frame){
        return T100FALSE;
    }

    menubar = frame->GetMenuBar();

    if(!menubar){
        return T100FALSE;
    }

    wxMenu*         menu    = T100NEW wxMenu();
    wxMenuItem*     item;

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_HELP_ABOUT,  _("About"), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("Help"));

    frame->Connect(ID_MENUITEM_HELP_ABOUT,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewHelp::OnMenuHelpAboutSelected);

    return T100TRUE;
}

void T100IDEViewHelp::OnMenuHelpAboutSelected(wxCommandEvent& event)
{
    T100IDECallbackHelp::frame_menu_about();
}
