#include "../../include/view/T100DiskCreateDemoDialog.h"

//(*InternalHeaders(T100DiskCreateDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskCreateDemoDialog)
const long T100DiskCreateDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskCreateDemoDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100DiskCreateDemoDialog::ID_BUTTON_BROWSE = wxNewId();
const long T100DiskCreateDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100DiskCreateDemoDialog::ID_COMBOBOX_LENGTH = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DiskCreateDemoDialog,wxDialog)
	//(*EventTable(T100DiskCreateDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskCreateDemoDialog::T100DiskCreateDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskCreateDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskCreateDemoDialog)
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
	FileComboBox = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxDefaultPosition, wxSize(300,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
	FlexGridSizer1->Add(FileComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BrowseButton = new wxButton(this, ID_BUTTON_BROWSE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_BROWSE"));
	FlexGridSizer1->Add(BrowseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("大小："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LengthComboBox = new wxComboBox(this, ID_COMBOBOX_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_LENGTH"));
	FlexGridSizer1->Add(LengthComboBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskCreateDemoDialog::OnFileComboBoxSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreateDemoDialog::OnFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreateDemoDialog::OnFileComboBoxTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100DiskCreateDemoDialog::OnBrowseButtonClick);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskCreateDemoDialog::OnLengthComboBoxSelected);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreateDemoDialog::OnLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreateDemoDialog::OnLengthComboBoxTextEnter);
	//*)
}

T100DiskCreateDemoDialog::~T100DiskCreateDemoDialog()
{
	//(*Destroy(T100DiskCreateDemoDialog)
	//*)
}


void T100DiskCreateDemoDialog::OnFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskCreateDemoDialog::OnFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskCreateDemoDialog::OnFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskCreateDemoDialog::OnBrowseButtonClick(wxCommandEvent& event)
{
}

void T100DiskCreateDemoDialog::OnLengthComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskCreateDemoDialog::OnLengthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskCreateDemoDialog::OnLengthComboBoxTextEnter(wxCommandEvent& event)
{
}
