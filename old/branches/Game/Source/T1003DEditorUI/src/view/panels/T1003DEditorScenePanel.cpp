#include "T1003DEditorScenePanel.h"

#include <wx/sizer.h>
#include "T100TreeItemData.h"
#include "T1003DEditorCallback.h"

#include "entity/T100Entity.h"
#include "entity/T100Mesh.h"
#include "data/T100Light.h"
#include "data/T100Camera.h"
#include "data/T100Texture.h"
#include "data/T100Material.h"


const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_ENTITY_CREATE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_ENTITY_REMOVE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MESH_CREATE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MESH_REMOVE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_CAMERA_CREATE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_CAMERA_REMOVE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_LIGHT_CREATE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_LIGHT_REMOVE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MATERIAL_CREATE = wxNewId();
const long T1003DEditorScenePanel::ID_SCENE_PANEL_MENU_MATERIAL_REMOVE = wxNewId();

BEGIN_EVENT_TABLE(T1003DEditorScenePanel,wxPanel)
    EVT_TREE_SEL_CHANGED(wxID_ANY, T1003DEditorScenePanel::OnTreeCtrlSceneItemSelected)
    EVT_TREE_ITEM_MENU(wxID_ANY, T1003DEditorScenePanel::OnTreeCtrlSceneItemMenu)
END_EVENT_TABLE()

T1003DEditorScenePanel::T1003DEditorScenePanel(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name) :
    wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
    init();
}

T1003DEditorScenePanel::~T1003DEditorScenePanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorScenePanel::init()
{
    m_treeCtrl  = T100NEW T1003DEditorTreeCtrl(this);

    wxBoxSizer* sizer   = T100NEW wxBoxSizer(wxHORIZONTAL);

    sizer->Add(m_treeCtrl, 1, wxALL | wxEXPAND, 5);
    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

}

T100VOID T1003DEditorScenePanel::uninit()
{
    T100SAFE_DELETE m_treeCtrl;
}

T100VOID T1003DEditorScenePanel::SetImageList(wxImageList* imageList)
{
    //m_treeCtrl->SetImageList(imageList);
}

T100BOOL T1003DEditorScenePanel::Open(T1003DEditorDocument* document)
{
    InitItems(document);

    T100ENTITY_VECTOR&      entities    = document->GetEntities();
    T100ENTITY_VECTOR&      meshes      = document->GetMeshes();
    T100LIGHT_VECTOR&       lights      = document->GetLights();
    T100MATERIAL_VECTOR&    materials   = document->GetMaterials();

    for(T100Entity* entity : entities){
        Append(entity);
    }

    for(T100Entity* entity : meshes){
        T100Mesh*   mesh    = dynamic_cast<T100Mesh*>(entity);
        AppendMesh(mesh);
    }

    for(T100Light* light : lights){
        AppendLight(light);
    }

    for(T100Material* material : materials){
        AppendMaterial(material);
    }
}

T100VOID T1003DEditorScenePanel::InitItems(T1003DEditorDocument* document)
{
    m_treeCtrl->DeleteAllItems();

    T100TreeItemData*   data    = T100NEW T100TreeItemData();

    data->Scene     = &document->GetScene();

    T1003DEditorCallback::UpdateScene(&document->GetScene());

    wxTreeItemId        root    = InsertItem(0, L"Scene", T100SCENE_ITEM_CATEGORY_ROOT, data, T100TRUE);

    m_entities  = InsertItem(root, L"Entities", T100SCENE_ITEM_CATEGORY_ENTITY);

    m_meshes    = InsertItem(root, L"Meshes", T100SCENE_ITEM_CATEGORY_MESH);
    m_lights    = InsertItem(root, L"Ligths", T100SCENE_ITEM_CATEGORY_LIGHT);
    m_cameras   = InsertItem(root, L"Cameras", T100SCENE_ITEM_CATEGORY_CAMERA);
    m_textures  = InsertItem(root, L"Textures", T100SCENE_ITEM_CATEGORY_TEXTURE);
    m_materials = InsertItem(root, L"Materials", T100SCENE_ITEM_CATEGORY_MATERIAL);
    InsertItem(root, L"Audio", T100SCENE_ITEM_CATEGORY_AUDIO);
    InsertItem(root, L"Video", T100SCENE_ITEM_CATEGORY_VIDEO);
    InsertItem(root, L"Samplers", T100SCENE_ITEM_CATEGORY_SAMPLER);

    m_treeCtrl->Expand(root);

    Connect(ID_SCENE_PANEL_MENU_ENTITY_CREATE,      wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuEntityCreate);
    Connect(ID_SCENE_PANEL_MENU_ENTITY_REMOVE,      wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuEntityRemove);
    Connect(ID_SCENE_PANEL_MENU_MESH_CREATE,        wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuMeshCreate);
    Connect(ID_SCENE_PANEL_MENU_MESH_REMOVE,        wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuMeshRemove);
    Connect(ID_SCENE_PANEL_MENU_CAMERA_CREATE,      wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuCameraCreate);
    Connect(ID_SCENE_PANEL_MENU_CAMERA_REMOVE,      wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuCameraRemove);
    Connect(ID_SCENE_PANEL_MENU_LIGHT_CREATE,       wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuLightCreate);
    Connect(ID_SCENE_PANEL_MENU_LIGHT_REMOVE,       wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuLightRemove);
    Connect(ID_SCENE_PANEL_MENU_MATERIAL_CREATE,    wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuMaterialCreate);
    Connect(ID_SCENE_PANEL_MENU_MATERIAL_REMOVE,    wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T1003DEditorScenePanel::OnItemMenuMaterialRemove);

}


void T1003DEditorScenePanel::OnItemMenuEntityCreate(wxCommandEvent& event)
{

}

void T1003DEditorScenePanel::OnItemMenuEntityRemove(wxCommandEvent& event)
{
    T100TreeItemData*   data    = (T100TreeItemData*)m_treeCtrl->GetItemData(m_treeCtrl->GetSelection());
    if(data){
        T1003DEditorCallback::Remove(data->Entity);

        m_treeCtrl->Delete(m_treeCtrl->GetSelection());
        T1003DEditorCallback::SetDirty();
    }
}

void T1003DEditorScenePanel::OnItemMenuMeshCreate(wxCommandEvent& event)
{
    T1003DEditorCallback::AppendMesh();
}

void T1003DEditorScenePanel::OnItemMenuMeshRemove(wxCommandEvent& event)
{
    T100TreeItemData*   data    = (T100TreeItemData*)m_treeCtrl->GetItemData(m_treeCtrl->GetSelection());
    if(data){
        T1003DEditorCallback::Remove(data->Entity);

        m_treeCtrl->Delete(m_treeCtrl->GetSelection());
        T1003DEditorCallback::SetDirty();
    }
}

void T1003DEditorScenePanel::OnItemMenuCameraCreate(wxCommandEvent& event)
{
    T1003DEditorCallback::AppendCamera();
}

void T1003DEditorScenePanel::OnItemMenuCameraRemove(wxCommandEvent& event)
{
    T100TreeItemData*   data    = (T100TreeItemData*)m_treeCtrl->GetItemData(m_treeCtrl->GetSelection());
    if(data){
        //T1003DEditorCallback::Remove(data->Entity);

        m_treeCtrl->Delete(m_treeCtrl->GetSelection());
        T1003DEditorCallback::SetDirty();
    }
}

void T1003DEditorScenePanel::OnItemMenuLightCreate(wxCommandEvent& event)
{
    T1003DEditorCallback::AppendLight();
}

void T1003DEditorScenePanel::OnItemMenuLightRemove(wxCommandEvent& event)
{
    T100TreeItemData*   data    = (T100TreeItemData*)m_treeCtrl->GetItemData(m_treeCtrl->GetSelection());
    if(data){
        //T1003DEditorCallback::Remove(data->Entity);

        m_treeCtrl->Delete(m_treeCtrl->GetSelection());
        T1003DEditorCallback::SetDirty();
    }
}

void T1003DEditorScenePanel::OnItemMenuMaterialCreate(wxCommandEvent& event)
{
    T1003DEditorCallback::AppendMaterial();
}

void T1003DEditorScenePanel::OnItemMenuMaterialRemove(wxCommandEvent& event)
{
    T100TreeItemData*   data    = (T100TreeItemData*)m_treeCtrl->GetItemData(m_treeCtrl->GetSelection());
    if(data){
        //T1003DEditorCallback::Remove(data->Entity);

        m_treeCtrl->Delete(m_treeCtrl->GetSelection());
        T1003DEditorCallback::SetDirty();
    }
}

void T1003DEditorScenePanel::OnTreeCtrlSceneItemSelected(wxTreeEvent& event)
{
    T100TreeItemData*   data    = GetItemData(event);

    if(data){
        DoItem(data);
    }
}

void T1003DEditorScenePanel::OnTreeCtrlSceneItemMenu(wxTreeEvent& event)
{
    T100TreeItemData*   data    = GetItemData(event);

    if(data){
        data->ShowMenu(m_treeCtrl);
    }
}

T100BOOL T1003DEditorScenePanel::Append(T100Entity* entity)
{
    InsertItem(entity);
}

T100BOOL T1003DEditorScenePanel::AppendMesh(T100Mesh* meshPtr)
{
    InsertItemMesh(meshPtr);
}

T100BOOL T1003DEditorScenePanel::AppendLight(T100Light* light)
{
    InsertItem(light);
}

T100BOOL T1003DEditorScenePanel::Append(T100Camera* camera)
{
    InsertItem(camera);
}

T100BOOL T1003DEditorScenePanel::Append(T100Texture* texture)
{
    InsertItem(texture);
}

T100BOOL T1003DEditorScenePanel::AppendMaterial(T100Material* material)
{
    InsertItem(material);
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(T100Entity* entity)
{
    T100TreeItemData*   data    = T100NEW T100TreeItemData();

    data->Type      = T100SCENE_ITEM_ENTITY;
    data->Entity    = entity;

    return InsertItem(m_entities, entity->Name, data);
}

wxTreeItemId T1003DEditorScenePanel::InsertItemMesh(T100Mesh* meshPtr)
{
    T100TreeItemData*   data    = T100NEW T100TreeItemData();

    data->Type      = T100SCENE_ITEM_MESH;
    data->Mesh      = meshPtr;

    T100Entity*     entity;

    entity      = meshPtr;

    return InsertItem(m_meshes, entity->Name, data);
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(T100Light* light)
{
    T100TreeItemData*   data    = T100NEW T100TreeItemData();
    T100Entity*         entity;

    entity  = light;

    data->Type      = T100SCENE_ITEM_LIGHT;
    data->Light     = light;

    return InsertItem(m_lights, entity->Name, data);
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(T100Camera* camera)
{
    T100TreeItemData*   data    = T100NEW T100TreeItemData();

    data->Type      = T100SCENE_ITEM_CAMERA;
    data->Camera    = camera;

    return InsertItem(m_cameras, camera->Name, data);
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(T100Texture* texture)
{
    T100TreeItemData*   data    = T100NEW T100TreeItemData();

    data->Type      = T100SCENE_ITEM_TEXTURE;
    data->Texture   = texture;

    return InsertItem(m_textures, texture->Name, data);
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(T100Material* material)
{
    T100TreeItemData*   data    = T100NEW T100TreeItemData();

    data->Type      = T100SCENE_ITEM_MATERIAL;
    data->Material  = material;

    return InsertItem(m_materials, material->Name, data);
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(wxTreeItemId id, T100WSTRING name, T1003DEDITOR_SCENE_ITEM_TYPE type, T100TreeItemData* data, T100BOOL bold)
{
    wxTreeItemId    item;

    item    = m_treeCtrl->AppendItem(id, name);

    data->Type  = type;

    m_treeCtrl->SetItemData(item, data);

    if(bold){
        m_treeCtrl->SetItemBold(item);
    }

    return item;
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(wxTreeItemId id, T100WSTRING name, T1003DEDITOR_SCENE_ITEM_TYPE type)
{
    wxTreeItemId    item;

    item    = m_treeCtrl->AppendItem(id, name);

    T100TreeItemData*   data    = T100NEW T100TreeItemData();

    data->Type  = type;

    m_treeCtrl->SetItemData(item, data);

    m_treeCtrl->SetItemBold(item);

    return item;
}

wxTreeItemId T1003DEditorScenePanel::InsertItem(wxTreeItemId id, T100WSTRING name, T100TreeItemData* data, T100BOOL bold)
{
    wxTreeItemId    item;

    item    = m_treeCtrl->AppendItem(id, name);

    m_treeCtrl->SetItemData(item, data);

    if(bold){
        m_treeCtrl->SetItemBold(item);
    }

    return item;
}


T100TreeItemData* T1003DEditorScenePanel::GetItemData(wxTreeEvent& event)
{
    T100TreeItemData*       item        = T100NULL;
    wxTreeItemId            current;

    current = event.GetItem();

    if(current.IsOk()){
        wxTreeItemData*     data        = T100NULL;

        data    = m_treeCtrl->GetItemData(current);

        if(data){
            item    = dynamic_cast<T100TreeItemData*>(data);
        }
    }

    return item;
}

T100VOID T1003DEditorScenePanel::DoItem(T100TreeItemData* data)
{
    switch(data->Type){
    case T100SCENE_ITEM_CATEGORY_ROOT:
        {
            T1003DEditorCallback::Update(data->Scene);
        }
        break;
    case T100SCENE_ITEM_ENTITY:
        {
            T1003DEditorCallback::Update(data->Entity);
        }
        break;
    case T100SCENE_ITEM_MESH:
        {
            T1003DEditorCallback::UpdateMesh(data->Mesh);
        }
        break;
    case T100SCENE_ITEM_CAMERA:
        {
            T1003DEditorCallback::Update(data->Camera);
        }
        break;
    case T100SCENE_ITEM_LIGHT:
        {
            T1003DEditorCallback::Update(data->Light);
        }
        break;
    case T100SCENE_ITEM_MATERIAL:
        {
            T1003DEditorCallback::Update(data->Material);
        }
        break;
    default:
        {
            T1003DEditorCallback::Clear();
        }
    }
}
