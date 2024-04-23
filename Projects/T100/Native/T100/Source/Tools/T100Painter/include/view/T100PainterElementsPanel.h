#ifndef T100PAINTERELEMENTSPANEL_H
#define T100PAINTERELEMENTSPANEL_H

//(*Headers(T100PainterElementsPanel)
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

#include "T100Common.h"
#include "T100PainterElementsDrawer.h"

class T100PainterElementsPanel: public wxPanel
{
	public:

		T100PainterElementsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PainterElementsPanel();

		T100VOID                            setElementsDrawer(T100PainterElementsDrawer*);
		T100PainterElementsDrawer*          getElementsDrawer();

		//(*Declarations(T100PainterElementsPanel)
		wxImageList* ImageList1;
		wxListView* ListView1;
		wxNotebook* Notebook1;
		//*)

    public:
		static const long ID_THREAD_IMAGE;

	protected:

		//(*Identifiers(T100PainterElementsPanel)
		static const long ID_LISTVIEW1;
		static const long ID_NOTEBOOK1;
		//*)

	private:
	    void OnThreadImage(wxThreadEvent& event);

		//(*Handlers(T100PainterElementsPanel)
		void OnListView1ItemSelect(wxListEvent& event);
		void OnListView1ItemDeselect(wxListEvent& event);
		//*)

	protected:
        T100VOID                            create();
        T100VOID                            destroy();

        T100PainterElementsDrawer*          m_elements_drawer           = T100NULL;

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
