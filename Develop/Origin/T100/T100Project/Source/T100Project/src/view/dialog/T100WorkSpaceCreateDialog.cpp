#include "T100WorkSpaceCreateDialog.h"

const long T100WorkSpaceCreateDialog::ID_STATIC_TEXT    = wxNewId();
const long T100WorkSpaceCreateDialog::ID_WORKSPACE_DIR  = wxNewId();

T100WorkSpaceCreateDialog::T100WorkSpaceCreateDialog(wxWindow *parent,
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

T100WorkSpaceCreateDialog::~T100WorkSpaceCreateDialog()
{
    //dtor
    uninit();
}

T100VOID T100WorkSpaceCreateDialog::init()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*       workspace  = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("WorkSpace:"));

    m_title     = T100NEW wxStaticText(this, ID_STATIC_TEXT, _("Path:"));
    m_dir       = T100NEW wxDirPickerCtrl(this, ID_WORKSPACE_DIR);

    workspace->Add(m_title, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    workspace->Add(m_dir, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(workspace, 1, wxALL|wxEXPAND, 5);

    sizer->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCANCEL));

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

}

T100VOID T100WorkSpaceCreateDialog::uninit()
{

}
