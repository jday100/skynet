#include "T100MemoryInfo.h"

namespace T100VPC{

T100MemoryInfo::T100MemoryInfo()
{
    //ctor
    create();
}

T100MemoryInfo::~T100MemoryInfo()
{
    //dtor
    destroy();
}

T100VOID T100MemoryInfo::create()
{
    name = L"Memory";
    type = T100Component::T100DEVICE_MEMORY;

    init();
}

T100VOID T100MemoryInfo::init()
{
    m_ram_base  = T100VPCSetup::m_ram_base;
    m_ram_size  = T100VPCSetup::m_ram_size;

    m_rom_base  = T100VPCSetup::m_rom_base;
    m_rom_size  = T100VPCSetup::m_rom_size;
}

T100VOID T100MemoryInfo::destroy()
{

}

T100WORD T100MemoryInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_MEMORY == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100MemoryInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100MemoryInfo::append(T100MemoryInfo* info)
{
    return T100TRUE;
}

T100BOOL T100MemoryInfo::remove(T100MemoryInfo* info)
{
    return T100TRUE;
}

T100BOOL T100MemoryInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100MemoryInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100MemoryInfo::setup()
{
    if(!m_setup){
        m_setup = T100NEW T100VPCMemorySetupDialog(T100NULL);
        m_setup->setInfo(this);
    }
    m_setup->Show();

    return T100TRUE;
}

T100BOOL T100MemoryInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100MemoryInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
