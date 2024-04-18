#ifndef T100PAINTERELEMENTSPANEL_H
#define T100PAINTERELEMENTSPANEL_H

//(*Headers(T100PainterElementsPanel)
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100PainterElementsPanel: public wxPanel
{
	public:

		T100PainterElementsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PainterElementsPanel();

		//(*Declarations(T100PainterElementsPanel)
		wxImageList* ImageList1;
		wxListView* ListView1;
		wxNotebook* Notebook1;
		//*)

		static const long ID_THREAD_IMAGE;

	protected:

		//(*Identifiers(T100PainterElementsPanel)
		static const long ID_LISTVIEW1;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(T100PainterElementsPanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
