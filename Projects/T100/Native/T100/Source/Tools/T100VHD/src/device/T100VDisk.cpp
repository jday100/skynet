#include "T100VDisk.h"

#include "T100VHD.h"
#include "T100VHDX.h"


T100VDisk::T100VDisk(T100STRING name, T100INT64 length)
    :m_filename(name), m_length(length)
{
    //ctor
}

T100VDisk::~T100VDisk()
{
    //dtor
}

T100VOID T100VDisk::setValue(T100VOID* value)
{
    m_value     = value;
}

T100VOID T100VDisk::cancel()
{

}

T100VOID T100VDisk::setCreateCallback(T100THREAD_CALLBACK callback)
{
    m_callback  = callback;
}

T100BOOL T100VDisk::create(T100VDISK_TYPE vdisk, T100VDISK_STORAGE_TYPE type)
{
    switch(vdisk){
    case T100VDISK_TYPE_VHD:
        {
            T100VHD                     vhd(m_filename, m_length);
            T100VHD_STORAGE_TYPE        vhd_type;

            switch(type){
            case T100VDISK_STORAGE_TYPE_FIXED:
                {
                    vhd_type    = T100VHD_STORAGE_TYPE_FIXED;
                }
                break;
            case T100VHD_STORAGE_TYPE_DYNAMIC:
                {
                    vhd_type    = T100VHD_STORAGE_TYPE_DYNAMIC;
                }
                break;
            }
            vhd.setValue(m_value);
            vhd.setCreateCallback(m_callback);
            vhd.create(vhd_type);
        }
        break;
    case T100VDISK_TYPE_VHDX:
        {

        }
        break;
    }
}
