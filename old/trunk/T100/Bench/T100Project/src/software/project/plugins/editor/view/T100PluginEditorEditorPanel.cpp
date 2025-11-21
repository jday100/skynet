#include "T100PluginEditorEditorPanel.h"

#include <wx/sizer.h>

BEGIN_EVENT_TABLE(T100PluginEditorEditorPanel, wxPanel)

END_EVENT_TABLE()

T100PluginEditorEditorPanel::T100PluginEditorEditorPanel(
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

T100PluginEditorEditorPanel::~T100PluginEditorEditorPanel()
{
    //dtor
    uninit();
}

T100VOID T100PluginEditorEditorPanel::init()
{
    m_stc   = T100NEW wxStyledTextCtrl(this);

    //m_treectrl->Connect(wxEVT_TREE_ITEM_MENU, (wxObjectEventFunction)&OnMenu, T100NULL, this);

    wxBoxSizer* sizer;

    sizer   = T100NEW wxBoxSizer(wxHORIZONTAL);

    sizer->Add(m_stc, 1, wxALL|wxEXPAND, 2);
    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100PluginEditorEditorPanel::uninit()
{
    T100SAFE_DELETE(m_stc);
}
