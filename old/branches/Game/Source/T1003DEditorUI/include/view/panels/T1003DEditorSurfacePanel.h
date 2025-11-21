#ifndef T1003DEDITORSURFACEPANEL_H
#define T1003DEDITORSURFACEPANEL_H

#include <wx/panel.h>
#include <wx/imaglist.h>
#include "T1003DEditorListCtrl.h"

class T1003DEditorSkeletal;

class T1003DEditorSurfacePanel : public wxPanel
{
    public:
        T1003DEditorSurfacePanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorSurfacePanel();

        T100VOID                        SetImageList(wxImageList*);
        T100VOID                        SetSkeletal(T1003DEditorSkeletal*);

        T100VOID                        Clear();

    protected:
        long                            m_item              = 0;
        T1003DEditorSkeletal*           m_skeletal          = T100NULL;
        T1003DEditorListCtrl*           m_listCtrl          = T100NULL;
        wxImageList*                    m_imageList         = T100NULL;

        T100VOID                        InitItems();
        T100VOID                        InitImageList();

        T100VOID                        InsertItem(T100WSTRING, T100UINT);

    protected:
        void            OnSelected(wxListEvent& event);

        void            OnMouseRightDown(wxMouseEvent& event);

    private:
        T100VOID                        init();
        T100VOID                        uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORSURFACEPANEL_H
