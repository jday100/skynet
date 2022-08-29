#ifndef T100IDEFRAMENEW_H
#define T100IDEFRAMENEW_H

//(*Headers(T100IDEFrameNew)
#include <wx/frame.h>
//*)

#include <wx/docmdi.h>
#include "T100Common.h"
class T100IDEView;


class T100IDEFrameNew: public wxDocMDIParentFrame
{
	public:

		T100IDEFrameNew(wxDocManager* manager,wxFrame* parent,wxWindowID id=wxID_ANY,const wxString& title=wxEmptyString);
		virtual ~T100IDEFrameNew();

		T100VOID                setView(T100IDEView*);
		T100IDEView*            getView();

		//(*Declarations(T100IDEFrameNew)
		//*)

	protected:
	    T100IDEView*            m_view          = T100NULL;

		//(*Identifiers(T100IDEFrameNew)
		//*)

	private:

		//(*Handlers(T100IDEFrameNew)
		//*)

	protected:

		void BuildContent(wxDocManager* manager,wxFrame* parent,wxWindowID id,const wxString& title);

		DECLARE_EVENT_TABLE()
};

#endif
