#ifndef T100WXPAINTELEMENTSPANEL_H
#define T100WXPAINTELEMENTSPANEL_H

#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include "T100Common.h"
#include "wx\paint\task\T100WxPaintElementsLoadThreadTask.h"


class T100WxPaintElementsPanel : public wxPanel
{
    public:
        T100WxPaintElementsPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100WxPaintElementsPanel();

        static const long ID_THREAD_IMAGE;

    protected:
        wxNotebook*         Notebook1;
        wxImageList*        ImageList1;

        wxPanel*            Panel1;
        wxPanel*            Panel2;
        wxPanel*            Panel3;

        wxListView*         ListView1;
        wxListView*         ListView2;
        wxListView*         ListView3;

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100WxPaintElementsLoadThreadTask*          m_load_task         = T100NULL;

    protected:
        static const long ID_NOTEBOOK1;
        static const long ID_LISTVIEW1;
        static const long ID_LISTVIEW2;
        static const long ID_LISTVIEW3;

    private:
        void OnThreadImage(wxThreadEvent& event);

        void OnPanel1ListCtrlItemSelect(wxListEvent& event);
        void OnPanel1ListCtrlItemDeselect(wxListEvent& event);

    private:
        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

        DECLARE_EVENT_TABLE()
};

#endif // T100WXPAINTELEMENTSPANEL_H
