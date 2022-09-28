#include "T100DiskBrowseCtrl.h"

#include "T100DiskBrowseData.h"
#include "T100DiskBrowseCreateFolderDialog.h"


const long T100DiskBrowseCtrl::ID_MENU_FOLDER_CREATE = wxNewId();
const long T100DiskBrowseCtrl::ID_MENU_FOLDER_REMOVE = wxNewId();
const long T100DiskBrowseCtrl::ID_MENU_FILE_COPY = wxNewId();
const long T100DiskBrowseCtrl::ID_MENU_FILE_REMOVE = wxNewId();


BEGIN_EVENT_TABLE(T100DiskBrowseCtrl,wxGenericDirCtrl)
    EVT_TREE_ITEM_EXPANDING     (wxID_TREECTRL, T100DiskBrowseCtrl::OnExpandItem)
    EVT_TREE_ITEM_COLLAPSED     (wxID_TREECTRL, T100DiskBrowseCtrl::OnCollapseItem)
    EVT_TREE_BEGIN_LABEL_EDIT   (wxID_TREECTRL, T100DiskBrowseCtrl::OnBeginEditItem)
    EVT_TREE_END_LABEL_EDIT     (wxID_TREECTRL, T100DiskBrowseCtrl::OnEndEditItem)
    EVT_TREE_SEL_CHANGED        (wxID_TREECTRL, T100DiskBrowseCtrl::OnTreeSelChange)
    EVT_TREE_ITEM_ACTIVATED     (wxID_TREECTRL, T100DiskBrowseCtrl::OnItemActivated)
    EVT_SIZE                    (T100DiskBrowseCtrl::OnSize)
    //
    EVT_TREE_BEGIN_DRAG         (wxID_TREECTRL, T100DiskBrowseCtrl::OnTreeBeginDrag)
    EVT_TREE_END_DRAG           (wxID_TREECTRL, T100DiskBrowseCtrl::OnTreeEndDrag)
    EVT_TREE_DELETE_ITEM        (wxID_TREECTRL, T100DiskBrowseCtrl::OnTreeDeleteItem)
    EVT_TREE_ITEM_MENU          (wxID_TREECTRL, T100DiskBrowseCtrl::OnTreeItemMenu)
END_EVENT_TABLE()

T100DiskBrowseCtrl::T100DiskBrowseCtrl(wxWindow* parent)
{
    //ctor
    BuildContent(parent);
}

T100DiskBrowseCtrl::~T100DiskBrowseCtrl()
{
    //dtor
}

void T100DiskBrowseCtrl::BuildContent(wxWindow *parent)
{
    Create(parent);

    Connect(ID_MENU_FOLDER_CREATE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskBrowseCtrl::OnCreateFolder);
    Connect(ID_MENU_FOLDER_REMOVE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskBrowseCtrl::OnRemoveFolder);
    Connect(ID_MENU_FILE_REMOVE, wxEVT_COMMAND_MENU_SELECTED,   (wxObjectEventFunction)&T100DiskBrowseCtrl::OnRemoveFile);
}

T100BOOL T100DiskBrowseCtrl::SetDiskCtrl(T100DiskCtrl* disk)
{
    m_disk = disk;
    return T100TRUE;
}

T100BOOL T100DiskBrowseCtrl::Load()
{
    T100BOOL        result      = T100TRUE;

    wxString    path;
    wxString    name;
    wxInt32     icon;

    path    = _("\\");
    name    = _("Computer");
    icon    = wxFileIconsTable::computer;

    AddSection(path, name, icon);

    if(!m_disk){
        return T100FALSE;
    }

    m_folder_menu.Append(ID_MENU_FOLDER_CREATE, _("Create"));
    m_folder_menu.Append(ID_MENU_FOLDER_REMOVE, _("Remove"));
    m_menu.Append(wxID_ANY, _("Folder"), &m_folder_menu);
    m_file_menu.Append(ID_MENU_FILE_COPY, _("Copy"));
    m_file_menu.Append(ID_MENU_FILE_REMOVE, _("Remove"));
    m_menu.Append(wxID_ANY, _("File"), &m_file_menu);

    //T100DISK_PART_CTRL_VECTOR       parts;

    //result = m_disk->DoGetAllParts(parts);

    T100DISK_PART_CTRL_VECTOR&  parts = m_disk->GetAllParts();

    if(result){
        for(T100DISK_PART_CTRL* item : parts){
            path    = item->PART->NAME.to_wstring();
            name    = item->PART->NAME.to_wstring();
            icon    = wxFileIconsTable::drive;

            AddPart(path, name, icon);
        }
    }


}

wxTreeCtrl* T100DiskBrowseCtrl::CreateTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long treeStyle)
{
    m_tree = new wxTreeCtrl(parent, id, pos, size, treeStyle);
    return m_tree;
}

void T100DiskBrowseCtrl::ExpandDir(wxTreeItemId parentId)
{
    wxTreeItemId    root;

    root = m_tree->GetRootItem();

    if(root.IsOk()){

    }else{
        return;
    }

    if(!m_disk){
        return;
    }

    T100DiskBrowseData*     data;
    T100DISK_ITEM_VECTOR    items;
    wxString                path;
    wxString                name;
    wxInt32                 icon;

    data = GetItemData(parentId);

    if(data){
        if(data->isPart()){
            m_disk->DoGetAllItems(data->part, _(":"), items);
        }else{
            m_disk->DoGetAllItems(data->part, data->m_path, items);
        }

        for(T100DISK_ITEM* item : items){
            if(item->ISDIR){
                path    = item->NAME.to_wstring();
                name    = item->NAME.to_wstring();
                icon    = wxFileIconsTable::folder;
            }else{
                path    = L"";
                name    = item->NAME.to_wstring();
                icon    = wxFileIconsTable::file;
            }

            AddItem(parentId, path, name, icon);
        }
    }
}

T100DiskBrowseData* T100DiskBrowseCtrl::GetItemData(wxTreeItemId id)
{
    return static_cast<T100DiskBrowseData*>(m_tree->GetItemData(id));
}

wxTreeItemId T100DiskBrowseCtrl::AddPart(wxString& path, wxString& name, int icon)
{
    T100DiskBrowseData*     data = T100NEW T100DiskBrowseData(path, name, icon);

    data->setPart(T100TRUE);
    data->part = name;

    m_root_id = m_tree->GetRootItem();

    wxTreeItemId    treeid = m_tree->AppendItem(m_root_id, name, icon, -1, data);
    m_tree->SetItemHasChildren(treeid);

    return treeid;
}

wxTreeItemId T100DiskBrowseCtrl::AddItem(wxTreeItemId parentId, wxString& path, wxString& name, int icon)
{
    T100DiskBrowseData*     data = T100NEW T100DiskBrowseData(path, name, T100TRUE);

    data->setPart(T100FALSE);
    data->part = name;

    wxTreeItemId    treeid = m_tree->AppendItem(parentId, name, icon, -1, data);
    m_tree->SetItemHasChildren(treeid);

    return treeid;
}

void T100DiskBrowseCtrl::ShowMenu()
{
    m_tree->PopupMenu(&m_menu);
}

///

void T100DiskBrowseCtrl::OnExpandItem(wxTreeEvent& event)
{
    wxTreeItemId parentId = event.GetItem();

    T100DiskBrowseData*     data;
    T100DISK_ITEM_VECTOR    items;
    wxString                path;
    wxString                name;
    wxInt32                 icon;

    data = GetItemData(parentId);

    if(data){
        if(data->isPart()){
            m_disk->DoGetAllItems(data->part, _(":"), items);
        }else{
            m_disk->DoGetAllItems(data->part, data->m_path, items);
        }

        for(T100DISK_ITEM* item : items){
            if(item->ISDIR){
                path    = item->NAME.to_wstring();
                name    = item->NAME.to_wstring();
                icon    = wxFileIconsTable::folder;
            }else{
                path    = L"";
                name    = item->NAME.to_wstring();
                icon    = wxFileIconsTable::file;
            }

            AddItem(parentId, path, name, icon);
        }
    }

}

void T100DiskBrowseCtrl::OnCollapseItem(wxTreeEvent& event)
{

}

void T100DiskBrowseCtrl::OnBeginEditItem(wxTreeEvent& event)
{

}

void T100DiskBrowseCtrl::OnEndEditItem(wxTreeEvent& event)
{

}

void T100DiskBrowseCtrl::OnTreeSelChange(wxTreeEvent& event)
{
    m_current = event.GetItem();
}

void T100DiskBrowseCtrl::OnSize(wxSizeEvent& event)
{
    DoResize();
}

void T100DiskBrowseCtrl::OnTreeBeginDrag(wxTreeEvent& event)
{

}

void T100DiskBrowseCtrl::OnTreeEndDrag(wxTreeEvent& event)
{

}

void T100DiskBrowseCtrl::OnTreeDeleteItem(wxTreeEvent& event)
{

}

void T100DiskBrowseCtrl::OnTreeItemMenu(wxTreeEvent& event)
{
    ShowMenu();
}

void T100DiskBrowseCtrl::OnCreateFolder(wxCommandEvent& event)
{
    T100BOOL            result          = T100TRUE;

    T100DiskBrowseCreateFolderDialog        dialog(this);

    if(dialog.ShowModal() == wxID_OK){
        T100DISK_ITEM       item;

        item.NAME   = dialog.FolderTextCtrl->GetValue().ToStdWstring();
        item.ISDIR  = T100TRUE;

        result = m_disk->DoCreateFolder(&item);

        if(result){
            wxString    name;
            wxString    path;

            name = item.NAME.to_wstring();
            path = item.NAME.to_wstring();
            result = AddItem(m_current, name, path, wxFileIconsTable::folder);
        }
    }

}

void T100DiskBrowseCtrl::OnRemoveFolder(wxCommandEvent& event)
{
    T100BOOL            result          = T100TRUE;

    wxMessageDialog     dialog(this, _("Are you sure?"));

    if(dialog.ShowModal() == wxID_OK){
        T100DISK_ITEM       item;

        result = m_disk->DoRemoveFolder(&item);
    }
}

void T100DiskBrowseCtrl::OnRemoveFile(wxCommandEvent& event)
{
    T100BOOL            result          = T100TRUE;

    wxMessageDialog     dialog(this, _("Are you sure?"));

    if(dialog.ShowModal() == wxID_OK){
        T100DISK_ITEM       item;

        result = m_disk->DoRemoveFile(&item);
    }
}

