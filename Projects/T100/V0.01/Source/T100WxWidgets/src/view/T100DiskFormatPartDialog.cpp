#include "T100DiskFormatPartDialog.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/filedlg.h>

const long T100DiskFormatPartDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskFormatPartDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100DiskFormatPartDialog::ID_BUTTON_BROWSE = wxNewId();

BEGIN_EVENT_TABLE(T100DiskFormatPartDialog,wxDialog)

END_EVENT_TABLE()

T100DiskFormatPartDialog::T100DiskFormatPartDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
	BuildContent(parent,id,pos,size);

}

T100DiskFormatPartDialog::~T100DiskFormatPartDialog()
{
    //dtor
}

void T100DiskFormatPartDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("格式化分区："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("引导文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FileComboBox = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
	StaticBoxSizer1->Add(FileComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BrowseButton = new wxButton(this, ID_BUTTON_BROWSE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_BROWSE"));
	StaticBoxSizer1->Add(BrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskFormatPartDialog::OnFileComboBoxSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskFormatPartDialog::OnFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskFormatPartDialog::OnFileComboBoxTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100DiskFormatPartDialog::OnBrowseButtonClick);

	BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);
}

void T100DiskFormatPartDialog::OnFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskFormatPartDialog::OnFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskFormatPartDialog::OnFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskFormatPartDialog::OnBrowseButtonClick(wxCommandEvent& event)
{
    wxFileDialog        dialog(this, _T("Select a boot file"), "", "", _T("Boot file (*.bin) | *.bin"), wxFD_FILE_MUST_EXIST);

    if(dialog.ShowModal() == wxID_OK){
        FileComboBox->SetValue(dialog.GetFilename());
    }
}
