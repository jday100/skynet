#include "../../../include/vpc/view/T100VPCConfigDialog.h"

//(*InternalHeaders(T100VPCConfigDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

namespace T100VPC{

//(*IdInit(T100VPCConfigDialog)
//*)

BEGIN_EVENT_TABLE(T100VPCConfigDialog,wxDialog)
	//(*EventTable(T100VPCConfigDialog)
	//*)
END_EVENT_TABLE()

T100VPCConfigDialog::T100VPCConfigDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCConfigDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCConfigDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100VPCConfigDialog::~T100VPCConfigDialog()
{
	//(*Destroy(T100VPCConfigDialog)
	//*)
}

}
