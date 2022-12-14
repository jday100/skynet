#include "../../../../../../include/wxwidgets/vpc/dialog/config/hardware/T100VPCMemorySetupDemoDialog.h"

//(*InternalHeaders(T100VPCMemorySetupDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCMemorySetupDemoDialog)
//*)

BEGIN_EVENT_TABLE(T100VPCMemorySetupDemoDialog,wxDialog)
	//(*EventTable(T100VPCMemorySetupDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCMemorySetupDemoDialog::T100VPCMemorySetupDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCMemorySetupDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCMemorySetupDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100VPCMemorySetupDemoDialog::~T100VPCMemorySetupDemoDialog()
{
	//(*Destroy(T100VPCMemorySetupDemoDialog)
	//*)
}

