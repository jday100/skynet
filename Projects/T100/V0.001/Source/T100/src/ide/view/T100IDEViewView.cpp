#include "T100IDEViewView.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackView.h"

const long T100IDEViewView::ID_MENUITEM_VIEW_PROJECT        = wxNewId();


T100IDEViewView::T100IDEViewView(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewView::~T100IDEViewView()
{
    //dtor
}

T100BOOL T100IDEViewView::create_menu()
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

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_VIEW_PROJECT,    _("Project"),   wxEmptyString, wxITEM_CHECK);
    menu->Append(item);

    menubar->Append(menu, _("View"));

    frame->Connect(ID_MENUITEM_VIEW_PROJECT,    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewView::OnMenuViewProjectSelected);

    return T100TRUE;
}

void T100IDEViewView::OnMenuViewProjectSelected(wxCommandEvent& event)
{
    T100IDECallbackView::frame_menu_project();
}
