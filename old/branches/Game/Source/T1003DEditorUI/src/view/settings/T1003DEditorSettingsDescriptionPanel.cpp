#include "T1003DEditorSettingsDescriptionPanel.h"

#include <io.h>
#include <fstream>
#include <wx/sizer.h>
#include "T100DescriptionGridData.h"
#include "T1003DEditorCallback.h"

const long T1003DEditorSettingsDescriptionPanel::ID_BUTTON_SAVE = wxNewId();
const long T1003DEditorSettingsDescriptionPanel::ID_BUTTON_APPEND = wxNewId();
const long T1003DEditorSettingsDescriptionPanel::ID_BUTTON_REMOVE = wxNewId();

BEGIN_EVENT_TABLE(T1003DEditorSettingsDescriptionPanel,wxPanel)

END_EVENT_TABLE()

T1003DEditorSettingsDescriptionPanel::T1003DEditorSettingsDescriptionPanel(wxWindow *parent,
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

T1003DEditorSettingsDescriptionPanel::~T1003DEditorSettingsDescriptionPanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorSettingsDescriptionPanel::init()
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

    Connect(ID_BUTTON_APPEND,       wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsDescriptionPanel::OnButtonAppendClick);
    Connect(ID_BUTTON_REMOVE,       wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsDescriptionPanel::OnButtonRemoveClick);
    Connect(ID_BUTTON_SAVE,         wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T1003DEditorSettingsDescriptionPanel::OnButtonSaveClick);

    Load();
}

T100VOID T1003DEditorSettingsDescriptionPanel::uninit()
{

}

void T1003DEditorSettingsDescriptionPanel::OnButtonAppendClick(wxCommandEvent& event)
{
    m_count++;

    T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*        desc        = T100NEW T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION();

    T100UINT            value   = m_count;
    wxString            name    = wxString::Format(L"Description%u", value);
    desc->Category      = T100NEW wxPropertyCategory(name);
    wxString            label   = wxString::Format("name%u", value);
    desc->Name          = T100NEW wxStringProperty(wxT("Name"), label);
    label               = wxString::Format("index%u", value);
    desc->Index         = T100NEW wxUIntProperty(wxT("Index"), label);
    label               = wxString::Format("format%u", value);
    desc->Format        = T100NEW wxEnumProperty(wxT("Format"), label, enumFormatLabels, enumFormatValues);
    label               = wxString::Format("slot%u", value);
    desc->Slot          = T100NEW wxUIntProperty(wxT("Slot"), label);
    label               = wxString::Format("offset%u", value);
    desc->Offset        = T100NEW wxUIntProperty(wxT("Offset"), label);
    label               = wxString::Format("inputslotclass%u", value);
    desc->InputClass    = T100NEW wxEnumProperty(wxT("InputSlotClass"), label, enumClassificationLabels, enumClassificationValues);
    label               = wxString::Format("rate%u", value);
    desc->Rate          = T100NEW wxUIntProperty(wxT("Rate"), label);

    SetClientData(desc);

    desc->Category->AppendChild(desc->Name);
    desc->Category->AppendChild(desc->Index);
    desc->Category->AppendChild(desc->Format);
    desc->Category->AppendChild(desc->Slot);
    desc->Category->AppendChild(desc->Offset);
    desc->Category->AppendChild(desc->InputClass);
    desc->Category->AppendChild(desc->Rate);
    m_gridPtr->Append(desc->Category);

    m_descs.push_back(desc);
}

T100VOID T1003DEditorSettingsDescriptionPanel::Remove(wxClientData* value)
{
    T100DescriptionGridData*    data    = dynamic_cast<T100DescriptionGridData*>(value);

    if(data){
        m_gridPtr->RemoveProperty(data->Desc->Name);
        m_gridPtr->RemoveProperty(data->Desc->Index);
        m_gridPtr->RemoveProperty(data->Desc->Format);;
        m_gridPtr->RemoveProperty(data->Desc->Offset);
        m_gridPtr->RemoveProperty(data->Desc->Slot);
        m_gridPtr->RemoveProperty(data->Desc->InputClass);
        m_gridPtr->RemoveProperty(data->Desc->Rate);
        m_gridPtr->RemoveProperty(data->Desc->Category);

        RemoveDesc(data->Desc);
    }
}

T100VOID T1003DEditorSettingsDescriptionPanel::RemoveDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION* desc)
{
    T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_VECTOR::iterator            it;

    for(it = m_descs.begin(); it != m_descs.end(); ++it){
        if(desc == *it){
            m_descs.erase(it);
            T100SAFE_DELETE desc;
            return;
        }
    }
}

void T1003DEditorSettingsDescriptionPanel::OnButtonRemoveClick(wxCommandEvent& event)
{
    wxPGProperty*   selection   = m_gridPtr->GetSelectedProperty();

    if(selection){
        Remove(selection->GetClientObject());
    }
}

void T1003DEditorSettingsDescriptionPanel::OnButtonSaveClick(wxCommandEvent& event)
{
    Save();
}

T100VOID T1003DEditorSettingsDescriptionPanel::SetClientData(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION* desc)
{
    T100DescriptionGridData*    category        = T100NEW T100DescriptionGridData();

    category->Desc      = desc;
    desc->Category->SetClientObject(category);

    T100DescriptionGridData*    name            = T100NEW T100DescriptionGridData();

    name->Desc          = desc;
    desc->Name->SetClientObject(name);

    T100DescriptionGridData*    index           = T100NEW T100DescriptionGridData();

    index->Desc         = desc;
    desc->Index->SetClientObject(index);

    T100DescriptionGridData*    format          = T100NEW T100DescriptionGridData();

    format->Desc        = desc;
    desc->Format->SetClientObject(format);

    T100DescriptionGridData*    slot            = T100NEW T100DescriptionGridData();

    slot->Desc          = desc;
    desc->Slot->SetClientObject(slot);

    T100DescriptionGridData*    offset          = T100NEW T100DescriptionGridData();

    offset->Desc        = desc;
    desc->Offset->SetClientObject(offset);

    T100DescriptionGridData*    inputClass      = T100NEW T100DescriptionGridData();

    inputClass->Desc    = desc;
    desc->InputClass->SetClientObject(inputClass);

    T100DescriptionGridData*    rate            = T100NEW T100DescriptionGridData();

    rate->Desc          = desc;
    desc->Rate->SetClientObject(rate);
}

T100VOID T1003DEditorSettingsDescriptionPanel::Load()
{
    T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&     descs       = T1003DEditorCallback::GetDescriptions();

    Decode(descs);
}

T100VOID T1003DEditorSettingsDescriptionPanel::Save()
{
    T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&     descs       = T1003DEditorCallback::GetDescriptions();

    descs.clear();

    Encode(descs);

    T1003DEditorCallback::SaveDescriptions(descs);
}

T100VOID T1003DEditorSettingsDescriptionPanel::Encode(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& descs)
{
    for(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*    desc : m_descs){
        T100D3D12_INPUT_ELEMENT_DESC*       item        = T100NEW T100D3D12_INPUT_ELEMENT_DESC();

        EncodeDesc(desc, item);

        descs.push_back(item);
    }
}

T100VOID T1003DEditorSettingsDescriptionPanel::EncodeDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION* source, T100D3D12_INPUT_ELEMENT_DESC* target)
{
    target->SemanticName            = source->Name->GetValueAsString().c_str();
    target->SemanticIndex           = source->Index->GetValue().GetInteger();
    target->Format                  = T1003DEditorDescriptionFile::ConvertFormat(source->Format->GetValue().GetInteger());
    target->InputSlot               = source->Slot->GetValue().GetInteger();
    target->AlignedByteOffset       = source->Offset->GetValue().GetInteger();
    target->InputSlotClass          = T1003DEditorDescriptionFile::ConvertClassification(source->InputClass->GetValue().GetInteger());
    target->InstanceDataStepRate    = source->Rate->GetValue().GetInteger();
}

T100VOID T1003DEditorSettingsDescriptionPanel::Decode(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& descs)
{
    m_count     = 0;

    for(T100D3D12_INPUT_ELEMENT_DESC*   desc : descs){
        T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*    item        = T100NEW T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION();

        DecodeDesc(item, desc);

        m_descs.push_back(item);
    }
}

T100VOID T1003DEditorSettingsDescriptionPanel::DecodeDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION* target, T100D3D12_INPUT_ELEMENT_DESC* source)
{
    m_count++;

    T100UINT            value   = m_count;
    wxString            name    = wxString::Format(L"Description%u", value);
    target->Category    = T100NEW wxPropertyCategory(name);
    wxString            label   = wxString::Format("name%u", value);
    target->Name        = T100NEW wxStringProperty(wxT("Name"), label, source->SemanticName);
    label               = wxString::Format("index%u", value);
    target->Index       = T100NEW wxUIntProperty(wxT("Index"), label, source->SemanticIndex);
    label               = wxString::Format("format%u", value);
    target->Format      = T100NEW wxEnumProperty(wxT("Format"), label, enumFormatLabels, enumFormatValues, source->Format);
    label               = wxString::Format("slot%u", value);
    target->Slot        = T100NEW wxUIntProperty(wxT("Slot"), label, source->InputSlot);
    label               = wxString::Format("offset%u", value);
    target->Offset      = T100NEW wxUIntProperty(wxT("Offset"), label, source->AlignedByteOffset);
    label               = wxString::Format("inputslotclass%u", value);
    target->InputClass  = T100NEW wxEnumProperty(wxT("InputSlotClass"), label, enumClassificationLabels, enumClassificationValues, source->InputSlotClass);
    label               = wxString::Format("rate%u", value);
    target->Rate        = T100NEW wxUIntProperty(wxT("Rate"), label, source->InstanceDataStepRate);

    SetClientData(target);

    target->Category->AppendChild(target->Name);
    target->Category->AppendChild(target->Index);
    target->Category->AppendChild(target->Format);
    target->Category->AppendChild(target->Slot);
    target->Category->AppendChild(target->Offset);
    target->Category->AppendChild(target->InputClass);
    target->Category->AppendChild(target->Rate);
    m_gridPtr->Append(target->Category);
}
