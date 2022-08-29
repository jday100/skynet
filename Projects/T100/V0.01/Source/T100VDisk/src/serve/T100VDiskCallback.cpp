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
    T100DiskCreateDialog    dialog(m_view->getFrame());
    T100STRING              name;
    T100LONG                length;

    T100VDiskFrame*         frame           = T100NULL;

    if(dialog.ShowModal() == wxID_OK){
        name    = dialog.FileTextCtrl->GetValue().ToStdWstring();
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

T100BOOL T100VDiskCallback::dialog_new_browse(void* d)
{
    T100BOOL            result          = T100TRUE;

    wxFileDialog        dialog(m_view->getFrame(), _("Create a new file"), "", "", "VDisk files (*.vdk)|*.vdk");

    if(dialog.ShowModal() == wxID_OK){
        T100DiskCreateDialog* parent = static_cast<T100DiskCreateDialog*>(d);

        parent->FileTextCtrl->SetValue(dialog.GetFilename());
    }else{
        result = T100FALSE;
    }

    return result;
}


T100BOOL T100VDiskCallback::frame_menu_open(void* d)
{
    T100BOOL            result          = T100TRUE;

    wxFileDialog        dialog(m_view->getFrame(), _("Open a vdisk file"), "", "", "VDisk files (*.vdk)|*.vdk", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if(dialog.ShowModal() == wxID_OK){
        T100STRING          name;
        T100VDiskFrame*     frame;

        name    = dialog.GetFilename().ToStdWstring();
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

    result = m_serve->saveVDisk();

    return result;
}

T100BOOL T100VDiskCallback::frame_menu_close(void* d)
{
    T100BOOL            result          = T100TRUE;

    result = m_serve->closeVDisk();

    return result;
}

T100BOOL T100VDiskCallback::ctrl_menu_new(void* d)
{
    T100BOOL            result          = T100TRUE;
    T100DISK_PART*      part            = T100NULL;

    part    = static_cast<T100DISK_PART*>(d);

    result  = m_serve->getVDisk()->part_create(part->NAME, part->LOCATION, part->LENGTH, part->BOOT);

    return result;
}
