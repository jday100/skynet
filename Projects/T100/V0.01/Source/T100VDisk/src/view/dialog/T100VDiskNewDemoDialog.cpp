#include "../../../include/view/dialog/T100VDiskNewDemoDialog.h"

//(*InternalHeaders(T100VDiskNewDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VDiskNewDemoDialog)
const long T100VDiskNewDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VDiskNewDemoDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100VDiskNewDemoDialog::ID_BUTTON_BROWSE = wxNewId();
const long T100VDiskNewDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VDiskNewDemoDialog::ID_COMBOBOX_LENGTH = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VDiskNewDemoDialog,wxDialog)
	//(*EventTable(T100VDiskNewDemoDialog)
	//*)
END_EVENT_TABLE()

T100VDiskNewDemoDialog::T100VDiskNewDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VDiskNewDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VDiskNewDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("虚拟磁盘："));
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

	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VDiskNewDemoDialog::OnFileComboBoxSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VDiskNewDemoDialog::OnFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VDiskNewDemoDialog::OnFileComboBoxTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VDiskNewDemoDialog::OnBrowseButtonClick);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VDiskNewDemoDialog::OnLengthComboBoxSelected);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VDiskNewDemoDialog::OnLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VDiskNewDemoDialog::OnLengthComboBoxTextEnter);
	//*)
}

T100VDiskNewDemoDialog::~T100VDiskNewDemoDialog()
{
	//(*Destroy(T100VDiskNewDemoDialog)
	//*)
}


void T100VDiskNewDemoDialog::OnFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100VDiskNewDemoDialog::OnFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VDiskNewDemoDialog::OnFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VDiskNewDemoDialog::OnBrowseButtonClick(wxCommandEvent& event)
{
}

void T100VDiskNewDemoDialog::OnLengthComboBoxSelected(wxCommandEvent& event)
{
}

void T100VDiskNewDemoDialog::OnLengthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VDiskNewDemoDialog::OnLengthComboBoxTextEnter(wxCommandEvent& event)
{
}
