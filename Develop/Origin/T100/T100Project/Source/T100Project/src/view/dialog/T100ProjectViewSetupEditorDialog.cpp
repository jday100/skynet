#include "T100ProjectViewSetupEditorDialog.h"

#include <wx/fontenum.h>

const long T100ProjectViewSetupEditorDialog::ID_FONT_STATIC_TEXT    = wxNewId();
const long T100ProjectViewSetupEditorDialog::ID_FONT_LIST_BOX   = wxNewId();

BEGIN_EVENT_TABLE(T100ProjectViewSetupEditorDialog, wxDialog)

END_EVENT_TABLE()

T100ProjectViewSetupEditorDialog::T100ProjectViewSetupEditorDialog(wxWindow *parent,
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

T100ProjectViewSetupEditorDialog::~T100ProjectViewSetupEditorDialog()
{
    //dtor
    uninit();
}

T100VOID T100ProjectViewSetupEditorDialog::init()
{
    wxBoxSizer*             sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*       font        = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Font:"));

    m_fontTitle         = T100NEW wxStaticText(this, ID_FONT_STATIC_TEXT, _("Editor's font:"));
    m_font              = T100NEW wxListBox(this,ID_FONT_LIST_BOX);

    wxArrayString       fonts;
    wxFontEnumerator    fontenum;
    wxFontEncoding      encoding        = wxFONTENCODING_DEFAULT;

    fonts = fontenum.GetFacenames(encoding);

    m_font->Append(fonts);

    font->Add(m_fontTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP, 5);
    font->Add(m_font, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(font, 1, wxALL|wxEXPAND, 5);

    sizer->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCANCEL), 0, wxALL | wxALIGN_RIGHT, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

    Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&OnApply);
}

T100VOID T100ProjectViewSetupEditorDialog::uninit()
{

}

T100VOID T100ProjectViewSetupEditorDialog::OnApply(wxCommandEvent& event)
{
    Close();
    SetReturnCode(wxID_APPLY);
}
