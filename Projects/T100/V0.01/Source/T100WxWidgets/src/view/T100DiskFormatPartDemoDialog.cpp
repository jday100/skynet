#include "../../include/view/T100DiskFormatPartDemoDialog.h"

//(*InternalHeaders(T100DiskFormatPartDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskFormatPartDemoDialog)
const long T100DiskFormatPartDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskFormatPartDemoDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100DiskFormatPartDemoDialog::ID_BUTTON_BROWSE = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DiskFormatPartDemoDialog,wxDialog)
	//(*EventTable(T100DiskFormatPartDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskFormatPartDemoDialog::T100DiskFormatPartDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskFormatPartDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskFormatPartDemoDialog)
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

	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskFormatPartDemoDialog::OnFileComboBoxSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskFormatPartDemoDialog::OnFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskFormatPartDemoDialog::OnFileComboBoxTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100DiskFormatPartDemoDialog::OnBrowseButtonClick);
	//*)
}

T100DiskFormatPartDemoDialog::~T100DiskFormatPartDemoDialog()
{
	//(*Destroy(T100DiskFormatPartDemoDialog)
	//*)
}


void T100DiskFormatPartDemoDialog::OnFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskFormatPartDemoDialog::OnFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskFormatPartDemoDialog::OnFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskFormatPartDemoDialog::OnBrowseButtonClick(wxCommandEvent& event)
{
}
