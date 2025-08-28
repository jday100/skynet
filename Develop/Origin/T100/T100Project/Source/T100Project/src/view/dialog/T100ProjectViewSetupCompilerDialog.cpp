#include "T100ProjectViewSetupCompilerDialog.h"

const long T100ProjectViewSetupCompilerDialog::ID_COMPILER_PATH_STATIC_TEXT    = wxNewId();
const long T100ProjectViewSetupCompilerDialog::ID_COMPILER_PATH_FOLDER_PICKER  = wxNewId();

T100ProjectViewSetupCompilerDialog::T100ProjectViewSetupCompilerDialog(wxWindow *parent,
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

T100ProjectViewSetupCompilerDialog::~T100ProjectViewSetupCompilerDialog()
{
    //dtor
    uninit();
}

T100VOID T100ProjectViewSetupCompilerDialog::init()
{
    wxBoxSizer*         sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*   gcc         = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("GCC:"));

    m_compilerPathStaticText        = T100NEW wxStaticText(this, ID_COMPILER_PATH_STATIC_TEXT, _("Compiler's directory:"));
    m_compilerPathFolderPicker      = T100NEW wxDirPickerCtrl(this, ID_COMPILER_PATH_FOLDER_PICKER);

    gcc->Add(m_compilerPathStaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    gcc->Add(m_compilerPathFolderPicker, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(gcc, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100ProjectViewSetupCompilerDialog::uninit()
{

}
