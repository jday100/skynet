#include "T100VDiskCallback.h"

#include <wx/filedlg.h>

#include "T100String.h"
#include "T100VDiskServe.h"
#include "T100VDiskView.h"

#include "T100VDiskMain.h"
#include "view/T100DiskCreateDialog.h"


T100VDiskServe*         T100VDiskCallback::m_serve              = T100NULL;
T100VDiskView*          T100VDiskCallback::m_view               = T100NULL;



T100VDiskCallback::T100VDiskCallback()
{
    //ctor
}

T100VDiskCallback::~T100VDiskCallback()
{
    //dtor
}

T100BOOL T100VDiskCallback::init(T100VDiskServe* serve, T100VDiskView* view)
{
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_serve     = serve;
    m_view      = view;

    return T100TRUE;
}

T100BOOL T100VDiskCallback::frame_menu_new(void* d)
{
    T100BOOL                result          = T100TRUE;

    T100STRING              name;
    T100LONG                length;

    T100VDiskFrame*         frame           = T100NULL;

    if(m_serve->opened()){
        return T100FALSE;
    }

    T100DiskCreateDialog    dialog(m_view->getFrame());

    if(dialog.ShowModal() == wxID_OK){
        name    = dialog.FileComboBox->GetValue().ToStdWstring();
        result  = dialog.LengthComboBox->GetValue().ToLongLong(&length);
        if(!result){
            return T100FALSE;
        }
        result  = m_serve->createVDisk(name, length);
    }else{
        result  = T100FALSE;
    }

    if(result){
        frame = static_cast<T100VDiskFrame*>(d);

        frame->load(m_serve->getVDisk());

    }

    return result;
}


T100BOOL T100VDiskCallback::frame_menu_open(void* d)
{
    T100BOOL            result          = T100TRUE;

    if(m_serve->opened()){
        return T100FALSE;
    }

    wxFileDialog        dialog(m_view->getFrame(), _("Open a vdisk file"), "", "", "VDisk files (*.vdk)|*.vdk", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    int i = dialog.ShowModal();

    if(i == wxID_OK){
        T100STRING          name;
        T100VDiskFrame*     frame;

        name    = dialog.GetPath().ToStdWstring();
        result  = m_serve->openVDisk(name);

        frame   = static_cast<T100VDiskFrame*>(d);

        frame->load(m_serve->getVDisk());

    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCallback::frame_menu_save(void* d)
{
    T100BOOL            result          = T100TRUE;

    if(!m_serve->opened()){
        return T100FALSE;
    }

    result = m_serve->saveVDisk();

    return result;
}

T100BOOL T100VDiskCallback::frame_menu_close(void* d)
{
    T100BOOL            result          = T100TRUE;

    if(!m_serve->opened()){
        return T100FALSE;
    }

    result = m_serve->closeVDisk();

    if(result){
        T100VDiskFrame*     frame   = T100NULL;

        frame = static_cast<T100VDiskFrame*>(m_view->getFrame());

        if(frame){
            result = frame->clear();
        }else{
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VDiskCallback::frame_menu_quit(void* d)
{
    if(m_serve->opened()){
        return T100FALSE;
    }else{
        m_view->quit();
    }
    return T100TRUE;
}

T100BOOL T100VDiskCallback::ctrl_menu_new(void* d)
{
    T100BOOL            result          = T100TRUE;
    T100DISK_PART*      part            = T100NULL;

    part    = static_cast<T100DISK_PART*>(d);

    result  = m_serve->getVDisk()->part_create(part->NAME, part->LOCATION, part->LENGTH, part->BOOT);

    return result;
}

T100BOOL T100VDiskCallback::ctrl_menu_remove(void* d)
{
    T100BOOL            result          = T100TRUE;
    T100DISK_PART*      part            = T100NULL;

    part    = static_cast<T100DISK_PART*>(d);

    result  = m_serve->getVDisk()->part_remove(part->NAME);

    return result;
}

T100BOOL T100VDiskCallback::ctrl_menu_format(void* d)
{
    T100BOOL                result          = T100TRUE;
    T100DISK_PART_INFO*     info            = T100NULL;

    info    = static_cast<T100DISK_PART_INFO*>(d);

    if(!info){
        return T100FALSE;
    }

    if((!info->PART->BOOT) && info->BOOT_FILE.empty()){
        result  = m_serve->getVDisk()->fs_format(info->PART->NAME);
    }else{
        result  = m_serve->getVDisk()->fs_format(info->PART->NAME, info->BOOT_FILE);
    }

    return result;
}

T100BOOL T100VDiskCallback::ctrl_get_all_parts(void* d)
{
    T100BOOL                        result          = T100TRUE;
    T100DISK_PART_CTRL_VECTOR*      parts           = T100NULL;

    parts = static_cast<T100DISK_PART_CTRL_VECTOR*>(d);

    if(!parts){
        return T100FALSE;
    }

    T100VFS_PART_VECTOR     items;

    result = m_serve->getVDisk()->part_list(items);

    if(!result){
        return T100FALSE;
    }

    for(T100VFS_PART item : items){

    }

    return result;
}

T100BOOL T100VDiskCallback::ctrl_get_all_items(T100String part, T100String path, T100DISK_ITEM_VECTOR& items)
{
    T100BOOL                result          = T100TRUE;


    result = m_serve->getVDisk()->fs_list(part, path, items);

    return result;
}
