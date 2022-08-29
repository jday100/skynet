#include "T100IDEViewProject.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackProject.h"
#include "T100IDEPanelProject.h"

const long T100IDEViewProject::ID_MENUITEM_PROJECT_NEW      = wxNewId();
const long T100IDEViewProject::ID_MENUITEM_PROJECT_OPEN     = wxNewId();
const long T100IDEViewProject::ID_MENUITEM_PROJECT_CLOSE    = wxNewId();
const long T100IDEViewProject::ID_MENUITEM_PROJECT_QUIT     = wxNewId();


T100IDEViewProject::T100IDEViewProject(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewProject::~T100IDEViewProject()
{
    //dtor
}

T100BOOL T100IDEViewProject::create_menu()
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

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_PROJECT_NEW,     _("New"),   wxEmptyString, wxITEM_NORMAL);

    menu->Append(item);
    menu->AppendSeparator();

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_PROJECT_OPEN,    _("Open"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_PROJECT_CLOSE,   _("Close"), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menu->AppendSeparator();
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_PROJECT_QUIT,    _("Quit"), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("Project"));

    frame->Connect(ID_MENUITEM_PROJECT_NEW,   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewProject::OnMenuProjectNewSelected);
    frame->Connect(ID_MENUITEM_PROJECT_OPEN,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewProject::OnMenuProjectOpenSelected);
    frame->Connect(ID_MENUITEM_PROJECT_CLOSE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewProject::OnMenuProjectCloseSelected);
    frame->Connect(ID_MENUITEM_PROJECT_QUIT,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewProject::OnMenuProjectQuitSelected);

    return T100TRUE;
}

T100BOOL T100IDEViewProject::show(T100IDE_PROJECT_VECTOR& projects)
{
    T100IDEPanelProject* panel;

    panel = T100NEW T100IDEPanelProject(m_view->getFrame());
    m_view->getManager()->getAuiManager()->AddPane(panel,wxAuiPaneInfo().
                  Name(wxT("test9")).Caption(wxT("Min Size 200x100")).
                  BestSize(wxSize(200,100)).MinSize(wxSize(200,100)).
                  Bottom().Layer(1).
                  CloseButton(true).MaximizeButton(true));

    wxTreeItemId    root, id;

    root = panel->TreeCtrl1->AddRoot("work");
    for(auto item : projects){
        panel->TreeCtrl1->AppendItem(root, item->m_folder.to_std_string());
    }

    panel->TreeCtrl1->Expand(root);

    m_view->getManager()->getAuiManager()->Update();

    return T100FALSE;
}

T100BOOL T100IDEViewProject::opened()
{
    T100IDEServe* serve     = T100NULL;

    serve = dynamic_cast<T100IDEServe*>(m_view->getServe());

    if(!serve){
        //exception
        return T100FALSE;
    }

    return serve->getFile()->opened();
}

T100BOOL T100IDEViewProject::create()
{
    T100BOOL        result;
    T100IDEServe*   serve     = T100NULL;

    serve = dynamic_cast<T100IDEServe*>(m_view->getServe());

    if(!serve){
        //exception
        return T100FALSE;
    }

    if(serve->getFile()->exist()){

    }else{
        result = serve->getFile()->create();
    }


    return result;
}

T100BOOL T100IDEViewProject::open()
{
    return T100FALSE;
}

T100BOOL T100IDEViewProject::close()
{
    return T100FALSE;
}

void T100IDEViewProject::OnMenuProjectNewSelected(wxCommandEvent& event)
{
    T100IDECallbackProject::frame_menu_new();
}

void T100IDEViewProject::OnMenuProjectOpenSelected(wxCommandEvent& event)
{
    T100IDECallbackProject::frame_menu_open();
}

void T100IDEViewProject::OnMenuProjectCloseSelected(wxCommandEvent& event)
{
    T100IDECallbackProject::frame_menu_close();
}

void T100IDEViewProject::OnMenuProjectQuitSelected(wxCommandEvent& event)
{
    T100IDECallbackProject::frame_menu_quit();
}

