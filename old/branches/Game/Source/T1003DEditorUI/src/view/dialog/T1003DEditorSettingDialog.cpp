#include "../../../include/view/dialog/T1003DEditorSettingDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

#include <wx/listctrl.h>

#include "T1003DEditorSettingsDescriptionPanel.h"
#include "T1003DEditorSettingsDescriptionReferencePanel.h"
#include "T1003DEditorSettingsParameterPanel.h"
#include "T1003DEditorSettingsParameterReferencePanel.h"
#include "T1003DEditorSettingsPipelineStateSettingPanel.h"
#include "T1003DEditorSettingsVertexShaderPanel.h"
#include "T1003DEditorSettingsPixelShaderPanel.h"
#include "T1003DEditorSettingsShaderReferencePanel.h"

const long T1003DEditorSettingDialog::ID_PANEL3 = wxNewId();

const long T1003DEditorSettingDialog::ID_LISTBOOK1 = wxNewId();

BEGIN_EVENT_TABLE(T1003DEditorSettingDialog,wxDialog)

END_EVENT_TABLE()

T1003DEditorSettingDialog::T1003DEditorSettingDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T1003DEditorSettingDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, id, wxT("Settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(1280,700));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Listbook1 = new wxListbook(this, ID_LISTBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_LISTBOOK1"));


	BoxSizer1->Add(Listbook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	Layout();
	Center();

	init();
}

T1003DEditorSettingDialog::~T1003DEditorSettingDialog()
{

	uninit();
}

T100VOID T1003DEditorSettingDialog::init()
{
    Listbook1->GetListView()->SetColumnWidth(0, 200);

    T1003DEditorSettingsDescriptionPanel*                       descPanel                   = T100NEW T1003DEditorSettingsDescriptionPanel(Listbook1);
    T1003DEditorSettingsDescriptionReferencePanel*              descReferencePanel          = T100NEW T1003DEditorSettingsDescriptionReferencePanel(Listbook1);
    T1003DEditorSettingsParameterPanel*                         paraPanel                   = T100NEW T1003DEditorSettingsParameterPanel(Listbook1);
    T1003DEditorSettingsParameterReferencePanel*                paraReferencePanel          = T100NEW T1003DEditorSettingsParameterReferencePanel(Listbook1);
    T1003DEditorSettingsPipelineStateSettingPanel*              settingPanel                = T100NEW T1003DEditorSettingsPipelineStateSettingPanel(Listbook1);
    T1003DEditorSettingsVertexShaderPanel*                      vertexPanel                 = T100NEW T1003DEditorSettingsVertexShaderPanel(Listbook1);
    T1003DEditorSettingsPixelShaderPanel*                       pixelPanel                  = T100NEW T1003DEditorSettingsPixelShaderPanel(Listbook1);
    T1003DEditorSettingsShaderReferencePanel*                   shaderPanel                 = T100NEW T1003DEditorSettingsShaderReferencePanel(Listbook1);

    Listbook1->AddPage(descPanel, _("Description"), false);
    Listbook1->AddPage(descReferencePanel, _("DescriptionReference"), false);
    Listbook1->AddPage(paraPanel, _("Parameter"), false);
    Listbook1->AddPage(paraReferencePanel, _("ParameterReference"), false);
    Listbook1->AddPage(settingPanel, _("Setting"), false);
    Listbook1->AddPage(vertexPanel, _("VertexShader"), false);
    Listbook1->AddPage(pixelPanel, _("PixelShader"), false);
    Listbook1->AddPage(shaderPanel, _("ShaderReference"), false);
}

T100VOID T1003DEditorSettingDialog::uninit()
{
    T100SAFE_DELETE m_gridPtr;
}
