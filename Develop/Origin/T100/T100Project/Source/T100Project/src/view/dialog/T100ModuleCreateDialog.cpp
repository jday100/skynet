#include "T100ModuleCreateDialog.h"

const long T100ModuleCreateDialog::ID_MODULE_NAME_STATIC_TEXT      = wxNewId();
const long T100ModuleCreateDialog::ID_MODULE_NAME_TEXT_CTRL     = wxNewId();

BEGIN_EVENT_TABLE(T100ModuleCreateDialog, wxDialog)

END_EVENT_TABLE()

T100ModuleCreateDialog::T100ModuleCreateDialog(wxWindow *parent,
             wxWindowID id,
             const wxString& title,
             const wxPoint& pos,
             const wxSize& size,
             long style,
             const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    Center();
    init();
}

T100ModuleCreateDialog::~T100ModuleCreateDialog()
{
    //dtor
    uninit();
}

T100VOID T100ModuleCreateDialog::init()
{
    wxBoxSizer*         sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*   module      = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Module:"));

    m_nameTitle     = T100NEW wxStaticText(this, ID_MODULE_NAME_STATIC_TEXT, _("Name:"));
    m_nameValue     = T100NEW wxTextCtrl(this, ID_MODULE_NAME_TEXT_CTRL);

    module->Add(m_nameTitle, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    module->Add(m_nameValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(module, 1, wxALL|wxEXPAND, 5);

    sizer->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCANCEL), 0, wxALL | wxALIGN_RIGHT, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

    Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&OnApply);
}

T100VOID T100ModuleCreateDialog::uninit()
{

}

T100ModuleInfo* T100ModuleCreateDialog::GetModuleInfo()
{
    return m_info;
}

T100VOID T100ModuleCreateDialog::OnApply(wxCommandEvent& event)
{
    m_info  = T100NEW T100ModuleInfo();

    m_info->SetLabel(m_nameValue->GetValue().ToStdWstring());

    Close();
    SetReturnCode(wxID_APPLY);
}

