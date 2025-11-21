#ifndef T1003DEDITORSCENEPANEL_H
#define T1003DEDITORSCENEPANEL_H

#include <wx/panel.h>
#include <wx/imaglist.h>
#include "T1003DEditorUICommon.h"
#include "view/ctrls/T1003DEditorTreeCtrl.h"
#include "data/T1003DEditorDocument.h"

#include "data/T100TreeItemData.h"

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

        T100VOID                        Clear();

        T100BOOL                        Append(T100Entity*);
        T100BOOL                        Append(T1003DMesh*);
        T100BOOL                        Append(T1003DLight*);
        T100BOOL                        Append(T1003DCamera*);
        T100BOOL                        Append(T1003DTexture*);

    public:
        static const long ID_SCENE_PANEL_MENU_ENTITY_CREATE;
        static const long ID_SCENE_PANEL_MENU_ENTITY_REMOVE;

        static const long ID_SCENE_PANEL_MENU_MESH_CREATE;
        static const long ID_SCENE_PANEL_MENU_MESH_REMOVE;

        static const long ID_SCENE_PANEL_MENU_CAMERA_CREATE;
        static const long ID_SCENE_PANEL_MENU_CAMERA_REMOVE;

        static const long ID_SCENE_PANEL_MENU_LIGHT_CREATE;
        static const long ID_SCENE_PANEL_MENU_LIGHT_REMOVE;

    protected:
        void OnItemMenuEntityCreate(wxCommandEvent& event);
        void OnItemMenuEntityRemove(wxCommandEvent& event);

        void OnItemMenuMeshCreate(wxCommandEvent& event);
        void OnItemMenuMeshRemove(wxCommandEvent& event);

        void OnItemMenuCameraCreate(wxCommandEvent& event);
        void OnItemMenuCameraRemove(wxCommandEvent& event);

        void OnItemMenuLightCreate(wxCommandEvent& event);
        void OnItemMenuLightRemove(wxCommandEvent& event);

    protected:
        T1003DEditorTreeCtrl*           m_treeCtrl          = T100NULL;

        void OnTreeCtrlSceneItemSelected(wxTreeEvent& event);
        void OnTreeCtrlSceneItemMenu(wxTreeEvent& event);

        T100VOID                        InitItems();

        wxTreeItemId                    InsertItem(T100Entity*);
        wxTreeItemId                    InsertItem(T1003DLight*);
        wxTreeItemId                    InsertItem(T1003DCamera*);
        wxTreeItemId                    InsertItem(T1003DTexture*);

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

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORSCENEPANEL_H
