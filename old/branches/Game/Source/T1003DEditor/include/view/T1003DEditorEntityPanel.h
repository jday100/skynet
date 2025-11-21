#ifndef T1003DEDITORENTITYPANEL_H
#define T1003DEDITORENTITYPANEL_H

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include <wx/imaglist.h>
#include "T100Common.h"

class T1003DEditorSkeletal;

class T1003DEditorEntityPanel : public wxPanel
{
    public:
        T1003DEditorEntityPanel(wxWindow *parent,
                wxWindowID winid = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorEntityPanel();

        T100VOID                    setSkeletal(T1003DEditorSkeletal*);

    protected:
        wxNotebook*                 m_notebook          = T100NULL;
        T1003DEditorSkeletal*       m_skeletal          = T100NULL;

        T100VOID                    InsertItem(T100WSTRING, T100UINT);

        T100VOID                    initItems(wxListCtrl*);

    private:
        wxListCtrl*                 m_listCtrl          = T100NULL;
        wxImageList*                m_imageList         = T100NULL;

        T100VOID                    initImageList();

    private:
        T100VOID                    create();
        T100VOID                    destroy();

        void    OnSelected(wxListEvent& event);

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORENTITYPANEL_H
