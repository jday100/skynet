#include "T100VDiskCtrl.h"

#include "T100VDiskCallback.h"


T100VDiskCtrl::T100VDiskCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size,
                             long style, const wxValidator& validator, const wxString& name)
    :T100DiskCtrl(parent, id, pos, size, style, validator, name)
{
    //ctor
}

T100VDiskCtrl::~T100VDiskCtrl()
{
    //dtor
}

T100BOOL T100VDiskCtrl::OnMenuCreate(void* d)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_menu_new(d);

    return result;
}

T100BOOL T100VDiskCtrl::OnMenuEdit(void* d)
{

}

T100BOOL T100VDiskCtrl::OnMenuRemove(void* d)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_menu_remove(d);

    return result;
}

T100BOOL T100VDiskCtrl::OnMenuBrowse(void* d)
{

}

T100BOOL T100VDiskCtrl::OnMenuFormat(void* d)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_menu_format(d);

    return result;
}

T100BOOL T100VDiskCtrl::OnFolderCreate(void* d)
{

}

T100BOOL T100VDiskCtrl::OnFolderRemove(void* d)
{

}

T100BOOL T100VDiskCtrl::OnFileCopy(void* d)
{

}

T100BOOL T100VDiskCtrl::OnFileRemove(void* d)
{

}

T100BOOL T100VDiskCtrl::OnGetAllDrivers(wxArrayString& paths, wxArrayString& names, wxArrayInt& icons)
{

}

///
T100BOOL T100VDiskCtrl::DoGetAllParts(T100DISK_PART_CTRL_VECTOR& parts)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_get_all_parts(&parts);

    return result;
}

T100BOOL T100VDiskCtrl::DoGetAllItems(wxString part, wxString path, T100DISK_ITEM_VECTOR& items)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_get_all_items(part.ToStdWstring(), path.ToStdWstring(), items);

    return result;
}

T100BOOL T100VDiskCtrl::DoCreateFolder(T100DISK_ITEM* item)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_create_folder(item);

    return result;
}

T100BOOL T100VDiskCtrl::DoRemoveFolder(T100DISK_ITEM* item)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_remove_folder(item);

    return result;
}

T100BOOL T100VDiskCtrl::DoCopyFile(T100DISK_ITEM* source, T100DISK_ITEM* target)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_copy_file(source, target);

    return result;
}

T100BOOL T100VDiskCtrl::DoRemoveFile(T100DISK_ITEM* item)
{
    T100BOOL            result          = T100TRUE;

    result = T100VDiskCallback::ctrl_remove_file(item);

    return result;
}
