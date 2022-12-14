#include "T100AUDeviceInfo.h"

namespace T100VPC{

T100AUDeviceInfo::T100AUDeviceInfo()
{
    //ctor
    create();
}

T100AUDeviceInfo::~T100AUDeviceInfo()
{
    //dtor
    destroy();
}

T100VOID T100AUDeviceInfo::create()
{
    name = L"AU";
    type = T100Component::T100DEVICE_AU;

    init();
}

T100VOID T100AUDeviceInfo::destroy()
{

}

T100VOID T100AUDeviceInfo::init()
{

}

T100WORD T100AUDeviceInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_AU == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100AUDeviceInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100AUDeviceInfo::append(T100AUDeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100AUDeviceInfo::remove(T100AUDeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100AUDeviceInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100AUDeviceInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100AUDeviceInfo::setup()
{
    return T100TRUE;
}

T100BOOL T100AUDeviceInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100AUDeviceInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
