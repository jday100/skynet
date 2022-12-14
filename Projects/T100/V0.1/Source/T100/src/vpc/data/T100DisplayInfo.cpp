#include "T100DisplayInfo.h"

namespace T100VPC{

T100DisplayInfo::T100DisplayInfo()
{
    //ctor
    create();
}

T100DisplayInfo::~T100DisplayInfo()
{
    //dtor
    destroy();
}

T100VOID T100DisplayInfo::create()
{
    name = L"Display";
    type = T100Component::T100DEVICE_DISPLAY;

    init();
}

T100VOID T100DisplayInfo::init()
{
    m_width     = T100VPCSetup::SCREEN_WIDTH;
    m_height    = T100VPCSetup::SCREEN_HEIGHT;

    m_font      = T100VPCSetup::getFontFile();
}

T100VOID T100DisplayInfo::destroy()
{

}

T100WORD T100DisplayInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_DISPLAY == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100DisplayInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100DisplayInfo::append(T100DisplayInfo* info)
{
    return T100TRUE;
}

T100BOOL T100DisplayInfo::remove(T100DisplayInfo* info)
{
    return T100TRUE;
}

T100BOOL T100DisplayInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100DisplayInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100DisplayInfo::setup()
{
    if(!m_setup){
        m_setup = T100NEW T100VPCDisplaySetupDialog(T100NULL);
        m_setup->setInfo(this);
    }
    m_setup->Show();

    return T100TRUE;
}

T100BOOL T100DisplayInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100DisplayInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
