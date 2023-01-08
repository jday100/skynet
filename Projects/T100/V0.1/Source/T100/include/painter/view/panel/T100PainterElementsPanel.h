#ifndef T100PAINTERELEMENTSPANEL_H
#define T100PAINTERELEMENTSPANEL_H

#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include "T100Common.h"

namespace T100Painter{
class T100ElementBase;

class T100PainterElementsPanel : public wxPanel
{
    public:
        T100PainterElementsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100PainterElementsPanel();

        T100BOOL            Append(wxString, T100ElementBase*);

    public:

        wxNotebook*         Notebook1;

        wxPanel*            Panel1;
		wxPanel*            Panel2;
		wxPanel*            Panel3;

        wxListView*         ListView1;
		wxListView*         ListView2;
		wxListView*         ListView3;

    protected:
        static const long ID_NOTEBOOK1;

        static const long ID_PANEL1;
        static const long ID_PANEL2;
        static const long ID_PANEL3;

        static const long ID_LISTVIEW1;
		static const long ID_LISTVIEW2;
		static const long ID_LISTVIEW3;

    private:
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        void OnPanel1ListCtrlItemSelect(wxListEvent& event);
        void OnPanel1ListCtrlItemDeselect(wxListEvent& event);

        void OnPanel2ListCtrlItemSelect(wxListEvent& event);
        void OnPanel2ListCtrlItemDeselect(wxListEvent& event);

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTERELEMENTSPANEL_H
