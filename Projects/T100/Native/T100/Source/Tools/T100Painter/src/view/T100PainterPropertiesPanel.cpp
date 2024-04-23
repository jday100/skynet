#include "../../include/view/T100PainterPropertiesPanel.h"

//(*InternalHeaders(T100PainterPropertiesPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100PainterPropertiesPanel)
//*)

BEGIN_EVENT_TABLE(T100PainterPropertiesPanel,wxPanel)
	//(*EventTable(T100PainterPropertiesPanel)
	//*)
END_EVENT_TABLE()

T100PainterPropertiesPanel::T100PainterPropertiesPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100PainterPropertiesPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100PainterPropertiesPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

T100PainterPropertiesPanel::~T100PainterPropertiesPanel()
{
	//(*Destroy(T100PainterPropertiesPanel)
	//*)
}

T100VOID T100PainterPropertiesPanel::setElement(T100ElementBase* element)
{
    m_element   = element;
}
