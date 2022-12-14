#include "T100KeyboardInfo.h"

namespace T100VPC{

T100KeyboardInfo::T100KeyboardInfo()
{
    //ctor
    create();
}

T100KeyboardInfo::~T100KeyboardInfo()
{
    //dtor
    destroy();
}

T100VOID T100KeyboardInfo::create()
{
    name = L"Keyboard";
    type = T100Component::T100DEVICE_KEYBOARD;

    init();
}

T100VOID T100KeyboardInfo::destroy()
{

}

T100VOID T100KeyboardInfo::init()
{

}

T100WORD T100KeyboardInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_KEYBOARD == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100KeyboardInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100KeyboardInfo::append(T100KeyboardInfo* info)
{
    return T100TRUE;
}

T100BOOL T100KeyboardInfo::remove(T100KeyboardInfo* info)
{
    return T100TRUE;
}

T100BOOL T100KeyboardInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100KeyboardInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100KeyboardInfo::setup()
{
    return T100TRUE;
}

T100BOOL T100KeyboardInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100KeyboardInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
