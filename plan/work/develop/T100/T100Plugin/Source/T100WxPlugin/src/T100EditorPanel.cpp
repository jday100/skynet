#include "../include/T100EditorPanel.h"

//(*InternalHeaders(T100EditorPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100EditorPanel)
//*)

BEGIN_EVENT_TABLE(T100EditorPanel,wxPanel)
	//(*EventTable(T100EditorPanel)
	//*)
END_EVENT_TABLE()

T100EditorPanel::T100EditorPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100EditorPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100EditorPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

T100EditorPanel::~T100EditorPanel()
{
	//(*Destroy(T100EditorPanel)
	//*)
}

