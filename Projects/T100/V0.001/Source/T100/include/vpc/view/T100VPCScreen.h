#ifndef T100VPCSCREEN_H
#define T100VPCSCREEN_H

//(*Headers(T100VPCScreen)
#include <wx/frame.h>
#include <wx/timer.h>
//*)
#include "T100VPCCommon.h"
class T100VPCFrame;


class T100VPCScreen: public wxFrame
{
	public:

		T100VPCScreen(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCScreen();

		T100BOOL            run();
		T100BOOL            start();
		T100BOOL            stop();

		//(*Declarations(T100VPCScreen)
		wxTimer T100VPCTimer;
		//*)

	protected:
	    T100BOOL            draw();
	    T100BOOL            paint();

		//(*Identifiers(T100VPCScreen)
		static const long ID_TIMER_SCREEN;
		//*)

	private:
	    T100VPCFrame*       m_frame         = T100NULL;
	    T100BOOL            m_paint         = T100FALSE;

		//(*Handlers(T100VPCScreen)
		void OnT100VPCTimerTrigger(wxTimerEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnEraseBackground(wxEraseEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
