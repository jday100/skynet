#ifndef T100SCENEEDITORENTITYPANEL_H
#define T100SCENEEDITORENTITYPANEL_H

//(*Headers(T100SceneEditorEntityPanel)
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100SceneEditorEntityPanel: public wxPanel
{
	public:

		T100SceneEditorEntityPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100SceneEditorEntityPanel();

		//(*Declarations(T100SceneEditorEntityPanel)
		wxNotebook* Notebook1;
		wxPanel* Panel1;
		wxPanel* Panel2;
		//*)

	protected:

		//(*Identifiers(T100SceneEditorEntityPanel)
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(T100SceneEditorEntityPanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
