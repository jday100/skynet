#ifndef T100FONTFRAME_H
#define T100FONTFRAME_H

//(*Headers(T100FontFrame)
#include "T100FontPanel.h"
#include <wx/frame.h>
//*)

namespace T100FontBuilder{

class T100FontFrame: public wxFrame
{
	public:

		T100FontFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100FontFrame();

		//(*Declarations(T100FontFrame)
		T100FontPanel* Custom1;
		//*)

	protected:

		//(*Identifiers(T100FontFrame)
		static const long ID_CUSTOM1;
		//*)

	private:

		//(*Handlers(T100FontFrame)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif
