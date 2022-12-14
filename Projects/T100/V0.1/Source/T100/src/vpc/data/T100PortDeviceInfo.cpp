#include "T100PortDeviceInfo.h"

namespace T100VPC{

T100PortDeviceInfo::T100PortDeviceInfo()
{
    //ctor
    create();
}

T100PortDeviceInfo::~T100PortDeviceInfo()
{
    //dtor
    destroy();
}

T100VOID T100PortDeviceInfo::create()
{
    name = L"Port";
    type = T100Component::T100DEVICE_PORT;

    init();
}

T100VOID T100PortDeviceInfo::destroy()
{

}

T100VOID T100PortDeviceInfo::init()
{

}

T100WORD T100PortDeviceInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_PORT == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100PortDeviceInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100PortDeviceInfo::append(T100PortDeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100PortDeviceInfo::remove(T100PortDeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100PortDeviceInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100PortDeviceInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100PortDeviceInfo::setup()
{
    return T100TRUE;
}

T100BOOL T100PortDeviceInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100PortDeviceInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
