#ifndef T100MAINPANEL_H
#define T100MAINPANEL_H

//(*Headers(T100MainPanel)
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100MainPanel: public wxPanel
{
	public:

		T100MainPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100MainPanel();

		//(*Declarations(T100MainPanel)
		wxNotebook* Notebook;
		//*)

	protected:

		//(*Identifiers(T100MainPanel)
		static const long ID_NOTEBOOK;
		//*)

	private:

		//(*Handlers(T100MainPanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
