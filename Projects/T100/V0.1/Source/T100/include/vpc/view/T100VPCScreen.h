#ifndef T100VPCSCREEN_H
#define T100VPCSCREEN_H

//(*Headers(T100VPCScreen)
#include <wx/frame.h>
//*)

namespace T100VPC{

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
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif
