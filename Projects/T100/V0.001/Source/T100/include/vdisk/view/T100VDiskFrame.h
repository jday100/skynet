#ifndef T100VDISKFRAME_H
#define T100VDISKFRAME_H

//(*Headers(T100VDiskFrame)
#include <wx/frame.h>
//*)

class T100VDiskFrame: public wxFrame
{
	public:

		T100VDiskFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VDiskFrame();

		//(*Declarations(T100VDiskFrame)
		//*)

	protected:

		//(*Identifiers(T100VDiskFrame)
		//*)

	private:

		//(*Handlers(T100VDiskFrame)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
