#include "T100WorkSpaceCreateDialog.h"

#include "T100ProjectConfig.h"

const long T100WorkSpaceCreateDialog::ID_WORKSPACE_STATIC_TEXT      = wxNewId();
const long T100WorkSpaceCreateDialog::ID_WORKSPACE_PATH     = wxNewId();
const long T100WorkSpaceCreateDialog::ID_PYTHON_STATIC_TEXT     = wxNewId();
const long T100WorkSpaceCreateDialog::ID_PYTHON_FILE    = wxNewId();
const long T100WorkSpaceCreateDialog::ID_COMPILER_STATIC_TEXT   = wxNewId();
const long T100WorkSpaceCreateDialog::ID_COMPILER_PATH  = wxNewId();

BEGIN_EVENT_TABLE(T100WorkSpaceCreateDialog, wxDialog)

END_EVENT_TABLE()

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

    wxStaticBoxSizer*       workspace   = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("WorkSpace:"));

    m_workspaceTitle        = T100NEW wxStaticText(this, ID_WORKSPACE_STATIC_TEXT, _("Path:"));
    m_workspacePathPicker   = T100NEW wxDirPickerCtrl(this, ID_WORKSPACE_PATH);

    m_workspaceTitle->SetSize(-1, 50);

    workspace->Add(m_workspaceTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    workspace->Add(m_workspacePathPicker, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    m_workspaceTitle->SetSize(-1, 50);
    m_workspacePathPicker->SetSize(-1, 250);
    sizer->Add(workspace, 1, wxALL|wxEXPAND, 5);

    wxStaticBoxSizer*       compiler    = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("GCC:"));

    m_compilerTitle         = T100NEW wxStaticText(this, ID_COMPILER_STATIC_TEXT, _("Path:"));
    m_compilerPathPicker    = T100NEW wxDirPickerCtrl(this, ID_COMPILER_PATH);

    m_compilerTitle->SetSize(-1, 50);

    compiler->Add(m_compilerTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    compiler->Add(m_compilerPathPicker, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    m_compilerTitle->SetSize(-1, 50);
    m_compilerPathPicker->SetSize(-1, 250);
    sizer->Add(compiler, 1, wxALL|wxEXPAND, 5);

    wxStaticBoxSizer*       python      = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Python:"));

    m_pythonTitle           = T100NEW wxStaticText(this, ID_PYTHON_STATIC_TEXT, _("File:"));
    m_pythonFilePicker      = T100NEW wxFilePickerCtrl(this, ID_PYTHON_FILE);

    m_pythonTitle->SetSize(-1, 50);

    python->Add(m_pythonTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    python->Add(m_pythonFilePicker, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    m_pythonTitle->SetSize(-1, 50);
    m_pythonFilePicker->SetSize(-1, 250);
    sizer->Add(python, 1, wxALL|wxEXPAND, 5);

    sizer->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCANCEL), 0, wxALL | wxALIGN_RIGHT, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

    SetSize(600, -1);
    Center();

    Connect(wxID_APPLY, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&OnApply);
}

T100VOID T100WorkSpaceCreateDialog::uninit()
{

}

T100VOID T100WorkSpaceCreateDialog::SetWorkSpacePath(const T100WSTRING& path)
{
    m_workspacePath     = path;
}

const T100WSTRING& T100WorkSpaceCreateDialog::GetWorkSpacePath()
{
    return m_workspacePath;
}

T100VOID T100WorkSpaceCreateDialog::SetPythonFile(const T100WSTRING& file)
{
    m_pythonFile        = file;
}

const T100WSTRING& T100WorkSpaceCreateDialog::GetPythonFile()
{
    return m_pythonFile;
}

T100VOID T100WorkSpaceCreateDialog::SetCompilerPath(const T100WSTRING& path)
{
    m_compilerPath      = path;
}

const T100WSTRING& T100WorkSpaceCreateDialog::GetCompilerPath()
{
    return m_compilerPath;
}

T100VOID T100WorkSpaceCreateDialog::OnApply(wxCommandEvent& event)
{
    m_workspacePath     = m_workspacePathPicker->GetPath().ToStdWstring();
    m_pythonFile        = m_pythonFilePicker->GetPath().ToStdWstring();
    m_compilerPath      = m_compilerPathPicker->GetPath().ToStdWstring();

    Close();
    SetReturnCode(wxID_APPLY);
}
