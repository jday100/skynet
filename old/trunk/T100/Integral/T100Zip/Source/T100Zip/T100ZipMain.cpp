/***************************************************************
 * Name:      T100ZipMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-09-29
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ZipMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100ZipDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100Zip.h"
#include "T100Unzip.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(T100ZipDialog)
const long T100ZipDialog::ID_STATICTEXT1 = wxNewId();
const long T100ZipDialog::ID_FILEPICKERCTRL1 = wxNewId();
const long T100ZipDialog::ID_STATICTEXT2 = wxNewId();
const long T100ZipDialog::ID_DIRPICKERCTRL1 = wxNewId();
const long T100ZipDialog::ID_BUTTON1 = wxNewId();
const long T100ZipDialog::ID_BUTTON2 = wxNewId();
const long T100ZipDialog::ID_PANEL1 = wxNewId();
const long T100ZipDialog::ID_STATICTEXT3 = wxNewId();
const long T100ZipDialog::ID_FILEPICKERCTRL2 = wxNewId();
const long T100ZipDialog::ID_STATICTEXT4 = wxNewId();
const long T100ZipDialog::ID_FILEPICKERCTRL3 = wxNewId();
const long T100ZipDialog::ID_BUTTON3 = wxNewId();
const long T100ZipDialog::ID_BUTTON4 = wxNewId();
const long T100ZipDialog::ID_PANEL2 = wxNewId();
const long T100ZipDialog::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100ZipDialog,wxDialog)
    //(*EventTable(T100ZipDialog)
    //*)
END_EVENT_TABLE()

T100ZipDialog::T100ZipDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100ZipDialog)
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer9;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;

    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Unzip:"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("File:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FilePickerCtrl1 = new wxFilePickerCtrl(Panel1, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    BoxSizer3->Add(FilePickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Folder:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT2"));
    BoxSizer4->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DirPickerCtrl1 = new wxDirPickerCtrl(Panel1, ID_DIRPICKERCTRL1, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_DIRPICKERCTRL1"));
    BoxSizer4->Add(DirPickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Unzip"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer8->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer8->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer8, 0, wxALL|wxALIGN_RIGHT, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Zip:"));
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Source:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT3"));
    BoxSizer6->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FilePickerCtrl2 = new wxFilePickerCtrl(Panel2, ID_FILEPICKERCTRL2, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
    BoxSizer6->Add(FilePickerCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("File:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT4"));
    BoxSizer7->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FilePickerCtrl3 = new wxFilePickerCtrl(Panel2, ID_FILEPICKERCTRL3, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL3"));
    BoxSizer7->Add(FilePickerCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    Button3 = new wxButton(Panel2, ID_BUTTON3, _("Zip"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer9->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(Panel2, ID_BUTTON4, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer9->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer9, 0, wxALL|wxALIGN_RIGHT, 5);
    Panel2->SetSizer(BoxSizer5);
    BoxSizer5->Fit(Panel2);
    BoxSizer5->SetSizeHints(Panel2);
    Notebook1->AddPage(Panel1, _("Unzip"), false);
    Notebook1->AddPage(Panel2, _("Zip"), false);
    BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100ZipDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100ZipDialog::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100ZipDialog::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100ZipDialog::OnButton4Click);
    //*)
}

T100ZipDialog::~T100ZipDialog()
{
    //(*Destroy(T100ZipDialog)
    //*)
}

void T100ZipDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100ZipDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100ZipDialog::OnButton1Click(wxCommandEvent& event)
{
    T100Unzip       unzip;

    if(unzip.Uncompress(FilePickerCtrl1->GetPath(), DirPickerCtrl1->GetPath())){
        wxMessageBox(L"Unzip Success!");
    }
}

void T100ZipDialog::OnButton2Click(wxCommandEvent& event)
{
    Close();
}

void T100ZipDialog::OnButton3Click(wxCommandEvent& event)
{
    T100Zip         zip;

    wxArrayString   source;

    if(zip.Compress(source, FilePickerCtrl3->GetPath())){
        wxMessageBox(L"Zip Success!");
    }
}

void T100ZipDialog::OnButton4Click(wxCommandEvent& event)
{
    Close();
}
