#include "T100FileSystemCtrl.h"

BEGIN_EVENT_TABLE(T100FileSystemCtrl,wxGenericDirCtrl)

END_EVENT_TABLE()

T100FileSystemCtrl::T100FileSystemCtrl(wxWindow *parent)
{
    //ctor
    BuildContent(parent);
}

T100FileSystemCtrl::~T100FileSystemCtrl()
{
    //dtor
}

void T100FileSystemCtrl::BuildContent(wxWindow *parent)
{
    Create(parent);
}

T100BOOL T100FileSystemCtrl::SetDiskCtrl(T100DiskCtrl* disk)
{
    m_disk = disk;
    return T100TRUE;
}

void T100FileSystemCtrl::SetupSections()
{
    wxArrayString   paths, names;
    wxArrayInt      icons;
    size_t  n;
    size_t  count;

    count = getAllDrives(paths, names, icons);

    for (n = 0; n < count; n++)
        AddSection(paths[n], names[n], icons[n]);
}

size_t T100FileSystemCtrl::getAllDrives(wxArrayString& paths, wxArrayString& names, wxArrayInt& icon_ids)
{
    wxString    name;
    wxString    path;
    int  id;

    name = _("Test");
    path = _("Test");
    id  = wxFileIconsTable::floppy;

    paths.Add(path);
    names.Add(name);
    icon_ids.Add(id);


    ///

    if(!m_disk)return 0;


    m_disk->OnGetAllDrivers(paths, names, icon_ids);



    return 1;
}

T100BOOL T100FileSystemCtrl::Load()
{
    wxArrayString   paths, names;
    wxArrayInt      icons;
    size_t  n;
    size_t  count;

    count = getAllDrives(paths, names, icons);

    for (n = 0; n < count; n++)
        AddSection(paths[n], names[n], icons[n]);
}
