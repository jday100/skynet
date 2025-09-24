#include "T100CompilerPanel.h"

const long T100CompilerPanel::ID_COMPILER_PATH_TITLE    = wxNewId();
const long T100CompilerPanel::ID_COMPILER_PATH_PICKER   = wxNewId();

T100CompilerPanel::T100CompilerPanel(wxWindow *parent,
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

T100CompilerPanel::~T100CompilerPanel()
{
    //dtor
    uninit();
}

T100VOID T100CompilerPanel::init()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*       compiler    = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Compiler:"));

    m_compilerTitle         = T100NEW wxStaticText(this, ID_COMPILER_PATH_TITLE, _("Path:"), wxDefaultPosition, wxSize(30, -1));
    m_compilerPath          = T100NEW wxDirPickerCtrl(this, ID_COMPILER_PATH_PICKER);

    compiler->Add(m_compilerTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    compiler->Add(m_compilerPath, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(compiler, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100CompilerPanel::uninit()
{

}

const T100WSTRING T100CompilerPanel::GetPath()
{
    return m_compilerPath->GetPath().ToStdWstring();
}
