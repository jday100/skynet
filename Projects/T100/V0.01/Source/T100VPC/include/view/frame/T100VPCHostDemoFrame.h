#ifndef T100VPCHOSTDEMOFRAME_H
#define T100VPCHOSTDEMOFRAME_H

//(*Headers(T100VPCHostDemoFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class T100VPCHostDemoFrame: public wxFrame
{
	public:

		T100VPCHostDemoFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCHostDemoFrame();

		//(*Declarations(T100VPCHostDemoFrame)
		wxMenu* Menu1;
		wxMenuBar* MenuBar1;
		wxMenuItem* MenuLoad;
		wxMenuItem* MenuRun;
		wxPanel* Panel1;
		wxStatusBar* StatusBar1;
		//*)

	protected:

		//(*Identifiers(T100VPCHostDemoFrame)
		static const long ID_PANEL1;
		static const long ID_MENU_LOAD;
		static const long ID_MENU_RUN;
		static const long ID_STATUSBAR1;
		//*)

	private:

		//(*Handlers(T100VPCHostDemoFrame)
		void OnMenuLoadSelected(wxCommandEvent& event);
		void OnMenuRunSelected(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
