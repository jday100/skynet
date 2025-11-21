#ifndef T100VMFRAME_H
#define T100VMFRAME_H

//(*Headers(T100VMFrame)
#include <wx/frame.h>
#include <wx/menu.h>
//*)

class T100VMFrame: public wxFrame
{
	public:

		T100VMFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VMFrame();

		//(*Declarations(T100VMFrame)
		wxMenuBar* MenuBar1;
		//*)

	protected:

		//(*Identifiers(T100VMFrame)
		//*)

	private:

		//(*Handlers(T100VMFrame)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
