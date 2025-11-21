#ifndef T1003DEDITORPROPERTIESPANEL_H
#define T1003DEDITORPROPERTIESPANEL_H

#include <wx/panel.h>
#include "T1003DEditorGridBase.h"
#include "T1003DEditorAllGrids.h"

class T100Mesh;
class T100Scene;
class T100Camera;
class T100Light;
class T100Material;

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

        T100VOID                        Clear();

        T100VOID                        Update(T100INT, T100Entity*);

        T100VOID                        UpdateMesh(T100Mesh*);
        T100VOID                        Update(T100Scene*);
        T100VOID                        Update(T100Camera*);
        T100VOID                        Update(T100Light*);
        T100VOID                        Update(T100Material*);

    protected:
        wxPropertyGrid*                 m_propertyGrid      = T100NULL;
        T1003DEditorGridBase*           m_gridPtr           = T100NULL;

        T100VOID                        loadDotGrid(T100Entity*);
        T100VOID                        loadLineGrid(T100Entity*);
        T100VOID                        loadTriangleGrid(T100Entity*);
        T100VOID                        loadPlaneGrid(T100Entity*);
        T100VOID                        loadMeshGrid(T100Entity*);
        T100VOID                        loadCityGrid(T100Entity*);
        T100VOID                        loadSphereGrid(T100Entity*);
        T100VOID                        loadRectangleGrid(T100Entity*);

        T100VOID                        loadSceneGrid(T100Scene*);
        T100VOID                        loadCameraGrid(T100Camera*);
        T100VOID                        loadLightGrid(T100Light*);
        T100VOID                        loadMaterialGrid(T100Material*);

        void                            OnPGChanged(wxPropertyGridEvent& event);

    protected:
        wxBoxSizer*                     m_sizer         = T100NULL;
        wxButton*                       m_buttonCancel  = T100NULL;
        wxButton*                       m_buttonConfirm = T100NULL;

        static const long ID_BUTTON_CANCEL;
        static const long ID_BUTTON_CONFIRM;

        void OnButtonCancelClick(wxCommandEvent& event);
        void OnButtonConfirmClick(wxCommandEvent& event);

    private:
        T100VOID                        init();
        T100VOID                        uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORPROPERTIESPANEL_H
