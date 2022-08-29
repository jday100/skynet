#include "../../include/view/T100DiskCreatePartDemoDialog.h"

//(*InternalHeaders(T100DiskCreatePartDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskCreatePartDemoDialog)
const long T100DiskCreatePartDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_TEXTCTRL1 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_COMBOBOX1 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_CHECKBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DiskCreatePartDemoDialog,wxDialog)
	//(*EventTable(T100DiskCreatePartDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskCreatePartDemoDialog::T100DiskCreatePartDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskCreatePartDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskCreatePartDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxGridBagSizer* GridBagSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	GridBagSizer1->Add(TextCtrl1, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	GridBagSizer1->Add(ComboBox1, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	GridBagSizer1->Add(CheckBox1, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100DiskCreatePartDemoDialog::~T100DiskCreatePartDemoDialog()
{
	//(*Destroy(T100DiskCreatePartDemoDialog)
	//*)
}

