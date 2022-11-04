#ifndef T100VPCFRAME_H
#define T100VPCFRAME_H

//(*Headers(T100VPCFrame)
#include <wx/frame.h>
//*)

namespace T100VPC{

class T100VPCFrame: public wxFrame
{
	public:

		T100VPCFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCFrame();

		//(*Declarations(T100VPCFrame)
		//*)

	protected:

		//(*Identifiers(T100VPCFrame)
		//*)

	private:

		//(*Handlers(T100VPCFrame)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif
