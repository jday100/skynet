#ifndef T100PAINTELEMENTSPANEL_H
#define T100PAINTELEMENTSPANEL_H

//(*Headers(T100PaintElementsPanel)
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100PaintElementsPanel: public wxPanel
{
	public:

		T100PaintElementsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PaintElementsPanel();

		//(*Declarations(T100PaintElementsPanel)
		wxImageList* ImageList1;
		wxListView* ListView1;
		wxListView* ListView2;
		wxListView* ListView3;
		wxNotebook* Notebook1;
		//*)

	protected:

		//(*Identifiers(T100PaintElementsPanel)
		static const long ID_LISTVIEW1;
		static const long ID_LISTVIEW2;
		static const long ID_LISTVIEW3;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(T100PaintElementsPanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
