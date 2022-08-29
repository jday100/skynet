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

}

T100BOOL T100VDiskCtrl::OnMenuBrowse(void* d)
{

}

T100BOOL T100VDiskCtrl::OnMenuFormat(void* d)
{

}
