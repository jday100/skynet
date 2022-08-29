#include "../../../../include/ide/view/frame/T100IDEFrameText.h"

//(*InternalHeaders(T100IDEFrameText)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100IDEFrameText)
//*)

BEGIN_EVENT_TABLE(T100IDEFrameText,wxDocMDIChildFrame)
	//(*EventTable(T100IDEFrameText)
	//*)
END_EVENT_TABLE()

T100IDEFrameText::T100IDEFrameText(wxDocument* doc,wxView* view,wxMDIParentFrame* parent,wxWindowID id,const wxString& title)
{
	BuildContent(doc,view,parent,id,title);
}

void T100IDEFrameText::BuildContent(wxDocument* doc,wxView* view,wxMDIParentFrame* parent,wxWindowID id,const wxString& title)
{
    //Create(doc, view, parent, id, title);
	//(*Initialize(T100IDEFrameText)
	Create(doc, view, parent, id, title);
	//*)
}

T100IDEFrameText::~T100IDEFrameText()
{
	//(*Destroy(T100IDEFrameText)
	//*)
}

T100BOOL T100IDEFrameText::load(T100EditorData* data)
{
    wxString text;

    text = "hello world";

    if(data){
        text    = (T100STDCHAR*)data->m_data.data();
        m_data  = data;

        SetLabel(data->m_name.to_std_string());
    }

    //m_text->SetValue(text);

    return T100FALSE;
}

T100EditorData* T100IDEFrameText::getData()
{
    return m_data;
}
