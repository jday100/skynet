#ifndef T1003DEDITORPROPERTIESPANEL_H
#define T1003DEDITORPROPERTIESPANEL_H

#include <wx/panel.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"
#include "link/T1003DCamera.h"
#include "link/T1003DLight.h"

#include "view/grids/T1003DEditorEntityGrid.h"

class T1003DEditorPropertiesPanel : public wxPanel
{
    public:
        T1003DEditorPropertiesPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorPropertiesPanel();

        T100VOID                        Update(T100INT, T100Entity*);

        T100VOID                        Update(T1003DCamera*);
        T100VOID                        Update(T1003DLight*);

        T100VOID                        Clear();

    protected:
        wxPropertyGrid*                 m_propertyGrid      = T100NULL;

        T1003DEditorEntityGrid*         m_entityGridPtr     = T100NULL;

        T100VOID                        loadDotGrid(T100Entity*);
        T100VOID                        loadLineGrid(T100Entity*);
        T100VOID                        loadTriangleGrid(T100Entity*);
        T100VOID                        loadPlaneGrid(T100Entity*);
        T100VOID                        loadCityGrid(T100Entity*);

        T100VOID                        loadCameraGrid(T1003DCamera*);
        T100VOID                        loadLightGrid(T1003DLight*);

        void                            OnPGChanged(wxPropertyGridEvent& event);

    protected:
        wxBoxSizer*                     m_sizer         = T100NULL;

    private:
        T100VOID                        init();
        T100VOID                        uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORPROPERTIESPANEL_H
