#include "../../../../../include/wxwidgets/vpc/dialog/config/T100VPCConfigSetupDemoDialog.h"

//(*InternalHeaders(T100VPCConfigSetupDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCConfigSetupDemoDialog)
//*)

BEGIN_EVENT_TABLE(T100VPCConfigSetupDemoDialog,wxDialog)
	//(*EventTable(T100VPCConfigSetupDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCConfigSetupDemoDialog::T100VPCConfigSetupDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCConfigSetupDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCConfigSetupDemoDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100VPCConfigSetupDemoDialog::~T100VPCConfigSetupDemoDialog()
{
	//(*Destroy(T100VPCConfigSetupDemoDialog)
	//*)
}

