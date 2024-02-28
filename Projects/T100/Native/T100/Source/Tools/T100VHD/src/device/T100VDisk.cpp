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
    m_base->cancel();
}

T100VOID T100VDisk::setCallback(T100VDiskCallback* callback)
{
    m_callback  = callback;
}

T100BOOL T100VDisk::create(T100VDISK_TYPE vdisk, T100VDISK_STORAGE_TYPE type)
{
    T100BOOL        result      = T100FALSE;

    switch(vdisk){
    case T100VDISK_TYPE_VHD:
        {
            m_base  = T100NEW T100VHD(m_filename, m_length);
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
            m_base->setValue(m_value);
            m_base->setCallback(m_callback);
            result  = m_base->create(vhd_type);

            if(m_base){
                T100DELETE  m_base;
                m_base  = T100NULL;
            }
        }
        break;
    case T100VDISK_TYPE_VHDX:
        {

        }
        break;
    }

    return result;
}
