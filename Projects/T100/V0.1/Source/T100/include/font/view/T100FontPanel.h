#ifndef T100FONTPANEL_H
#define T100FONTPANEL_H

//(*Headers(T100FontPanel)
#include <wx/panel.h>
//*)

namespace T100FontBuilder{

class T100FontPanel: public wxPanel
{
	public:

		T100FontPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100FontPanel();

		//(*Declarations(T100FontPanel)
		//*)

	protected:

		//(*Identifiers(T100FontPanel)
		//*)

	private:

		//(*Handlers(T100FontPanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif
