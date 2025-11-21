#ifndef T100EDITORPANEL_H
#define T100EDITORPANEL_H

//(*Headers(T100EditorPanel)
#include <wx/panel.h>
//*)

#include <wx/sizer.h>
#include <wx/stc/stc.h>
#include "T100Common.h"

class T100EditorPanel: public wxPanel
{
	public:

		T100EditorPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100EditorPanel();

		//(*Declarations(T100EditorPanel)
		//*)

	protected:

		//(*Identifiers(T100EditorPanel)
		//*)

	private:
	    wxStyledTextCtrl*           m_styledTextCtrl        = T100NULL;

		//(*Handlers(T100EditorPanel)
		//*)

	protected:
	    T100VOID                    init();
	    T100VOID                    uninit();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
