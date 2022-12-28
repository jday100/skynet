#include "T100EditorFrame.h"

#include <wx/intl.h>
#include <wx/string.h>


namespace T100Editor{

BEGIN_EVENT_TABLE(T100EditorFrame,wxFrame)

END_EVENT_TABLE()


T100EditorFrame::T100EditorFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100EditorFrame::~T100EditorFrame()
{
    //dtor
}

void T100EditorFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(406,550));
	Move(wxDefaultPosition);

}

}
