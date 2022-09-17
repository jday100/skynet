#include "T100FileSystemCtrl.h"

BEGIN_EVENT_TABLE(T100FileSystemCtrl,wxGenericDirCtrl)
    //EVT_TREE_ITEM_EXPANDING     (wxID_TREECTRL, T100FileSystemCtrl::OnExpandItem)
    EVT_TREE_ITEM_COLLAPSED     (wxID_TREECTRL, T100FileSystemCtrl::OnCollapseItem)
    EVT_TREE_BEGIN_LABEL_EDIT   (wxID_TREECTRL, T100FileSystemCtrl::OnBeginEditItem)
    EVT_TREE_END_LABEL_EDIT     (wxID_TREECTRL, T100FileSystemCtrl::OnEndEditItem)
    EVT_TREE_SEL_CHANGED        (wxID_TREECTRL, T100FileSystemCtrl::OnTreeSelChange)
    EVT_TREE_ITEM_ACTIVATED     (wxID_TREECTRL, T100FileSystemCtrl::OnItemActivated)
    EVT_SIZE                    (T100FileSystemCtrl::OnSize)
    //
    EVT_TREE_BEGIN_DRAG         (wxID_TREECTRL, T100FileSystemCtrl::OnTreeBeginDrag)
    EVT_TREE_END_DRAG           (wxID_TREECTRL, T100FileSystemCtrl::OnTreeEndDrag)
    EVT_TREE_DELETE_ITEM        (wxID_TREECTRL, T100FileSystemCtrl::OnTreeDeleteItem)
    EVT_TREE_ITEM_MENU          (wxID_TREECTRL, T100FileSystemCtrl::OnTreeItemMenu)
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

    name    = _("\\");
    path    = _("\\");
    id      = wxFileIconsTable::computer;

    names.Add(name);
    paths.Add(path);
    icon_ids.Add(id);


    name = _("Test");
    path = _("Test");
    id  = wxFileIconsTable::floppy;

    paths.Add(path);
    names.Add(name);
    icon_ids.Add(id);


    ///

    if(!m_disk)return 0;


    m_disk->OnGetAllDrivers(paths, names, icon_ids);



    return 2;
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

void T100FileSystemCtrl::PopulateNode(wxTreeItemId parentId)
{

}

void T100FileSystemCtrl::OnExpandItem(wxTreeEvent& event)
{
    wxTreeItemId parentId = event.GetItem();

    DoExpandItem(parentId);
}

void T100FileSystemCtrl::OnCollapseItem(wxTreeEvent& event)
{
    DoCollapseItem();
}

void T100FileSystemCtrl::OnBeginEditItem(wxTreeEvent& event)
{
    DoBeginEditItem();
}

void T100FileSystemCtrl::OnEndEditItem(wxTreeEvent& event)
{
    DoEndEditItem();
}

void T100FileSystemCtrl::OnTreeSelChange(wxTreeEvent& event)
{
    DoSelectChange();
}

void T100FileSystemCtrl::OnSize(wxSizeEvent& event)
{
    DoResize();
}

void T100FileSystemCtrl::OnTreeBeginDrag(wxTreeEvent& event)
{
    DoBeginDrag();
}

void T100FileSystemCtrl::OnTreeEndDrag(wxTreeEvent& event)
{
    DoEndDrag();
}

void T100FileSystemCtrl::OnTreeDeleteItem(wxTreeEvent& event)
{
    DoDeleteItem();
}

void T100FileSystemCtrl::OnTreeItemMenu(wxTreeEvent& event)
{
    DoItemMenu();
}

///
void T100FileSystemCtrl::DoExpandItem(wxTreeItemId parentId)
{

}

void T100FileSystemCtrl::DoCollapseItem()
{

}

void T100FileSystemCtrl::DoBeginEditItem()
{

}

void T100FileSystemCtrl::DoEndEditItem()
{

}

void T100FileSystemCtrl::DoSelectChange()
{

}

void T100FileSystemCtrl::DoBeginDrag()
{

}

void T100FileSystemCtrl::DoEndDrag()
{

}

void T100FileSystemCtrl::DoDeleteItem()
{

}

void T100FileSystemCtrl::DoItemMenu()
{

}

///
void T100FileSystemCtrl::ExpandDir(wxTreeItemId parentId)
{

}
