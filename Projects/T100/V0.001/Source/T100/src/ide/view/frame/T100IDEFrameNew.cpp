#include "../../../../include/ide/view/frame/T100IDEFrameNew.h"

//(*InternalHeaders(T100IDEFrameNew)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100IDEView.h"

//(*IdInit(T100IDEFrameNew)
//*)

BEGIN_EVENT_TABLE(T100IDEFrameNew,wxDocMDIParentFrame)
	//(*EventTable(T100IDEFrameNew)
	//*)
END_EVENT_TABLE()

T100IDEFrameNew::T100IDEFrameNew(wxDocManager* manager,wxFrame* parent,wxWindowID id,const wxString& title)
{
	BuildContent(manager,parent,id,title);
}

void T100IDEFrameNew::BuildContent(wxDocManager* manager,wxFrame* parent,wxWindowID id,const wxString& title)
{
    //Create(manager, parent, id, title);
	//(*Initialize(T100IDEFrameNew)
	Create(manager, parent, id, title);
	//*)
}

T100IDEFrameNew::~T100IDEFrameNew()
{
	//(*Destroy(T100IDEFrameNew)
	//*)

	m_view->getManager()->getAuiManager()->UnInit();
}

T100VOID T100IDEFrameNew::setView(T100IDEView* view)
{
    m_view = view;
}

T100IDEView* T100IDEFrameNew::getView()
{
    return m_view;
}
