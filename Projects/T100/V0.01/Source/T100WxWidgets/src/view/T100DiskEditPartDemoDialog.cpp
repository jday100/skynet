#include "../../include/view/T100DiskEditPartDemoDialog.h"

//(*InternalHeaders(T100DiskEditPartDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskEditPartDemoDialog)
//*)

BEGIN_EVENT_TABLE(T100DiskEditPartDemoDialog,wxDialog)
	//(*EventTable(T100DiskEditPartDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskEditPartDemoDialog::T100DiskEditPartDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskEditPartDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskEditPartDemoDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100DiskEditPartDemoDialog::~T100DiskEditPartDemoDialog()
{
	//(*Destroy(T100DiskEditPartDemoDialog)
	//*)
}

