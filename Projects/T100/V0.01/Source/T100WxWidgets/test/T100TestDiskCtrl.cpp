#include "T100TestDiskCtrl.h"

#include <wx/msgdlg.h>


T100TestDiskCtrl::T100TestDiskCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                     const wxSize& size, long style, const wxValidator& validator,
                     const wxString& name)
    :T100DiskCtrl(parent, id, pos, size, style, validator, name)
{
    //ctor
}

T100TestDiskCtrl::~T100TestDiskCtrl()
{
    //dtor
}

T100BOOL T100TestDiskCtrl::OnMenuCreate(void* d)
{
    wxMessageBox(_("Part is created!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnMenuEdit(void* d)
{
    wxMessageBox(_("Part is edited!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnMenuRemove(void* d)
{
    wxMessageBox(_("Part is removed!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnMenuFormat(void* d)
{
    wxMessageBox(_("Part is formated!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnMenuBrowse(void* d)
{
    wxMessageBox(_("be loaded!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnFolderCreate(void* d)
{
    wxMessageBox(_("Folder is created!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnFolderRemove(void* d)
{
    wxMessageBox(_("Folder is removed!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnFileCopy(void* d)
{
    wxMessageBox(_("File is copied!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnFileRemove(void* d)
{
    wxMessageBox(_("File is removed!"));
    return T100TRUE;
}

T100BOOL T100TestDiskCtrl::OnGetAllDrivers(wxArrayString& paths, wxArrayString& names, wxArrayInt& icons)
{
    wxMessageBox(_("GetAllDrivers!"));
    return T100TRUE;
}
