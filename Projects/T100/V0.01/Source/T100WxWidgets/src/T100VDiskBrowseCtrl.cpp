#include "T100VDiskBrowseCtrl.h"

BEGIN_EVENT_TABLE(T100VDiskBrowseCtrl,wxGenericDirCtrl)
END_EVENT_TABLE()

T100VDiskBrowseCtrl::T100VDiskBrowseCtrl(wxWindow* parent)
{
    //ctor
    BuildContent(parent);
}

T100VDiskBrowseCtrl::~T100VDiskBrowseCtrl()
{
    //dtor
}

void T100VDiskBrowseCtrl::BuildContent(wxWindow *parent)
{
    Create(parent);
}

T100BOOL T100VDiskBrowseCtrl::SetDiskCtrl(T100DiskCtrl* disk)
{
    m_disk = disk;
    return T100TRUE;
}

T100BOOL T100VDiskBrowseCtrl::Load()
{
    wxString    path;
    wxString    name;
    wxInt32     icon;

    path    = _("\\");
    name    = _("Computer");
    icon    = wxFileIconsTable::computer;

    AddSection(path, name, icon);
}

wxTreeCtrl* T100VDiskBrowseCtrl::CreateTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long treeStyle)
{
    m_tree = new wxTreeCtrl(parent, id, pos, size, treeStyle);
    return m_tree;
}

void T100VDiskBrowseCtrl::ExpandDir(wxTreeItemId parentId)
{
    if(!m_disk){
        return;
    }

    T100DISK_PART_CTRL_VECTOR&      parts   = m_disk->GetAllParts();

    if(0 == parts.size()){
        return;
    }

    for(T100DISK_PART_CTRL* item : parts){
        if(item){
            if(item->PART){
                wxString        path;
                wxString        name;
                wxInt32         icon;

                path    = item->PART->NAME.to_wstring();
                name    = item->PART->NAME.to_wstring();
                icon    = wxFileIconsTable::drive;

                AddSection(path, name, icon);
            }
        }
    }

    wxDirItemData*  data = GetItemData(parentId);

    if(data){
        wxString    part;

        part    = data->m_path;

        GetFolders(part);
    }
}

void T100VDiskBrowseCtrl::CollapseDir(wxTreeItemId parentId)
{

}

wxDirItemData* T100VDiskBrowseCtrl::GetItemData(wxTreeItemId itemId)
{
    return static_cast<wxDirItemData*>(m_tree->GetItemData(itemId));
}

T100BOOL T100VDiskBrowseCtrl::GetFolders(wxString part)
{

}
