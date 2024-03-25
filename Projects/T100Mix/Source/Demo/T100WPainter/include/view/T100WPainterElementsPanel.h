#ifndef T100WPAINTERELEMENTSPANEL_H
#define T100WPAINTERELEMENTSPANEL_H

//(*Headers(T100WPainterElementsPanel)
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100WPainterElementsPanel: public wxPanel
{
	public:

		T100WPainterElementsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100WPainterElementsPanel();

		//(*Declarations(T100WPainterElementsPanel)
		wxListView* ListView1;
		wxListView* ListView2;
		wxListView* ListView3;
		wxNotebook* Notebook1;
		//*)

	protected:

		//(*Identifiers(T100WPainterElementsPanel)
		static const long ID_LISTVIEW1;
		static const long ID_LISTVIEW2;
		static const long ID_LISTVIEW3;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(T100WPainterElementsPanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
