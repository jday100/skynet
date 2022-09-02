#include "T100DiskCreateDialog.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/filedlg.h>


const long T100DiskCreateDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskCreateDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100DiskCreateDialog::ID_BUTTON_BROWSE = wxNewId();
const long T100DiskCreateDialog::ID_STATICTEXT2 = wxNewId();
const long T100DiskCreateDialog::ID_COMBOBOX_LENGTH = wxNewId();


BEGIN_EVENT_TABLE(T100DiskCreateDialog,wxDialog)

END_EVENT_TABLE()

T100DiskCreateDialog::T100DiskCreateDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100DiskCreateDialog::~T100DiskCreateDialog()
{
    //dtor
}

void T100DiskCreateDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("新建磁盘文件："));
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FileComboBox = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
	FlexGridSizer1->Add(FileComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BrowseButton = new wxButton(this, ID_BUTTON_BROWSE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_BROWSE"));
	FlexGridSizer1->Add(BrowseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("大小："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LengthComboBox = new wxComboBox(this, ID_COMBOBOX_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_LENGTH"));
	FlexGridSizer1->Add(LengthComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskCreateDialog::OnFileComboBoxSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreateDialog::OnFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreateDialog::OnFileComboBoxTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100DiskCreateDialog::OnBrowseButtonClick);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskCreateDialog::OnLengthComboBoxSelected);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreateDialog::OnLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreateDialog::OnLengthComboBoxTextEnter);


    BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);
}

void T100DiskCreateDialog::OnFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskCreateDialog::OnFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskCreateDialog::OnFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskCreateDialog::OnBrowseButtonClick(wxCommandEvent& event)
{
    wxFileDialog        dialog(this, _T("Create a vdisk file"), "", "", _T("VDisk file (*.vdk) | *.vdk"));

    if(dialog.ShowModal() == wxID_OK){
        FileComboBox->SetValue(dialog.GetFilename());
    }
}

void T100DiskCreateDialog::OnLengthComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskCreateDialog::OnLengthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskCreateDialog::OnLengthComboBoxTextEnter(wxCommandEvent& event)
{
}
