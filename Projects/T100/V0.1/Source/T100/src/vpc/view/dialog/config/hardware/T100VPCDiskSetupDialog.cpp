#include "T100VPCDiskSetupDialog.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/filedlg.h>

#include "T100DiskInfo.h"

namespace T100VPC{
const long T100VPCDiskSetupDialog::ID_STATICTEXT_FILE_NAME = wxNewId();
const long T100VPCDiskSetupDialog::ID_TEXTCTRL_FILE_NAME = wxNewId();
const long T100VPCDiskSetupDialog::ID_STATICTEXT_FILE_PATH = wxNewId();
const long T100VPCDiskSetupDialog::ID_COMBOBOX_FILE_PATH = wxNewId();
const long T100VPCDiskSetupDialog::ID_BUTTON_FILE_BROWSE = wxNewId();
const long T100VPCDiskSetupDialog::ID_STATICTEXT_FILE_LENGTH = wxNewId();
const long T100VPCDiskSetupDialog::ID_COMBOBOX_FILE_LENGTH = wxNewId();


BEGIN_EVENT_TABLE(T100VPCDiskSetupDialog, wxDialog)

END_EVENT_TABLE()

T100VPCDiskSetupDialog::T100VPCDiskSetupDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	//ctor
    BuildContent(parent,id,pos,size);
}

T100VPCDiskSetupDialog::~T100VPCDiskSetupDialog()
{
    //dtor
}

void T100VPCDiskSetupDialog::BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{

	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("文件："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT_FILE_NAME, _("名称："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILE_NAME"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
	FileNameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL_FILE_NAME, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_FILE_NAME"));
	StaticBoxSizer1->Add(FileNameTextCtrl, 0, wxALL|wxALIGN_LEFT, 5);

	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT_FILE_PATH, _("路径："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILE_PATH"));
	StaticBoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
	FilePathComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_PATH, wxEmptyString, wxDefaultPosition, wxSize(300,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_PATH"));
	BoxSizer2->Add(FilePathComboBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FileBrowseButton = new wxButton(this, ID_BUTTON_FILE_BROWSE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FILE_BROWSE"));
	BoxSizer2->Add(FileBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	StaticText3 = new wxStaticText(this, ID_STATICTEXT_FILE_LENGTH, _("大小："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILE_LENGTH"));
	StaticBoxSizer1->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 5);
	FileLengthComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_LENGTH"));
	StaticBoxSizer1->Add(FileLengthComboBox, 0, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);

    BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);

	Connect(ID_TEXTCTRL_FILE_NAME,      wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFileNameTextCtrlText);
	Connect(ID_TEXTCTRL_FILE_NAME,      wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFileNameTextCtrlTextEnter);
	Connect(ID_COMBOBOX_FILE_PATH,      wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFilePathComboBoxSelected);
	Connect(ID_COMBOBOX_FILE_PATH,      wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFilePathComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE_PATH,      wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFilePathComboBoxTextEnter);
	Connect(ID_BUTTON_FILE_BROWSE,      wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFileBrowseButtonClick);
	Connect(ID_COMBOBOX_FILE_LENGTH,    wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFileLengthComboBoxSelected);
	Connect(ID_COMBOBOX_FILE_LENGTH,    wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFileLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE_LENGTH,    wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCDiskSetupDialog::OnFileLengthComboBoxTextEnter);
}

T100VOID T100VPCDiskSetupDialog::setInfo(T100DiskInfo* info)
{
    m_info = info;

    load();
}

T100VOID T100VPCDiskSetupDialog::load()
{
    if(m_info){
        FileNameTextCtrl->SetValue(m_info->m_name.to_wstring());
        FilePathComboBox->SetValue(m_info->m_file.to_wstring());
        FileLengthComboBox->SetValue(std::to_string(m_info->m_length));
    }
}

void T100VPCDiskSetupDialog::OnFileNameTextCtrlText(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_name = FileNameTextCtrl->GetValue().ToStdWstring();
    }
}

void T100VPCDiskSetupDialog::OnFileNameTextCtrlTextEnter(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_name = FileNameTextCtrl->GetValue().ToStdWstring();
    }
}

void T100VPCDiskSetupDialog::OnFilePathComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_file = FilePathComboBox->GetValue().ToStdWstring();
    }
}

void T100VPCDiskSetupDialog::OnFilePathComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_file = FilePathComboBox->GetValue().ToStdWstring();
    }
}

void T100VPCDiskSetupDialog::OnFilePathComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_file = FilePathComboBox->GetValue().ToStdWstring();
    }
}

void T100VPCDiskSetupDialog::OnFileBrowseButtonClick(wxCommandEvent& event)
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return;

    FilePathComboBox->Append(FilePathComboBox->GetValue());
    FilePathComboBox->SetValue(dialog.GetPath());
}

void T100VPCDiskSetupDialog::OnFileLengthComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        length;

        if(FileLengthComboBox->GetValue().ToLongLong(&length)){
            m_info->m_length = length;
        }
    }
}

void T100VPCDiskSetupDialog::OnFileLengthComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        length;

        if(FileLengthComboBox->GetValue().ToLongLong(&length)){
            m_info->m_length = length;
        }
    }
}

void T100VPCDiskSetupDialog::OnFileLengthComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        length;

        if(FileLengthComboBox->GetValue().ToLongLong(&length)){
            m_info->m_length = length;
        }
    }
}


}
