#include "T100PluginProjectProjectPanel.h"

#include <wx/sizer.h>
#include <wx/menu.h>

#include "T100PluginProjectInvoking.h"

BEGIN_EVENT_TABLE(T100PluginProjectProjectPanel, wxPanel)

END_EVENT_TABLE()

T100PluginProjectProjectPanel::T100PluginProjectProjectPanel(
            wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name) :
    wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
    init();
}

T100PluginProjectProjectPanel::~T100PluginProjectProjectPanel()
{
    //dtor
    uninit();
}

T100VOID T100PluginProjectProjectPanel::init()
{
    m_treectrl  = T100NEW wxTreeCtrl(this);

    m_treectrl->Connect(wxEVT_TREE_ITEM_MENU, (wxObjectEventFunction)&OnMenu, T100NULL, this);

    wxBoxSizer* sizer;

    sizer   = T100NEW wxBoxSizer(wxHORIZONTAL);

    sizer->Add(m_treectrl, 1, wxALL|wxEXPAND, 2);
    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100PluginProjectProjectPanel::uninit()
{
    m_treectrl->Disconnect(wxEVT_TREE_ITEM_MENU);
    T100SAFE_DELETE(m_treectrl);
}

T100VOID T100PluginProjectProjectPanel::Append(T100ProjectInfo& info)
{
    wxTreeItemId    root        = m_treectrl->GetRootItem();
    m_treectrl->AppendItem(root, info.GetProjectData().GetLabel());
}

T100VOID T100PluginProjectProjectPanel::Update(T100PROJECT_VESSEL& projects)
{
    m_treectrl->DeleteAllItems();

    wxTreeItemId    root    = m_treectrl->AddRoot(L"WorkSpace");

    for(T100Project* project : projects.GetVector()){
        m_treectrl->AppendItem(root, project->GetLabel());
    }
}

T100VOID T100PluginProjectProjectPanel::OnMenu(wxCommandEvent& event)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(10000, L"Create");
    m_treectrl->Connect(10000, wxEVT_MENU, (wxObjectEventFunction)&OnCreate, T100NULL, this);

    m_treectrl->PopupMenu(menu);
}

T100VOID T100PluginProjectProjectPanel::OnCreate(wxCommandEvent& event)
{
    T100PluginProjectInvoking::OnCreate(event);
}
