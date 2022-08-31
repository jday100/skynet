#include "../../../include/view/dialog/T100VPCSetupDemoDialog.h"

//(*InternalHeaders(T100VPCSetupDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCSetupDemoDialog)
const long T100VPCSetupDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_FONT_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON_FONT_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_VDISK_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON_VDISK_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT3 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_ROM_BASE = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT4 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT5 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_ROM_SIZE = wxNewId();
const long T100VPCSetupDemoDialog::ID_CHECKBOX_ROM = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_ROM_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON_ROM_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT6 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_RAM_BASE = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT7 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_RAM_SIZE = wxNewId();
const long T100VPCSetupDemoDialog::ID_LISTVIEW_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT10 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON4 = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT11 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_LOCATION = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT12 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_LENGTH = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCSetupDemoDialog::ID_BUTTON_REMOVE = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT8 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_SCREEN_WIDTH = wxNewId();
const long T100VPCSetupDemoDialog::ID_STATICTEXT9 = wxNewId();
const long T100VPCSetupDemoDialog::ID_COMBOBOX_SCREEN_HEIGHT = wxNewId();
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
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxGridBagSizer* GridBagSizer1;
	wxGridBagSizer* GridBagSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxStaticBoxSizer* StaticBoxSizer7;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("字体："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FontFileComboBox = new wxComboBox(this, ID_COMBOBOX_FONT_FILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FONT_FILE"));
	StaticBoxSizer1->Add(FontFileComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FontFileButton = new wxButton(this, ID_BUTTON_FONT_FILE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FONT_FILE"));
	StaticBoxSizer1->Add(FontFileButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("虚拟磁盘："));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VDiskFileComboBox = new wxComboBox(this, ID_COMBOBOX_VDISK_FILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_VDISK_FILE"));
	StaticBoxSizer2->Add(VDiskFileComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VDiskFileButton = new wxButton(this, ID_BUTTON_VDISK_FILE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_VDISK_FILE"));
	StaticBoxSizer2->Add(VDiskFileButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, this, _("内存："));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, this, _("ROM："));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("BASE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ROMBaseComboBox = new wxComboBox(this, ID_COMBOBOX_ROM_BASE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ROM_BASE"));
	GridBagSizer1->Add(ROMBaseComboBox, wxGBPosition(0, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("SIZE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer1->Add(StaticText5, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ROMSizeComboBox = new wxComboBox(this, ID_COMBOBOX_ROM_SIZE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ROM_SIZE"));
	GridBagSizer1->Add(ROMSizeComboBox, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ROMCheckBox = new wxCheckBox(this, ID_CHECKBOX_ROM, _("加载ROM"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_ROM"));
	ROMCheckBox->SetValue(false);
	GridBagSizer1->Add(ROMCheckBox, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ROMFileComboBox = new wxComboBox(this, ID_COMBOBOX_ROM_FILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ROM_FILE"));
	GridBagSizer1->Add(ROMFileComboBox, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ROMFileButton = new wxButton(this, ID_BUTTON_ROM_FILE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ROM_FILE"));
	GridBagSizer1->Add(ROMFileButton, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("RAM："));
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("BASE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RAMBaseComboBox = new wxComboBox(this, ID_COMBOBOX_RAM_BASE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_RAM_BASE"));
	FlexGridSizer2->Add(RAMBaseComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("SIZE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RAMSizeComboBox = new wxComboBox(this, ID_COMBOBOX_RAM_SIZE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_RAM_SIZE"));
	FlexGridSizer2->Add(RAMSizeComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6->Add(FlexGridSizer2, 1, wxALL|wxALIGN_TOP, 5);
	BoxSizer3->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("加载："));
	GridBagSizer2 = new wxGridBagSizer(0, 0);
	FileListView = new wxListView(this, ID_LISTVIEW_FILE, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW_FILE"));
	GridBagSizer2->Add(FileListView, wxGBPosition(0, 0), wxGBSpan(4, 2), wxALL|wxEXPAND, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	GridBagSizer2->Add(StaticText10, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FileComboBox = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
	GridBagSizer2->Add(FileComboBox, wxGBPosition(0, 3), wxGBSpan(1, 2), wxALL|wxEXPAND, 5);
	FileButton = new wxButton(this, ID_BUTTON4, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	GridBagSizer2->Add(FileButton, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("定位："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	GridBagSizer2->Add(StaticText11, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LocationComboBox = new wxComboBox(this, ID_COMBOBOX_LOCATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_LOCATION"));
	GridBagSizer2->Add(LocationComboBox, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("长度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	GridBagSizer2->Add(StaticText12, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LengthComboBox = new wxComboBox(this, ID_COMBOBOX_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_LENGTH"));
	GridBagSizer2->Add(LengthComboBox, wxGBPosition(1, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	GridBagSizer2->Add(AppendButton, wxGBPosition(3, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RemoveButton = new wxButton(this, ID_BUTTON_REMOVE, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	GridBagSizer2->Add(RemoveButton, wxGBPosition(3, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7->Add(GridBagSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("屏幕："));
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("宽度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer3->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ScreenWidthComboBox = new wxComboBox(this, ID_COMBOBOX_SCREEN_WIDTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_SCREEN_WIDTH"));
	FlexGridSizer3->Add(ScreenWidthComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("高度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer3->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ScreenHeightComboBox = new wxComboBox(this, ID_COMBOBOX_SCREEN_HEIGHT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_SCREEN_HEIGHT"));
	FlexGridSizer3->Add(ScreenHeightComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer4, 0, wxALL|wxALIGN_LEFT, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_FONT_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFontFileComboBoxSelected);
	Connect(ID_COMBOBOX_FONT_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFontFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FONT_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFontFileComboBoxTextEnter);
	Connect(ID_BUTTON_FONT_FILE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFontFileButtonClick);
	Connect(ID_COMBOBOX_VDISK_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnVDiskFileComboBoxSelected);
	Connect(ID_COMBOBOX_VDISK_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnVDiskFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_VDISK_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnVDiskFileComboBoxTextEnter);
	Connect(ID_BUTTON_VDISK_FILE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnVDiskFileButtonClick);
	Connect(ID_COMBOBOX_ROM_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMBaseComboBoxSelected);
	Connect(ID_COMBOBOX_ROM_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMBaseComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ROM_BASE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMBaseComboBoxTextEnter);
	Connect(ID_COMBOBOX_ROM_SIZE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMSizeComboBoxSelected);
	Connect(ID_COMBOBOX_ROM_SIZE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ROM_SIZE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMSizeComboBoxTextEnter);
	Connect(ID_CHECKBOX_ROM,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMCheckBoxClick);
	Connect(ID_COMBOBOX_ROM_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMFileComboBoxSelected);
	Connect(ID_COMBOBOX_ROM_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ROM_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMFileComboBoxTextEnter);
	Connect(ID_BUTTON_ROM_FILE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnROMFileButtonClick);
	Connect(ID_COMBOBOX_RAM_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnRAMBaseComboBoxSelected);
	Connect(ID_COMBOBOX_RAM_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnRAMBaseComboBoxTextUpdated);
	Connect(ID_COMBOBOX_RAM_BASE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnRAMBaseComboBoxTextEnter);
	Connect(ID_COMBOBOX_RAM_SIZE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnRAMSizeComboBoxSelected);
	Connect(ID_COMBOBOX_RAM_SIZE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnRAMSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_RAM_SIZE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnRAMSizeComboBoxTextEnter);
	Connect(ID_LISTVIEW_FILE,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFileListViewItemSelect);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFileComboBoxSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFileComboBoxTextEnter);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnFileButtonClick);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnLocationComboBoxSelected);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnLocationComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnLocationComboBoxTextEnter);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnLengthComboBoxSelected);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnLengthComboBoxTextEnter);
	Connect(ID_COMBOBOX_SCREEN_WIDTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnScreenWidthComboBoxSelected);
	Connect(ID_COMBOBOX_SCREEN_WIDTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnScreenWidthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_SCREEN_WIDTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnScreenWidthComboBoxTextEnter);
	Connect(ID_COMBOBOX_SCREEN_HEIGHT,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnScreenHeightComboBoxSelected);
	Connect(ID_COMBOBOX_SCREEN_HEIGHT,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnScreenHeightComboBoxTextUpdated);
	Connect(ID_COMBOBOX_SCREEN_HEIGHT,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCSetupDemoDialog::OnScreenHeightComboBoxTextEnter);
	//*)
}

T100VPCSetupDemoDialog::~T100VPCSetupDemoDialog()
{
	//(*Destroy(T100VPCSetupDemoDialog)
	//*)
}


void T100VPCSetupDemoDialog::OnFontFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFontFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFontFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFontFileButtonClick(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnVDiskFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnVDiskFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnVDiskFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnVDiskFileButtonClick(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMBaseComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMBaseComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMBaseComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMSizeComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMSizeComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMSizeComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMFileButtonClick(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnRAMBaseComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnRAMBaseComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnRAMBaseComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnRAMSizeComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnRAMSizeComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnRAMSizeComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFileListViewItemSelect(wxListEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnFileButtonClick(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnLocationComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnLocationComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnLocationComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnLengthComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnLengthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnLengthComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnScreenWidthComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnScreenWidthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnScreenWidthComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnScreenHeightComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnScreenHeightComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnScreenHeightComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCSetupDemoDialog::OnROMCheckBoxClick(wxCommandEvent& event)
{
}
