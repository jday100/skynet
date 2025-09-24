#include "T100PythonPanel.h"

const long T100PythonPanel::ID_PYTHON_FILE_TITLE    = wxNewId();
const long T100PythonPanel::ID_PYTHON_FILE_PICKER   = wxNewId();

T100PythonPanel::T100PythonPanel(wxWindow *parent,
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

T100PythonPanel::~T100PythonPanel()
{
    //dtor
    uninit();
}

T100VOID T100PythonPanel::init()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*       python      = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Python:"));

    m_pythonTitle           = T100NEW wxStaticText(this, ID_PYTHON_FILE_TITLE, _("File:"), wxDefaultPosition, wxSize(30, -1));
    m_pythonFile            = T100NEW wxFilePickerCtrl(this, ID_PYTHON_FILE_PICKER);

    python->Add(m_pythonTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    python->Add(m_pythonFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(python, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100PythonPanel::uninit()
{

}

const T100WSTRING T100PythonPanel::GetPath()
{
    return m_pythonFile->GetPath().ToStdWstring();
}
