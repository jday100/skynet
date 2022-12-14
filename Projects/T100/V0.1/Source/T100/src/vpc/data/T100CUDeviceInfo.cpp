#include "T100CUDeviceInfo.h"

namespace T100VPC{

T100CUDeviceInfo::T100CUDeviceInfo()
{
    //ctor
    create();
}

T100CUDeviceInfo::~T100CUDeviceInfo()
{
    //dtor
    destroy();
}

T100VOID T100CUDeviceInfo::create()
{
    name = L"CU";
    type = T100Component::T100DEVICE_CU;

    init();
}


T100VOID T100CUDeviceInfo::destroy()
{

}

T100VOID T100CUDeviceInfo::init()
{

}

T100WORD T100CUDeviceInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_CU == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100CUDeviceInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100CUDeviceInfo::append(T100CUDeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100CUDeviceInfo::remove(T100CUDeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100CUDeviceInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100CUDeviceInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100CUDeviceInfo::setup()
{
    return T100TRUE;
}

T100BOOL T100CUDeviceInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100CUDeviceInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
