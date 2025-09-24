#include "T100ProjectTree.h"

#include "T100ProjectCommon.h"
#include "T100FileData.h"
#include "T100FolderData.h"
#include "T100ProjectData.h"
#include "T100WorkSpaceData.h"
#include "T100ProjectInvoking.h"

BEGIN_EVENT_TABLE(T100ProjectTree, wxTreeCtrl)
    EVT_RIGHT_DOWN(OnMouseRightDown)

    EVT_TREE_ITEM_MENU(wxID_ANY, OnItemMenu)
    EVT_TREE_SEL_CHANGED(wxID_ANY, OnItemChanged)
    EVT_TREE_ITEM_EXPANDING(wxID_ANY, OnItemExpanding)
    EVT_TREE_ITEM_ACTIVATED(wxID_ANY, OnItemActivated)

    EVT_MENU(T100PROJECT_TREE_MENU_PROJECT_NEW, OnProjectCreate)
    EVT_MENU(T100PROJECT_TREE_MENU_MODULE_NEW, OnModuleCreate)
END_EVENT_TABLE()

T100ProjectTree::T100ProjectTree(wxWindow *parent, wxWindowID id,
               const wxPoint& pos,
               const wxSize& size,
               long style,
               const wxValidator& validator,
               const wxString& name) :
    wxTreeCtrl(parent, id, pos, size, style, validator, name)
{
    //ctor
}

T100ProjectTree::~T100ProjectTree()
{
    //dtor
}

T100BOOL T100ProjectTree::WorkSpaceOpen(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    DeleteAllItems();

    wxTreeItemId        root        = AppendRoot(info);

    for(T100ProjectInfo* item : info->GetProjects()){
        AppendProject(root, item);
    }

    for(T100FolderInfo* item : info->GetSubFolders()){
        AppendFolder(root, item);
    }

    for(T100FileInfo* item : info->GetFiles()){
        AppendFile(root, item);
    }

    Expand(root);
    return T100TRUE;
}


T100BOOL T100ProjectTree::ProjectAppend(T100ProjectInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    wxTreeItemId        root        = GetRootItem();
    wxTreeItemId        item;

    if(root.IsOk()){

    }else{
        return T100FALSE;
    }

    item    = AppendProject(root, info);

    if(item.IsOk()){
        Expand(root);
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectTree::ProjectOpen(wxTreeItemId id, T100ProjectInfo* info)
{
    if(id.IsOk() && info){

    }else{
        return T100FALSE;
    }

    T100ProjectData*        data        = dynamic_cast<T100ProjectData*>(GetItemData(id));

    if(!data){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&       files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&     folders     = info->GetSubFolders();

    for(T100FolderInfo* folder : folders){
        AppendFolder(id, folder);
    }

    for(T100FileInfo* file : files){
        AppendFile(id, file);
    }

    data->SetOpened(T100TRUE);
    Expand(id);
    return T100TRUE;
}

T100BOOL T100ProjectTree::FolderList(wxTreeItemId id, T100FolderInfo* info)
{
    T100FolderData*         data        = dynamic_cast<T100FolderData*>(GetItemData(id));

    if(!data){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&       files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&     folders     = info->GetSubFolders();


    for(T100FolderInfo* folder : folders){
        AppendFolder(id, folder);
    }

    for(T100FileInfo* file : files){
        AppendFile(id, file);
    }

    data->SetOpened(T100TRUE);

    Expand(id);
}

T100BOOL T100ProjectTree::ModuleAppend(T100WorkSpaceInfo* workspace, T100ProjectInfo* project, T100ModuleInfo* module)
{
    if(workspace && project && module){

    }else{
        return T100FALSE;
    }

    AppendFile(project->GetIncludeTreeId(), module->GetIncludeFile());
    AppendFile(project->GetSourceTreeId(), module->GetSourceFile());

    return T100TRUE;
}

T100BOOL T100ProjectTree::Remove(wxTreeItemId id)
{
    if(id.IsOk()){

    }else{
        return T100FALSE;
    }

    Delete(id);
    return T100TRUE;
}

T100BOOL T100ProjectTree::Clear()
{
    DeleteAllItems();
    return T100TRUE;
}

T100VOID T100ProjectTree::OnMouseRightDown(wxMouseEvent& event)
{
    wxTreeItemId        item        = GetSelection();

    if(item.IsOk()){
        T100TreeItemData*       data        = dynamic_cast<T100TreeItemData*>(GetItemData(item));

        if(!data){
            return;
        }

        PopupMenu(data->CreateMenu());
    }else{
        T100ProjectInvoking::OnWorkSpaceMouseRightDown();
    }
}

T100VOID T100ProjectTree::OnItemMenu(wxTreeEvent& event)
{
    T100TreeItemData*       data        = dynamic_cast<T100TreeItemData*>(event.GetClientObject());

    if(!data){
        return;
    }

    PopupMenu(data->CreateMenu());
}

T100VOID T100ProjectTree::OnItemChanged(wxTreeEvent& event)
{
    T100TreeItemData*       data        = dynamic_cast<T100TreeItemData*>(event.GetClientObject());

    if(!data){
        return;
    }

    data->OnItemChanged();
}

T100VOID T100ProjectTree::OnItemExpanding(wxTreeEvent& event)
{
    T100TreeItemData*       data        = dynamic_cast<T100TreeItemData*>(event.GetClientObject());

    if(!data){
        return;
    }

    data->OnItemExpanding();

    T100ProjectInvoking::OnDebugPrint(L"Expanding");
}

T100VOID T100ProjectTree::OnItemActivated(wxTreeEvent& event)
{
    T100TreeItemData*       data        = dynamic_cast<T100TreeItemData*>(event.GetClientObject());

    if(!data){
        return;
    }

    data->OnItemActivated();

    T100ProjectInvoking::OnDebugPrint(L"Activated");

    event.Skip();
}

T100VOID T100ProjectTree::OnProjectCreate(wxCommandEvent& event)
{
    T100ProjectInvoking::OnProjectCreate();
}

T100VOID T100ProjectTree::OnModuleCreate(wxCommandEvent& event)
{
    T100ProjectInvoking::OnModuleCreate();
}

T100VOID T100ProjectTree::ShowWorkSpacePopupMenu(T100BOOL value)
{
    if(value){
        PopupMenu(GetWorkSpaceItemMenu());
    }else{
        PopupMenu(GetWorkSpaceMenu());
    }
}

wxTreeItemId T100ProjectTree::AppendRoot(T100WorkSpaceInfo* info)
{
    wxTreeItemId            result;

    if(!info){
        return result;
    }

    T100WorkSpaceData*      data        = T100NEW T100WorkSpaceData(info);

    result  = AddRoot(L"WorkSpace", 0, -1, data);

    if(result.IsOk()){

    }else{
        T100SAFE_DELETE(data);
    }

    return result;
}

wxTreeItemId T100ProjectTree::AppendProject(wxTreeItemId parent, T100ProjectInfo* info)
{
    wxTreeItemId        item;

    if(!info){
        return item;
    }

    T100ProjectData*        data        = T100NEW T100ProjectData(info);

    item    = AppendItem(parent, info->GetLabel(), 5, -1, data);

    if(item.IsOk()){
        data->SetId(item);
        SetItemHasChildren(item, T100TRUE);
    }else{
        T100SAFE_DELETE(data);
    }
    return item;
}

wxTreeItemId T100ProjectTree::AppendFile(wxTreeItemId parent, T100FileInfo* info)
{
    wxTreeItemId        item;

    if(!info){
        return item;
    }

    T100FileData*       data        = T100NEW T100FileData(info);

    item    = AppendItem(parent, info->GetLabel(), 10, -1, data);

    if(item.IsOk()){
        data->SetId(item);
    }else{
        T100SAFE_DELETE(data);
    }
    return item;
}

wxTreeItemId T100ProjectTree::AppendFolder(wxTreeItemId parent, T100FolderInfo* info)
{
    wxTreeItemId        item;

    if(!info){
        return item;
    }

    T100FolderData*     data        = T100NEW T100FolderData(info);

    item    = AppendItem(parent, info->GetLabel(), 5, -1, data);

    if(item.IsOk()){
        data->SetId(item);
        SetItemHasChildren(item, T100TRUE);
    }else{
        T100SAFE_DELETE(data);
    }
    return item;
}

wxMenu* T100ProjectTree::GetWorkSpaceMenu()
{
    wxMenu*         menu    = T100NEW wxMenu();
    wxMenu*         work    = T100NEW wxMenu();

    work->Append(T100PROJECT_MENU_WORKSPACE_NEW, L"New");
    work->Append(T100PROJECT_MENU_WORKSPACE_OPEN, L"Open");

    menu->AppendSubMenu(work, L"WorkSpace");

    return menu;
}

wxMenu* T100ProjectTree::GetWorkSpaceItemMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();
    wxMenu*     project = T100NEW wxMenu();

    menu->AppendSubMenu(project, L"Project");
    project->Append(T100PROJECT_TREE_MENU_PROJECT_NEW, L"New");

    menu->Append(T100PROJECT_TREE_MENU_WORKSPACE_PROPERTIES, L"Properties...");

    return menu;
}
