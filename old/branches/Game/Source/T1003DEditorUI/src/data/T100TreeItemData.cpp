#include "T100TreeItemData.h"

#include <wx/menu.h>
#include "T1003DEditorScenePanel.h"

T100TreeItemData::T100TreeItemData() :
    wxTreeItemData()
{
    //ctor
}

T100TreeItemData::~T100TreeItemData()
{
    //dtor
}

T100VOID T100TreeItemData::ShowMenu(wxTreeCtrl* parent)
{

    switch(Type){
    case T100SCENE_ITEM_CATEGORY_ENTITY:
        {
            ShowEntityCategoryMenu(parent);
        }
        break;
    case T100SCENE_ITEM_ENTITY:
        {
            ShowEntityMenu(parent);
        }
        break;
    case T100SCENE_ITEM_CATEGORY_MESH:
        {
            ShowMeshCategoryMenu(parent);
        }
        break;
    case T100SCENE_ITEM_MESH:
        {
            ShowMeshMenu(parent);
        }
        break;
    case T100SCENE_ITEM_CATEGORY_CAMERA:
        {
            ShowCameraCategoryMenu(parent);
        }
        break;
    case T100SCENE_ITEM_CAMERA:
        {
            ShowCameraMenu(parent);
        }
        break;
    case T100SCENE_ITEM_CATEGORY_LIGHT:
        {
            ShowLightCategoryMenu(parent);
        }
        break;
    case T100SCENE_ITEM_LIGHT:
        {
            ShowLightMenu(parent);
        }
        break;
    case T100SCENE_ITEM_CATEGORY_MATERIAL:
        {
            ShowMaterialCategoryMenu(parent);
        }
        break;
    case T100SCENE_ITEM_MATERIAL:
        {
            ShowMaterialMenu(parent);
        }
        break;
    }



}

T100VOID T100TreeItemData::ShowEntityCategoryMenu(wxTreeCtrl* parent)
{

}

T100VOID T100TreeItemData::ShowMeshCategoryMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MESH_CREATE, wxT("Create"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowCameraCategoryMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_CAMERA_CREATE, wxT("Create"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowLightCategoryMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_LIGHT_CREATE, wxT("Create"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowMaterialCategoryMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MATERIAL_CREATE, wxT("Create"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowEntityMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_ENTITY_REMOVE, wxT("Remove"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowMeshMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MESH_REMOVE, wxT("Remove"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowCameraMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_CAMERA_REMOVE, wxT("Remove"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowLightMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_LIGHT_REMOVE, wxT("Remove"));

    parent->PopupMenu(menu);
}

T100VOID T100TreeItemData::ShowMaterialMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MATERIAL_REMOVE, wxT("Remove"));

    parent->PopupMenu(menu);
}
