#include "T100WorkSpacePropertiesDialog.h"

const long T100WorkSpacePropertiesDialog::ID_STATIC_TEXT    = wxNewId();
const long T100WorkSpacePropertiesDialog::ID_PYTHON_DIR     = wxNewId();

T100WorkSpacePropertiesDialog::T100WorkSpacePropertiesDialog(wxWindow *parent,
             wxWindowID id,
             const wxString& title,
             const wxPoint& pos,
             const wxSize& size,
             long style,
             const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    init();
}

T100WorkSpacePropertiesDialog::~T100WorkSpacePropertiesDialog()
{
    //dtor
    uninit();
}

T100VOID T100WorkSpacePropertiesDialog::init()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*       python  = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Python:"));

    m_title     = T100NEW wxStaticText(this, ID_STATIC_TEXT, _("Bin:"));
    m_dir       = T100NEW wxDirPickerCtrl(this, ID_PYTHON_DIR);

    python->Add(m_title, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    python->Add(m_dir, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(python, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

    Center();
}

T100VOID T100WorkSpacePropertiesDialog::uninit()
{

}
