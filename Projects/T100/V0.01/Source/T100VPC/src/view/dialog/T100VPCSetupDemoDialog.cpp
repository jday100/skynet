#include "../../../include/view/dialog/T100VPCSetupDemoDialog.h"

//(*InternalHeaders(T100VPCSetupDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCSetupDemoDialog)
const long T100VPCSetupDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX1 = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON1 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX2 = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON2 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT3 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX3 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT4 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT5 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX4 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX5 = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON3 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT6 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX6 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT7 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX7 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT8 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX8 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT9 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX9 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCSetupDemoDialog,wxDialog)
	//(*EventTable(T100VPCSetupDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCSetupDemoDialog::T100VPCSetupDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCSetupDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCSetupDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxGridBagSizer* GridBagSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer6;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("字体："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	StaticBoxSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer1->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("虚拟磁盘："));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	StaticBoxSizer2->Add(ComboBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticBoxSizer2->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("内存："));
	StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, this, _("ROM："));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("BASE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox3 = new wxComboBox(this, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	GridBagSizer1->Add(ComboBox3, wxGBPosition(0, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("SIZE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer1->Add(StaticText5, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox4 = new wxComboBox(this, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	GridBagSizer1->Add(ComboBox4, wxGBPosition(1, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox5 = new wxComboBox(this, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	GridBagSizer1->Add(ComboBox5, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	GridBagSizer1->Add(Button3, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("RAM："));
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("BASE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox6 = new wxComboBox(this, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
	FlexGridSizer2->Add(ComboBox6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("SIZE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox7 = new wxComboBox(this, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
	FlexGridSizer2->Add(ComboBox7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6->Add(FlexGridSizer2, 1, wxALL|wxALIGN_TOP, 5);
	StaticBoxSizer3->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("屏幕："));
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("宽度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer3->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox8 = new wxComboBox(this, ID_COMBOBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX8"));
	FlexGridSizer3->Add(ComboBox8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("高度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer3->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox9 = new wxComboBox(this, ID_COMBOBOX9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX9"));
	FlexGridSizer3->Add(ComboBox9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer4, 0, wxALL|wxALIGN_LEFT, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100VPCSetupDemoDialog::~T100VPCSetupDemoDialog()
{
	//(*Destroy(T100VPCSetupDemoDialog)
	//*)
}

