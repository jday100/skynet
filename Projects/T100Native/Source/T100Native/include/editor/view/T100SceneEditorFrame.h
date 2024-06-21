#ifndef T100SCENEEDITORFRAME_H
#define T100SCENEEDITORFRAME_H

//(*Headers(T100SceneEditorFrame)
#include <wx/frame.h>
#include <wx/menu.h>
//*)

class T100SceneEditorFrame: public wxFrame
{
	public:

		T100SceneEditorFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100SceneEditorFrame();

		//(*Declarations(T100SceneEditorFrame)
		wxMenuBar* MenuBar1;
		//*)

	protected:

		//(*Identifiers(T100SceneEditorFrame)
		//*)

	private:

		//(*Handlers(T100SceneEditorFrame)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
