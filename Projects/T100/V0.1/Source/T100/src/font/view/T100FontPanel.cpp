#include "../../../include/font/view/T100FontPanel.h"

//(*InternalHeaders(T100FontPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

namespace T100FontBuilder{

//(*IdInit(T100FontPanel)
//*)

BEGIN_EVENT_TABLE(T100FontPanel,wxPanel)
	//(*EventTable(T100FontPanel)
	//*)
END_EVENT_TABLE()

T100FontPanel::T100FontPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100FontPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100FontPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

T100FontPanel::~T100FontPanel()
{
	//(*Destroy(T100FontPanel)
	//*)
}

}
