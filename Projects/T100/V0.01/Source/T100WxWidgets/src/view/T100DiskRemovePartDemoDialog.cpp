#include "../../include/view/T100DiskRemovePartDemoDialog.h"

//(*InternalHeaders(T100DiskRemovePartDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskRemovePartDemoDialog)
//*)

BEGIN_EVENT_TABLE(T100DiskRemovePartDemoDialog,wxDialog)
	//(*EventTable(T100DiskRemovePartDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskRemovePartDemoDialog::T100DiskRemovePartDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskRemovePartDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskRemovePartDemoDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100DiskRemovePartDemoDialog::~T100DiskRemovePartDemoDialog()
{
	//(*Destroy(T100DiskRemovePartDemoDialog)
	//*)
}

