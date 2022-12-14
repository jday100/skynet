#include "T100MouseInfo.h"

namespace T100VPC{

T100MouseInfo::T100MouseInfo()
{
    //ctor
    create();
}

T100MouseInfo::~T100MouseInfo()
{
    //dtor
    destroy();
}

T100VOID T100MouseInfo::create()
{
    name = L"Mouse";
    type = T100Component::T100DEVICE_MOUSE;

    init();
}

T100VOID T100MouseInfo::destroy()
{

}

T100VOID T100MouseInfo::init()
{

}

T100WORD T100MouseInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_MOUSE == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100MouseInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100MouseInfo::append(T100MouseInfo* info)
{
    return T100TRUE;
}

T100BOOL T100MouseInfo::remove(T100MouseInfo* info)
{
    return T100TRUE;
}

T100BOOL T100MouseInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100MouseInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100MouseInfo::setup()
{
    return T100TRUE;
}

T100BOOL T100MouseInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100MouseInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
