#include "../../include/view/T100DiskFormatPartDemoDialog.h"

//(*InternalHeaders(T100DiskFormatPartDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskFormatPartDemoDialog)
const long T100DiskFormatPartDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskFormatPartDemoDialog::ID_COMBOBOX1 = wxNewId();
const long T100DiskFormatPartDemoDialog::ID_BUTTON1 = wxNewId();
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
	wxGridBagSizer* GridBagSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	GridBagSizer1->Add(ComboBox1, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	GridBagSizer1->Add(Button1, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100DiskFormatPartDemoDialog::~T100DiskFormatPartDemoDialog()
{
	//(*Destroy(T100DiskFormatPartDemoDialog)
	//*)
}

