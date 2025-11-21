#ifndef T100DIAGRAMENTITYPANEL_H
#define T100DIAGRAMENTITYPANEL_H

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include "T100Common.h"

class T100DiagramEntityPanel : public wxPanel
{
    public:
        T100DiagramEntityPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100DiagramEntityPanel();

        virtual T100VOID            Clear();

    protected:
        static const long ID_LISTVIEW;

    protected:
        wxImageList*                m_imageList     = T100NULL;
        wxListView*                 m_listView      = T100NULL;

        T100INT                     m_index         =  0;

    private:
        T100VOID OnListViewItemSelect(wxListEvent& event);

        T100VOID                    init();
        T100VOID                    uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100DIAGRAMENTITYPANEL_H
