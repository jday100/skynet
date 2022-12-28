#include "T100PainterFrame.h"

#include <wx/intl.h>
#include <wx/string.h>

namespace T100Painter{

BEGIN_EVENT_TABLE(T100PainterFrame,wxFrame)

END_EVENT_TABLE()

T100PainterFrame::T100PainterFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100PainterFrame::~T100PainterFrame()
{
    //dtor
}

void T100PainterFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(406,550));
	Move(wxDefaultPosition);

}

}
