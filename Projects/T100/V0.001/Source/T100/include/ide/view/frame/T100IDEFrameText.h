#ifndef T100IDEFRAMETEXT_H
#define T100IDEFRAMETEXT_H

//(*Headers(T100IDEFrameText)
#include <wx/frame.h>
//*)
#include <wx/docmdi.h>
#include "T100EditorData.h"


class T100IDEFrameText: public wxDocMDIChildFrame
{
	public:

		T100IDEFrameText(wxDocument* doc,wxView* view,wxMDIParentFrame* parent,wxWindowID id=wxID_ANY,const wxString& title=wxEmptyString);
		virtual ~T100IDEFrameText();

		//(*Declarations(T100IDEFrameText)
		//*)

		T100BOOL            load(T100EditorData*);
		T100EditorData*     getData();

	protected:

		//(*Identifiers(T100IDEFrameText)
		//*)

	private:
	    T100EditorData*     m_data          = T100NULL;

		//(*Handlers(T100IDEFrameText)
		//*)

	protected:

		void BuildContent(wxDocument* doc,wxView* view,wxMDIParentFrame* parent,wxWindowID id,const wxString& title);

		DECLARE_EVENT_TABLE()
};

#endif
