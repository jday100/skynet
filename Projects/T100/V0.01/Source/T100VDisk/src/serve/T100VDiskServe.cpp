#include "T100VDiskServe.h"

T100VDiskServe::T100VDiskServe()
{
    //ctor
}

T100VDiskServe::~T100VDiskServe()
{
    //dtor
}

T100BOOL T100VDiskServe::createVDisk(T100String file, T100DWORD length)
{
    T100BOOL            result          = T100TRUE;

    m_vdisk = T100NEW T100VDisk(file);

    if(m_vdisk){
        result = m_vdisk->create(length);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskServe::openVDisk(T100String file)
{
    T100BOOL            result          = T100TRUE;

    m_vdisk = T100NEW T100VDisk(file);

    if(m_vdisk){
        result = m_vdisk->open();
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskServe::saveVDisk()
{

}

T100BOOL T100VDiskServe::closeVDisk()
{

}

T100VDisk* T100VDiskServe::getVDisk()
{
    return m_vdisk;
}
