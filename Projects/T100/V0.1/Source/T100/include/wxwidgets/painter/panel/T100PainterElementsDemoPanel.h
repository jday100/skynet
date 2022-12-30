#ifndef T100PAINTERELEMENTSDEMOPANEL_H
#define T100PAINTERELEMENTSDEMOPANEL_H

//(*Headers(T100PainterElementsDemoPanel)
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100PainterElementsDemoPanel: public wxPanel
{
	public:

		T100PainterElementsDemoPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PainterElementsDemoPanel();

		//(*Declarations(T100PainterElementsDemoPanel)
		wxListView* ListView1;
		wxListView* ListView2;
		wxListView* ListView3;
		wxNotebook* Notebook1;
		wxPanel* Panel1;
		wxPanel* Panel2;
		wxPanel* Panel3;
		//*)

	protected:

		//(*Identifiers(T100PainterElementsDemoPanel)
		static const long ID_LISTVIEW1;
		static const long ID_PANEL1;
		static const long ID_LISTVIEW2;
		static const long ID_PANEL2;
		static const long ID_LISTVIEW3;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(T100PainterElementsDemoPanel)
		void OnNotebook1PageChanged(wxNotebookEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
