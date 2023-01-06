#include "T100PainterPropertiesPanel.h"

#include <wx/intl.h>
#include <wx/string.h>

#include "T100PainterCallback.h"

namespace T100Painter{

const long T100PainterPropertiesPanel::ID_LISTVIEW = wxNewId();

BEGIN_EVENT_TABLE(T100PainterPropertiesPanel,wxPanel)

END_EVENT_TABLE()

T100PainterPropertiesPanel::T100PainterPropertiesPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100PainterPropertiesPanel::~T100PainterPropertiesPanel()
{
    //dtor
}

void T100PainterPropertiesPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	ListView = new wxListView(this, ID_LISTVIEW, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW"));
	BoxSizer1->Add(ListView, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
}

T100BOOL T100PainterPropertiesPanel::setElement(T100ElementBase* element)
{
    m_element = element;

    element->Update(ListView);

    return T100TRUE;
}

}
