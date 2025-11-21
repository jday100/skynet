#include "T1003DEditorSettingsDescriptionReferencePanel.h"

#include <io.h>
#include <fstream>
#include <wx/sizer.h>

#include "T1003DEditorCallback.h"
#include "T1003DEditorDescriptionReferenceFile.h"

#include "T100DescriptionReferencePanelAmountData.h"

const long T1003DEditorSettingsDescriptionReferencePanel::ID_BUTTON_SAVE = wxNewId();
const long T1003DEditorSettingsDescriptionReferencePanel::ID_BUTTON_APPEND = wxNewId();
const long T1003DEditorSettingsDescriptionReferencePanel::ID_BUTTON_REMOVE = wxNewId();

BEGIN_EVENT_TABLE(T1003DEditorSettingsDescriptionReferencePanel,wxPanel)

END_EVENT_TABLE()

T1003DEditorSettingsDescriptionReferencePanel::T1003DEditorSettingsDescriptionReferencePanel(wxWindow *parent,
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

T1003DEditorSettingsDescriptionReferencePanel::~T1003DEditorSettingsDescriptionReferencePanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::init()
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

    Connect(ID_BUTTON_APPEND,       wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsDescriptionReferencePanel::OnButtonAppendClick);
    Connect(ID_BUTTON_REMOVE,       wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsDescriptionReferencePanel::OnButtonRemoveClick);
    Connect(ID_BUTTON_SAVE,         wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsDescriptionReferencePanel::OnButtonSaveClick);

    Load();

    m_gridPtr->Connect(wxEVT_PG_CHANGED, (wxObjectEventFunction)&T1003DEditorSettingsDescriptionReferencePanel::OnPGChanged, T100NULL, this);
}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::uninit()
{

}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::Load()
{
    T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&     data        = T1003DEditorCallback::GetDescriptionReferences();

    Decode(data);
}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::Save()
{
    T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&     data        = T1003DEditorCallback::GetDescriptionReferences();

    data.clear();

    Encode(data);

    T1003DEditorCallback::SaveDescriptionReferences(data);
}

void T1003DEditorSettingsDescriptionReferencePanel::OnButtonAppendClick(wxCommandEvent& event)
{
    m_count++;

    T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE*      data        = T100NEW T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE();
    T1003DEditorDescriptionReferenceData*                       desc        = T100NEW T1003DEditorDescriptionReferenceData();

    T100UINT            value   = m_count;
    wxString            name    = wxString::Format("DescriptionReference%u", value);
    data->Category      = T100NEW wxPropertyCategory(name);
    wxString            label   = wxString::Format("name%u", value);
    data->Name          = T100NEW wxStringProperty(wxT("Name"), label);
    label               = wxString::Format("amount%u", value);
    data->Amount        = T100NEW wxUIntProperty(wxT("Amount"), label);

    T100DescriptionReferencePanelAmountData*            amountData          = T100NEW T100DescriptionReferencePanelAmountData(m_gridPtr, desc, m_count);
    data->Amount->SetClientObject(amountData);

    data->Category->AppendChild(data->Name);
    data->Category->AppendChild(data->Amount);

    m_gridPtr->Append(data->Category);

    m_descriptionReferences.push_back(data);
}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::Remove(wxClientData* value)
{

}

void T1003DEditorSettingsDescriptionReferencePanel::OnPGChanged(wxPropertyGridEvent& event)
{
    wxPGProperty*           property    = event.GetProperty();

    if(property){
        T100GridClientData*     data    = dynamic_cast<T100GridClientData*>(property->GetClientObject());
        if(data){
            data->Update(property);
            T1003DEditorCallback::SetDirty();
        }
    }
}

void T1003DEditorSettingsDescriptionReferencePanel::OnButtonRemoveClick(wxCommandEvent& event)
{
    wxPGProperty*   selection   = m_gridPtr->GetSelectedProperty();

    if(selection){
        Remove(selection->GetClientObject());
    }
}

void T1003DEditorSettingsDescriptionReferencePanel::OnButtonSaveClick(wxCommandEvent& event)
{
    Save();
}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::Encode(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&)
{

}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::Decode(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& data)
{
    m_count     = 0;

    for(T1003DEditorDescriptionReferenceData* desc : data){
        T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE*   item    = T100NEW T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE();

        DecodeDesc(item, desc);

        m_descriptionReferences.push_back(item);
    }
}

T100VOID T1003DEditorSettingsDescriptionReferencePanel::DecodeDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE* target, T1003DEditorDescriptionReferenceData* source)
{
    m_count++;

    T100UINT            value   = m_count;
    wxString            name    = wxString::Format("DescriptionReference%u", value);
    target->Category    = T100NEW wxPropertyCategory(name);
    wxString            label   = wxString::Format("name%u", value);
    target->Name        = T100NEW wxStringProperty(wxT("Name"), label);
    label               = wxString::Format("amount%u", value);
    target->Amount      = T100NEW wxUIntProperty(wxT("Amount"), label);

    T100DescriptionReferencePanelAmountData*            amountData          = T100NEW T100DescriptionReferencePanelAmountData(m_gridPtr, source, m_count);
    target->Amount->SetClientObject(amountData);

    target->Category->AppendChild(target->Name);
    target->Category->AppendChild(target->Amount);

    m_gridPtr->Append(target->Category);
}
