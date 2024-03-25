#ifndef T100WPAINTERELEMENTSPANEL_H
#define T100WPAINTERELEMENTSPANEL_H

//(*Headers(T100WPainterElementsPanel)
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

#include "T100Common.h"

class T100WPainterElementsPanel: public wxPanel
{
	public:

		T100WPainterElementsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100WPainterElementsPanel();

		//(*Declarations(T100WPainterElementsPanel)
		wxImageList* ImageList1;
		wxListView* ListView1;
		wxListView* ListView2;
		wxListView* ListView3;
		wxNotebook* Notebook1;
		//*)


		static const long ID_THREAD_IMAGE;

	protected:

		//(*Identifiers(T100WPainterElementsPanel)
		static const long ID_LISTVIEW1;
		static const long ID_LISTVIEW2;
		static const long ID_LISTVIEW3;
		static const long ID_NOTEBOOK1;
		//*)

	private:
	    void OnThreadImage(wxThreadEvent& event);

		//(*Handlers(T100WPainterElementsPanel)
		void OnListView1ItemSelect(wxListEvent& event);
		void OnListView1ItemDeselect(wxListEvent& event);
		//*)

	protected:
	    T100VOID            create();
	    T100VOID            destroy();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
