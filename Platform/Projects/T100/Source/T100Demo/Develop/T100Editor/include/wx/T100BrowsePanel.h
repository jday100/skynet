#ifndef T100BROWSEPANEL_H
#define T100BROWSEPANEL_H

//(*Headers(T100BrowsePanel)
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100BrowsePanel: public wxPanel
{
	public:

		T100BrowsePanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100BrowsePanel();

		//(*Declarations(T100BrowsePanel)
		//*)

	protected:

		//(*Identifiers(T100BrowsePanel)
		//*)

	private:

		//(*Handlers(T100BrowsePanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
