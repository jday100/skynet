#ifndef T100VPCSCREEN_H
#define T100VPCSCREEN_H

//(*Headers(T100VPCScreen)
#include <wx/frame.h>
//*)

#include "T100VPCCommon.h"


class T100VPCScreen: public wxFrame
{
	public:

		T100VPCScreen(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCScreen();

		//(*Declarations(T100VPCScreen)
		//*)

	protected:

		//(*Identifiers(T100VPCScreen)
		//*)

	private:

		//(*Handlers(T100VPCScreen)
		void OnEraseBackground(wxEraseEvent& event);
		void OnPaint(wxPaintEvent& event);
		//*)

	protected:
	    T100BOOL        paint();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
