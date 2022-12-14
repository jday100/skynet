#include "T100DiskInfo.h"

namespace T100VPC{

T100DiskInfo::T100DiskInfo()
{
    //ctor
    create();
}

T100DiskInfo::~T100DiskInfo()
{
    //dtor
    destroy();
}

T100VOID T100DiskInfo::create()
{
    name = L"Disk";
    type = T100Component::T100DEVICE_DISK;

    init();
}

T100VOID T100DiskInfo::init()
{
    m_name  = L"vdisk";
    m_file  = T100VPCSetup::getVDiskFile();
}

T100VOID T100DiskInfo::destroy()
{

}

T100WORD T100DiskInfo::count()
{
    T100WORD        total           = 0;

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        if(item){
            if(T100Component::T100DEVICE_DISK == item->type){
                total++;
            }
        }else{
            return -1;
        }
    }
    return total;
}

T100BOOL T100DiskInfo::verify()
{
    T100BOOL        result          = T100FALSE;

    if(1 == count()){
        return T100TRUE;
    }
    return result;
}

T100BOOL T100DiskInfo::append(T100DiskInfo* info)
{
    return T100TRUE;
}

T100BOOL T100DiskInfo::remove(T100DiskInfo* info)
{
    return T100TRUE;
}

T100BOOL T100DiskInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{
    infos = T100VPCSetup::getDevices();
    return T100TRUE;
}

T100BOOL T100DiskInfo::insert(wxListView* view)
{
    T100BOOL        result          = T100FALSE;
    T100LONG        index;
    wxUIntPtr       data;

    index   = view->InsertItem(view->GetItemCount(), name.to_wstring());
    data    = (wxUIntPtr)this;
    result  = view->SetItemPtrData(index, data);

    return result;
}

T100BOOL T100DiskInfo::setup()
{
    if(!m_setup){
        m_setup = T100NEW T100VPCDiskSetupDialog(T100NULL);
        m_setup->setInfo(this);
    }
    m_setup->Show();

    return T100TRUE;
}

T100BOOL T100DiskInfo::append(T100DeviceInfo* info)
{
    return T100TRUE;
}

T100BOOL T100DiskInfo::remove(T100DeviceInfo* info)
{
    return T100TRUE;
}

}
