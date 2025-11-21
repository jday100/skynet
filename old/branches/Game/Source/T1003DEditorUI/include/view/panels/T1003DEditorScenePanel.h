#ifndef T1003DEDITORSCENEPANEL_H
#define T1003DEDITORSCENEPANEL_H

#include <wx/panel.h>
#include <wx/imaglist.h>
#include "T1003DEditorUICommon.h"
#include "T1003DEditorTreeCtrl.h"
#include "T1003DEditorDocument.h"

#include "T100TreeItemData.h"

class T1003DEditorScenePanel : public wxPanel
{
    public:
        T1003DEditorScenePanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorScenePanel();

        T100VOID                        SetImageList(wxImageList*);

        T100BOOL                        Open(T1003DEditorDocument*);

        T100BOOL                        Append(T100Entity*);
        T100BOOL                        AppendMesh(T100Mesh*);
        T100BOOL                        AppendLight(T100Light*);
        T100BOOL                        Append(T100Camera*);
        T100BOOL                        Append(T100Texture*);
        T100BOOL                        AppendMaterial(T100Material*);

    public:
        static const long ID_SCENE_PANEL_MENU_ENTITY_CREATE;
        static const long ID_SCENE_PANEL_MENU_ENTITY_REMOVE;

        static const long ID_SCENE_PANEL_MENU_MESH_CREATE;
        static const long ID_SCENE_PANEL_MENU_MESH_REMOVE;

        static const long ID_SCENE_PANEL_MENU_CAMERA_CREATE;
        static const long ID_SCENE_PANEL_MENU_CAMERA_REMOVE;

        static const long ID_SCENE_PANEL_MENU_LIGHT_CREATE;
        static const long ID_SCENE_PANEL_MENU_LIGHT_REMOVE;

        static const long ID_SCENE_PANEL_MENU_MATERIAL_CREATE;
        static const long ID_SCENE_PANEL_MENU_MATERIAL_REMOVE;

    protected:
        void OnItemMenuEntityCreate(wxCommandEvent& event);
        void OnItemMenuEntityRemove(wxCommandEvent& event);

        void OnItemMenuMeshCreate(wxCommandEvent& event);
        void OnItemMenuMeshRemove(wxCommandEvent& event);

        void OnItemMenuCameraCreate(wxCommandEvent& event);
        void OnItemMenuCameraRemove(wxCommandEvent& event);

        void OnItemMenuLightCreate(wxCommandEvent& event);
        void OnItemMenuLightRemove(wxCommandEvent& event);

        void OnItemMenuMaterialCreate(wxCommandEvent& event);
        void OnItemMenuMaterialRemove(wxCommandEvent& event);

    protected:
        T1003DEditorTreeCtrl*           m_treeCtrl          = T100NULL;

        void OnTreeCtrlSceneItemSelected(wxTreeEvent& event);
        void OnTreeCtrlSceneItemMenu(wxTreeEvent& event);

        T100VOID                        InitItems(T1003DEditorDocument*);

        wxTreeItemId                    InsertItem(T100Entity*);
        wxTreeItemId                    InsertItemMesh(T100Mesh*);
        wxTreeItemId                    InsertItem(T100Light*);
        wxTreeItemId                    InsertItem(T100Camera*);
        wxTreeItemId                    InsertItem(T100Texture*);
        wxTreeItemId                    InsertItem(T100Material*);

        wxTreeItemId                    InsertItem(wxTreeItemId, T100WSTRING, T1003DEDITOR_SCENE_ITEM_TYPE, T100TreeItemData*, T100BOOL = T100FALSE);
        wxTreeItemId                    InsertItem(wxTreeItemId, T100WSTRING, T1003DEDITOR_SCENE_ITEM_TYPE);
        wxTreeItemId                    InsertItem(wxTreeItemId, T100WSTRING, T100TreeItemData*, T100BOOL = T100FALSE);
        T100TreeItemData*               GetItemData(wxTreeEvent&);
        T100VOID                        DoItem(T100TreeItemData*);

    private:
        T100VOID                        init();
        T100VOID                        uninit();

        wxTreeItemId                    m_entities;
        wxTreeItemId                    m_meshes;
        wxTreeItemId                    m_lights;
        wxTreeItemId                    m_cameras;
        wxTreeItemId                    m_textures;
        wxTreeItemId                    m_materials;

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORSCENEPANEL_H
