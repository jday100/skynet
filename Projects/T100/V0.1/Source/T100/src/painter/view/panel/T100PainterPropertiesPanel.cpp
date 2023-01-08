#include "T100PainterPropertiesPanel.h"

#include <wx/intl.h>
#include <wx/string.h>

#include "T100PainterView.h"
#include "T100PainterCallback.h"

namespace T100Painter{

const long T100PainterPropertiesPanel::ID_PROPERTYGRID = wxNewId();

BEGIN_EVENT_TABLE(T100PainterPropertiesPanel,wxPanel)
    EVT_PG_CHANGED(ID_PROPERTYGRID, T100PainterPropertiesPanel::OnChanged)
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
	PropertyGrid = new wxPropertyGrid(this, ID_PROPERTYGRID, wxDefaultPosition, wxDefaultSize, 0, _T("ID_PROPERTYGRID"));
	BoxSizer1->Add(PropertyGrid, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
}

T100BOOL T100PainterPropertiesPanel::setElement(T100ElementBase* element)
{
    m_element = element;


    element->Update(PropertyGrid);

    return T100TRUE;
}

T100VOID T100PainterPropertiesPanel::Clear()
{
    PropertyGrid->Clear();
}

T100VOID T100PainterPropertiesPanel::OnChanged(wxPropertyGridEvent& event)
{
    if(m_element){
        m_element->Update(event);
        T100PainterCallback::getView()->getPaintCtrl()->Refresh();
    }
}

}
