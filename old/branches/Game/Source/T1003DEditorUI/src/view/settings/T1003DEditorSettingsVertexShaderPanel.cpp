#include "T1003DEditorSettingsVertexShaderPanel.h"

#include <io.h>
#include <fstream>
#include <wx/sizer.h>
#include "T1003DEditorVertexShaderFile.h"

const long T1003DEditorSettingsVertexShaderPanel::ID_BUTTON_SAVE = wxNewId();
const long T1003DEditorSettingsVertexShaderPanel::ID_BUTTON_APPEND = wxNewId();
const long T1003DEditorSettingsVertexShaderPanel::ID_BUTTON_REMOVE = wxNewId();

BEGIN_EVENT_TABLE(T1003DEditorSettingsVertexShaderPanel,wxPanel)

END_EVENT_TABLE()

T1003DEditorSettingsVertexShaderPanel::T1003DEditorSettingsVertexShaderPanel(wxWindow *parent,
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

T1003DEditorSettingsVertexShaderPanel::~T1003DEditorSettingsVertexShaderPanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorSettingsVertexShaderPanel::init()
{
    m_count     = 0;

    wxBoxSizer*     BoxSizer        = T100NEW wxBoxSizer(wxVERTICAL);

    m_gridPtr   = T100NEW wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxSize(800,600));

    BoxSizer->Add(m_gridPtr, 1, wxALL|wxEXPAND, 5);

    wxBoxSizer*     BoxSizer1       = T100NEW wxBoxSizer(wxHORIZONTAL);

    m_buttonAppend = new wxButton(this, ID_BUTTON_APPEND, _("Append"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	BoxSizer1->Add(m_buttonAppend, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_buttonRemove = new wxButton(this, ID_BUTTON_REMOVE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	BoxSizer1->Add(m_buttonRemove, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_buttonSave = new wxButton(this, ID_BUTTON_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SAVE"));
	BoxSizer1->Add(m_buttonSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer->Add(BoxSizer1, 0, wxALL|wxALIGN_RIGHT, 5);

	SetSizer(BoxSizer);
	BoxSizer->Fit(this);
	BoxSizer->SetSizeHints(this);

    Connect(ID_BUTTON_APPEND,       wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsVertexShaderPanel::OnButtonAppendClick);
    Connect(ID_BUTTON_REMOVE,       wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsVertexShaderPanel::OnButtonRemoveClick);
    Connect(ID_BUTTON_SAVE,         wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsVertexShaderPanel::OnButtonSaveClick);

    if(access(m_name.c_str(), 0) != -1){
        Load();
    }
}

T100VOID T1003DEditorSettingsVertexShaderPanel::uninit()
{

}

T100VOID T1003DEditorSettingsVertexShaderPanel::Load()
{

}

T100VOID T1003DEditorSettingsVertexShaderPanel::Save()
{
    std::ofstream   ofs(m_name);
    T1003DEditorVertexShaderFile        file;

    ofs << file;
}

void T1003DEditorSettingsVertexShaderPanel::OnButtonAppendClick(wxCommandEvent& event)
{

}

void T1003DEditorSettingsVertexShaderPanel::OnButtonRemoveClick(wxCommandEvent& event)
{

}

void T1003DEditorSettingsVertexShaderPanel::OnButtonSaveClick(wxCommandEvent& event)
{
    Save();
}
