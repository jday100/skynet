#include "T100VPCDisplaySetupDialog.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/filedlg.h>

#include "T100DisplayInfo.h"

namespace T100VPC{

const long T100VPCDisplaySetupDialog::ID_STATICTEXT_SCREEN_WIDTH = wxNewId();
const long T100VPCDisplaySetupDialog::ID_STATICTEXT_SCREEN_HEIGHT = wxNewId();
const long T100VPCDisplaySetupDialog::ID_STATICTEXT_FONT_FILE = wxNewId();
const long T100VPCDisplaySetupDialog::ID_COMBOBOX_SCREEN_WIDTH = wxNewId();
const long T100VPCDisplaySetupDialog::ID_COMBOBOX_SCREEN_HEIGHT = wxNewId();
const long T100VPCDisplaySetupDialog::ID_COMBOBOX_FONT_FILE = wxNewId();
const long T100VPCDisplaySetupDialog::ID_BUTTON_FILE_BROWSE = wxNewId();

BEGIN_EVENT_TABLE(T100VPCDisplaySetupDialog, wxDialog)

END_EVENT_TABLE()

T100VPCDisplaySetupDialog::T100VPCDisplaySetupDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100VPCDisplaySetupDialog::~T100VPCDisplaySetupDialog()
{
    //dtor
}

void T100VPCDisplaySetupDialog::BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{

	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);

	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("屏幕："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT_SCREEN_WIDTH, _("宽度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_SCREEN_WIDTH"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
	ScreenWidthComboBox = new wxComboBox(this, ID_COMBOBOX_SCREEN_WIDTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_SCREEN_WIDTH"));
	StaticBoxSizer1->Add(ScreenWidthComboBox, 1, wxALL|wxALIGN_LEFT, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT_SCREEN_HEIGHT, _("高度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_SCREEN_HEIGHT"));
	StaticBoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
	ScreenHeightComboBox = new wxComboBox(this, ID_COMBOBOX_SCREEN_HEIGHT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_SCREEN_HEIGHT"));
	StaticBoxSizer1->Add(ScreenHeightComboBox, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);

    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("字体："));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT_FONT_FILE, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FONT_FILE"));
	StaticBoxSizer2->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 5);
	FontFileComboBox = new wxComboBox(this, ID_COMBOBOX_FONT_FILE, wxEmptyString, wxDefaultPosition, wxSize(300, -1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FONT_FILE"));
	BoxSizer2->Add(FontFileComboBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FileBrowseButton = new wxButton(this, ID_BUTTON_FILE_BROWSE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FILE_BROWSE"));
	BoxSizer2->Add(FileBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 5);

    BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);

	Connect(ID_COMBOBOX_SCREEN_WIDTH,       wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnScreenWidthComboBoxSelected);
	Connect(ID_COMBOBOX_SCREEN_WIDTH,       wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnScreenWidthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_SCREEN_WIDTH,       wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnScreenWidthComboBoxTextEnter);
	Connect(ID_COMBOBOX_SCREEN_HEIGHT,      wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnScreenHeightComboBoxSelected);
	Connect(ID_COMBOBOX_SCREEN_HEIGHT,      wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnScreenHeightComboBoxTextUpdated);
	Connect(ID_COMBOBOX_SCREEN_HEIGHT,      wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnScreenHeightComboBoxTextEnter);
	Connect(ID_COMBOBOX_FONT_FILE,          wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnFontFileComboBoxSelected);
	Connect(ID_COMBOBOX_FONT_FILE,          wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnFontFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FONT_FILE,          wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnFontFileComboBoxTextEnter);
    Connect(ID_BUTTON_FILE_BROWSE,          wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T100VPCDisplaySetupDialog::OnFileBrowseButtonClick);
}

T100VOID T100VPCDisplaySetupDialog::setInfo(T100DisplayInfo* info)
{
    m_info = info;

    load();
}

T100VOID T100VPCDisplaySetupDialog::load()
{
    if(m_info){
        ScreenWidthComboBox->SetValue(std::to_string(m_info->m_width));
        ScreenHeightComboBox->SetValue(std::to_string(m_info->m_height));
        FontFileComboBox->SetValue(m_info->m_font.to_wstring());
    }
}

void T100VPCDisplaySetupDialog::OnScreenWidthComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(ScreenWidthComboBox->GetValue().ToLongLong(&value)){
            m_info->m_width = value;
        }
    }
}

void T100VPCDisplaySetupDialog::OnScreenWidthComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(ScreenWidthComboBox->GetValue().ToLongLong(&value)){
            m_info->m_width = value;
        }
    }
}

void T100VPCDisplaySetupDialog::OnScreenWidthComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(ScreenWidthComboBox->GetValue().ToLongLong(&value)){
            m_info->m_width = value;
        }
    }
}

void T100VPCDisplaySetupDialog::OnScreenHeightComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(ScreenHeightComboBox->GetValue().ToLongLong(&value)){
            m_info->m_height = value;
        }
    }
}

void T100VPCDisplaySetupDialog::OnScreenHeightComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(ScreenHeightComboBox->GetValue().ToLongLong(&value)){
            m_info->m_height = value;
        }
    }
}

void T100VPCDisplaySetupDialog::OnScreenHeightComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(ScreenHeightComboBox->GetValue().ToLongLong(&value)){
            m_info->m_height = value;
        }
    }
}

void T100VPCDisplaySetupDialog::OnFontFileComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_font = FontFileComboBox->GetValue().ToStdWstring();
    }
}

void T100VPCDisplaySetupDialog::OnFontFileComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_font = FontFileComboBox->GetValue().ToStdWstring();
    }
}

void T100VPCDisplaySetupDialog::OnFontFileComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        m_info->m_font = FontFileComboBox->GetValue().ToStdWstring();
    }
}

void T100VPCDisplaySetupDialog::OnFileBrowseButtonClick(wxCommandEvent& event)
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return;

    FontFileComboBox->Append(FontFileComboBox->GetValue());
    FontFileComboBox->SetValue(dialog.GetPath());
}

}
