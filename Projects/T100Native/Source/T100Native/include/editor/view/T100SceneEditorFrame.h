#ifndef T100SCENEEDITORFRAME_H
#define T100SCENEEDITORFRAME_H

//(*Headers(T100SceneEditorFrame)
#include <wx/aui/aui.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100WxRender.h"

class T100SceneEditorFrame: public wxFrame
{
	public:

		T100SceneEditorFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100SceneEditorFrame();

		T100VOID            SetRender(T100WxRender*);
		T100WxRender*       GetRender();

		//(*Declarations(T100SceneEditorFrame)
		wxAuiManager* AuiManager1;
		wxMenu* Menu1;
		wxMenuBar* MenuBar1;
		wxMenuItem* MenuItem1;
		wxMenuItem* MenuItem2;
		wxMenuItem* MenuItem3;
		wxMenuItem* MenuItem4;
		wxStatusBar* StatusBar1;
		//*)

	protected:

		//(*Identifiers(T100SceneEditorFrame)
		static const long ID_MENUITEM1;
		static const long ID_MENUITEM2;
		static const long ID_MENUITEM3;
		static const long ID_MENUITEM4;
		static const long ID_STATUSBAR1;
		//*)

	private:
	    T100VOID                TurnOn();
	    T100VOID                TurnOff();

		//(*Handlers(T100SceneEditorFrame)
		//*)

	protected:
	    T100WxRender*           m_render            = T100NULL;

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
