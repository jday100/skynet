#include "T1003DEditorConfigPanel.h"

#include <wx/sizer.h>
#include "T1003DEditorConfig.h"
#include "T1003DEditorCallback.h"

const long T1003DEditorConfigPanel::ID_BUTTON_SAVE = wxNewId();
const long T1003DEditorConfigPanel::ID_STATICTEXT_COORDINATE = wxNewId();
const long T1003DEditorConfigPanel::ID_CHOICE_COORDINATE = wxNewId();
const long T1003DEditorConfigPanel::ID_STATICTEXT_PROJECTION = wxNewId();
const long T1003DEditorConfigPanel::ID_CHOICE_PROJECTION = wxNewId();

BEGIN_EVENT_TABLE(T1003DEditorConfigPanel,wxPanel)

END_EVENT_TABLE()

T1003DEditorConfigPanel::T1003DEditorConfigPanel(wxWindow *parent,
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

T1003DEditorConfigPanel::~T1003DEditorConfigPanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorConfigPanel::init()
{
	wxBoxSizer*             BoxSizer1;
	wxBoxSizer*             BoxSizer2;
	wxFlexGridSizer*        FlexGridSizer1;
	wxStaticBoxSizer*       StaticBoxSizer1;

	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Default"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	m_coordinateStaticText = new wxStaticText(this, ID_STATICTEXT_COORDINATE, _("CoordinateSystem:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(m_coordinateStaticText, 1, wxALL|wxALIGN_RIGHT, 5);
	m_coordinateChoice = new wxChoice(this, ID_CHOICE_COORDINATE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	m_coordinateChoice->Append(_("Left Hand"));
	m_coordinateChoice->Append(_("Right Hand"));
	m_coordinateChoice->SetSelection(T1003DEditorConfig::DefaultCoordinateSystemType);
	FlexGridSizer1->Add(m_coordinateChoice, 1, wxALL|wxEXPAND, 5);
	m_projectionStaticText = new wxStaticText(this, ID_STATICTEXT_PROJECTION, _("Projection:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(m_projectionStaticText, 1, wxALL|wxALIGN_RIGHT, 5);
	m_projectionChoice = new wxChoice(this, ID_CHOICE_PROJECTION, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	m_projectionChoice->Append(_("Orthographic"));
	m_projectionChoice->Append(_("Perspective"));
	m_projectionChoice->SetSelection(T1003DEditorConfig::DefaultProjectiveType);
	FlexGridSizer1->Add(m_projectionChoice, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	m_buttonSave = new wxButton(this, ID_BUTTON_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SAVE"));
	BoxSizer2->Add(m_buttonSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_RIGHT, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE_COORDINATE,   wxEVT_COMMAND_CHOICE_SELECTED,      (wxObjectEventFunction)&T1003DEditorConfigPanel::OnChoiceCoordinateSelect);
	Connect(ID_CHOICE_PROJECTION,   wxEVT_COMMAND_CHOICE_SELECTED,      (wxObjectEventFunction)&T1003DEditorConfigPanel::OnChoiceProjectionSelect);
    Connect(ID_BUTTON_SAVE,         wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorConfigPanel::OnButtonSaveClick);
}

T100VOID T1003DEditorConfigPanel::uninit()
{

}
void T1003DEditorConfigPanel::OnChoiceCoordinateSelect(wxCommandEvent& event)
{
    switch(m_coordinateChoice->GetSelection()){
    case 0:
        {
            T1003DEditorConfig::DefaultCoordinateSystemType     = T100DX12_COORDINATE_SYSTEM_LEFT_HAND;
        }
        break;
    case 1:
        {
            T1003DEditorConfig::DefaultCoordinateSystemType     = T100DX12_COORDINATE_SYSTEM_RIGHT_HAND;
        }
        break;
    }
}

void T1003DEditorConfigPanel::OnChoiceProjectionSelect(wxCommandEvent& event)
{
    switch(m_projectionChoice->GetSelection()){
    case 0:
        {
            T1003DEditorConfig::DefaultProjectiveType   = T100DX12_ORTHOGRAPHIC_PROJECTION;
        }
        break;
    case 1:
        {
            T1003DEditorConfig::DefaultProjectiveType   = T100DX12_PERSPECTIVE_PROJECTION;
        }
        break;
    }
}

void T1003DEditorConfigPanel::OnButtonSaveClick(wxCommandEvent& event)
{
    T1003DEditorCallback::SaveConfig();
}
