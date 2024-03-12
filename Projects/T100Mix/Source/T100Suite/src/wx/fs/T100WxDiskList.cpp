#include "T100WxDiskList.h"

T100WxDiskList::T100WxDiskList(wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos,
               const wxSize& size,
               long style,
               const wxValidator& validator,
               const wxString& name)
    :wxListCtrl(parent, id, pos, size, style, validator, name)
{
    //ctor
}

T100WxDiskList::~T100WxDiskList()
{
    //dtor
}
