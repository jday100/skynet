#ifndef T100VPCDEMOPANEL_H
#define T100VPCDEMOPANEL_H

//(*Headers(T100VPCDemoPanel)
#include <wx/panel.h>
//*)

class T100VPCDemoPanel: public wxPanel
{
	public:

		T100VPCDemoPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCDemoPanel();

		//(*Declarations(T100VPCDemoPanel)
		//*)

	protected:

		//(*Identifiers(T100VPCDemoPanel)
		//*)

	private:

		//(*Handlers(T100VPCDemoPanel)
		void OnPaint(wxPaintEvent& event);
		void OnEraseBackground(wxEraseEvent& event);
		void OnKeyDown(wxKeyEvent& event);
		void OnKeyUp(wxKeyEvent& event);
		void OnChar(wxKeyEvent& event);
		void OnSetFocus(wxFocusEvent& event);
		void OnKillFocus(wxFocusEvent& event);
		void OnMouseMove(wxMouseEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
