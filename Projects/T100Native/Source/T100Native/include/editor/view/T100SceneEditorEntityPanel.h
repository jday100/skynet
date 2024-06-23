#ifndef T100SCENEEDITORENTITYPANEL_H
#define T100SCENEEDITORENTITYPANEL_H

//(*Headers(T100SceneEditorEntityPanel)
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

#include "T100Common.h"
class T100Editor;

class T100SceneEditorEntityPanel: public wxPanel
{
	public:

		T100SceneEditorEntityPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100SceneEditorEntityPanel();

		//(*Declarations(T100SceneEditorEntityPanel)
		wxImageList* ImageList1;
		wxListView* ListViewEntity;
		wxNotebook* Notebook1;
		wxPanel* Panel1;
		wxPanel* Panel2;
		//*)

		T100VOID            SetEditor(T100Editor*);

	protected:

		//(*Identifiers(T100SceneEditorEntityPanel)
		static const long ID_LISTVIEW_ENTITY;
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(T100SceneEditorEntityPanel)
		void OnListViewEntityItemSelect(wxListEvent& event);
		void OnListViewEntityItemDeselect(wxListEvent& event);
		void OnListViewEntityItemActivated(wxListEvent& event);
		void OnListViewEntityItemFocused(wxListEvent& event);
		//*)

	protected:
	    T100Editor*         m_editor            = T100NULL;

	    T100VOID            TurnOn();
	    T100VOID            TurnOff();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
