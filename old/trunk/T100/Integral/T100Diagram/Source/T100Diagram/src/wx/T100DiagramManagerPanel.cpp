#include "T100DiagramManagerPanel.h"

const long T100DiagramManagerPanel::ID_NOTEBOOK     = wxNewId();

BEGIN_EVENT_TABLE(T100DiagramManagerPanel, wxPanel)

END_EVENT_TABLE()

T100DiagramManagerPanel::T100DiagramManagerPanel(wxWindow *parent,
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

T100DiagramManagerPanel::~T100DiagramManagerPanel()
{
    //dtor
    uninit();
}

T100VOID T100DiagramManagerPanel::init()
{
    wxBoxSizer*     sizer;

    sizer = T100NEW wxBoxSizer(wxHORIZONTAL);

    m_notebook  = T100NEW wxNotebook(this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK"));


    m_elementPanel      = T100NEW T100DiagramElementPanel(m_notebook);
    m_entityPanel       = T100NEW T100DiagramEntityPanel(m_notebook);


    m_notebook->AddPage(m_elementPanel, _("Element"));
    m_notebook->AddPage(m_entityPanel, _("Diagram"));

    sizer->Add(m_notebook, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

    Connect(ID_NOTEBOOK,    wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,    (wxObjectEventFunction)&T100DiagramManagerPanel::OnNotebookPageChanged);
    Connect(ID_NOTEBOOK,    wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING,   (wxObjectEventFunction)&T100DiagramManagerPanel::OnNotebookPageChanging);

}

T100VOID T100DiagramManagerPanel::uninit()
{
    T100SAFE_DELETE(m_elementPanel)
    T100SAFE_DELETE(m_entityPanel)
}

T100VOID T100DiagramManagerPanel::Clear()
{
    switch(m_index){
    case 0:
        {
            m_elementPanel->Clear();
        }
        break;
    case 1:
        {
            m_entityPanel->Clear();
        }
        break;
    }

}

T100VOID T100DiagramManagerPanel::OnNotebookPageChanged(wxNotebookEvent& event)
{
    m_index     = event.GetSelection();
}

T100VOID T100DiagramManagerPanel::OnNotebookPageChanging(wxNotebookEvent& event)
{

}
