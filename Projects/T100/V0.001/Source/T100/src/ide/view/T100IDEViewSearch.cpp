#include "T100IDEViewSearch.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackSearch.h"

const long T100IDEViewSearch::ID_MENUITEM_SEARCH_FIND       = wxNewId();
const long T100IDEViewSearch::ID_MENUITEM_SEARCH_REPLACE    = wxNewId();


T100IDEViewSearch::T100IDEViewSearch(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewSearch::~T100IDEViewSearch()
{
    //dtor
}

T100BOOL T100IDEViewSearch::create_menu()
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

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_SEARCH_FIND,     _("Find"),      wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    menu->AppendSeparator();

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_SEARCH_REPLACE,  _("Replace"),   wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("Search"));

    frame->Connect(ID_MENUITEM_SEARCH_FIND,     wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewSearch::OnMenuSearchFindSelected);
    frame->Connect(ID_MENUITEM_SEARCH_REPLACE,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewSearch::OnMenuSearchReplaceSelected);

    return T100TRUE;
}

void T100IDEViewSearch::OnMenuSearchFindSelected(wxCommandEvent& event)
{
    T100IDECallbackSearch::frame_menu_find();
}

void T100IDEViewSearch::OnMenuSearchReplaceSelected(wxCommandEvent& event)
{
    T100IDECallbackSearch::frame_menu_replace();
}
