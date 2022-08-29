#ifndef T100VPCFRAME_H
#define T100VPCFRAME_H

//(*Headers(T100VPCFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/statusbr.h>
//*)
#include "T100VPCCommon.h"
class T100VPCView;


class T100VPCFrame: public wxFrame
{
    friend class T100Executor32;
    friend class T100VPCDebugFrame;
    friend class T100Memory32;
    friend class T100Manager32;
    friend class T100VPCApp;
    friend class T100VPCView;
    friend class T100VPCCallback;
	public:

		T100VPCFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCFrame();

		T100VOID            setView(T100VPCView*);
		T100VPCView*        getView();

		//(*Declarations(T100VPCFrame)
		wxMenu* Menu1;
		wxMenu* Menu4;
		wxMenuBar* MenuBar1;
		wxMenuItem* MenuDebug;
		wxMenuItem* MenuQuit;
		wxMenuItem* MenuSetup;
		wxMenuItem* MenuStart;
		wxMenuItem* MenuStop;
		wxRichTextCtrl* RichTextCtrl1;
		wxStatusBar* StatusBar1;
		//*)

	protected:
	    T100BOOL            start();
		T100BOOL            stop();

		//(*Identifiers(T100VPCFrame)
		static const long ID_RICHTEXTCTRL1;
		static const long ID_STATUSBAR1;
		static const long ID_MENUITEM_START;
		static const long ID_MENUITEM_STOP;
		static const long ID_MENUITEM_QUIT;
		static const long ID_MENUITEM_SETUP;
		static const long ID_MENUITEM_DEBUG;
		//*)

		static const long ID_THREAD_DEBUG;
		static const long ID_THREAD_DEBUG_UPDATE;
		static const long ID_THREAD_DONE;
		static const long ID_THREAD_QUIT;
		static const long ID_DEBUG_ROM_BASE_UPDATE;
		static const long ID_DEBUG_RAM_BASE_UPDATE;
		static const long ID_DEBUG_DEVICE_UPDATE;
		static const long ID_DEBUG_BLOCK_BASE_UPDATE;
		static const long ID_DEBUG_PAGE_BASE_UPDATE;

	private:
	    T100VPCView*        m_view;
	    T100BOOL            m_debug             = T100FALSE;
	    T100BOOL            m_debugging         = T100FALSE;

		//(*Handlers(T100VPCFrame)
		void OnMenuQuitSelected(wxCommandEvent& event);
		void OnMenuStartSelected(wxCommandEvent& event);
		void OnMenuStopSelected(wxCommandEvent& event);
		void OnMenuSetupSelected(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnMenuDebugSelected(wxCommandEvent& event);
		//*)

		void OnThreadDebug(wxThreadEvent& event);
		void OnThreadDebugUpdate(wxThreadEvent& event);
		void OnThreadDone(wxThreadEvent& event);
		void OnThreadQuit(wxThreadEvent& event);

		void OnDebugRomBaseUpdate(wxThreadEvent& event);
		void OnDebugRamBaseUpdate(wxThreadEvent& event);
		void OnDebugDeviceUpdate(wxThreadEvent& event);
		void OnDebugBlockBaseUpdate(wxThreadEvent& event);
		void OnDebugPageBaseUpdate(wxThreadEvent& event);

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
