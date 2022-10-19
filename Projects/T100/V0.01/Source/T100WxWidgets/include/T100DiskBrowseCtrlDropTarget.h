#ifndef T100DISKBROWSECTRLDROPTARGET_H
#define T100DISKBROWSECTRLDROPTARGET_H

#include <wx/dnd.h>
#include "T100Common.h"
#include "T100DiskBrowseCtrl.h"


class T100DiskBrowseCtrlDropTarget : public wxFileDropTarget
{
    public:
        T100DiskBrowseCtrlDropTarget(T100DiskBrowseCtrl*);
        virtual ~T100DiskBrowseCtrlDropTarget();

        virtual bool OnDropFiles(wxCoord x, wxCoord y,
                             const wxArrayString& filenames);

    protected:

    private:
        T100DiskBrowseCtrl*     m_ctrl          = T100NULL;

};

#endif // T100DISKBROWSECTRLDROPTARGET_H
