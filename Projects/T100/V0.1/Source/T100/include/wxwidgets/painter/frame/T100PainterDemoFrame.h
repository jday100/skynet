#ifndef T100PAINTERDEMOFRAME_H
#define T100PAINTERDEMOFRAME_H

//(*Headers(T100PainterDemoFrame)
#include <wx/frame.h>
#include <wx/scrolwin.h>
//*)

class T100PainterDemoFrame: public wxFrame
{
	public:

		T100PainterDemoFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PainterDemoFrame();

		//(*Declarations(T100PainterDemoFrame)
		wxScrolledWindow* ScrolledWindow1;
		//*)

	protected:

		//(*Identifiers(T100PainterDemoFrame)
		static const long ID_SCROLLEDWINDOW1;
		//*)

	private:

		//(*Handlers(T100PainterDemoFrame)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
