#ifndef T100VPCFRAME_H
#define T100VPCFRAME_H

//(*Headers(T100VPCFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

namespace T100VPC{

class T100VPCFrame: public wxFrame
{
	public:

		T100VPCFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCFrame();


        static const long ID_THREAD_START;
		static const long ID_THREAD_STOP;
		static const long ID_THREAD_QUIT;

		static const long ID_DEBUG_REGISTER_UPDATE;
		static const long ID_DEBUG_MEMORY_UPDATE;
		static const long ID_DEBUG_PORT_UPDATE;

		static const long ID_DEBUG_PAUSE;


		//(*Declarations(T100VPCFrame)
		wxMenu* Menu11;
		wxMenu* Menu1;
		wxMenu* Menu6;
		wxMenu* Menu8;
		wxMenuBar* MenuBar1;
		wxMenuItem* AboutMenu;
		wxMenuItem* DebugMenu;
		wxMenuItem* HardwareMenu;
		wxMenuItem* QuitMenu;
		wxMenuItem* SetupMenu;
		wxMenuItem* StartMenu;
		wxMenuItem* StopMenu;
		wxStatusBar* StatusBar1;
		//*)

	protected:

		//(*Identifiers(T100VPCFrame)
		static const long ID_MENUITEM_START;
		static const long ID_MENUITEM_STOP;
		static const long ID_MENUITEM_QUIT;
		static const long ID_MENUITEM_DEBUG;
		static const long ID_MENUITEM_HARDWARE;
		static const long ID_MENUITEM_SETUP;
		static const long ID_MENUITEM_ABOUT;
		static const long ID_STATUSBAR1;
		//*)



	private:

		//(*Handlers(T100VPCFrame)
		void OnStartMenuSelected(wxCommandEvent& event);
		void OnStopMenuSelected(wxCommandEvent& event);
		void OnQuitMenuSelected(wxCommandEvent& event);
		void OnDebugMenuSelected(wxCommandEvent& event);
		void OnHardwareMenuSelected(wxCommandEvent& event);
		void OnSetupMenuSelected(wxCommandEvent& event);
		void OnAboutMenuSelected(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		void OnThreadStart(wxThreadEvent& event);
		void OnThreadStop(wxThreadEvent& event);
		void OnThreadQuit(wxThreadEvent& event);

		void OnDebugRegisterUpdate(wxThreadEvent& event);
		void OnDebugMemoryUpdate(wxThreadEvent& event);
		void OnDebugPortUpdate(wxThreadEvent& event);

		void OnDebugPause(wxThreadEvent& event);

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif
