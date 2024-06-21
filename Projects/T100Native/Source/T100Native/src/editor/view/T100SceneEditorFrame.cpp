#include "../../../include/editor/view/T100SceneEditorFrame.h"

//(*InternalHeaders(T100SceneEditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100SceneEditorFrame)
//*)

BEGIN_EVENT_TABLE(T100SceneEditorFrame,wxFrame)
	//(*EventTable(T100SceneEditorFrame)
	//*)
END_EVENT_TABLE()

T100SceneEditorFrame::T100SceneEditorFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100SceneEditorFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100SceneEditorFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	MenuBar1 = new wxMenuBar();
	SetMenuBar(MenuBar1);
	//*)
}

T100SceneEditorFrame::~T100SceneEditorFrame()
{
	//(*Destroy(T100SceneEditorFrame)
	//*)
}

