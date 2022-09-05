#ifndef T100DISKBROWSEPARTDIALOG_H
#define T100DISKBROWSEPARTDIALOG_H

#include <wx/dialog.h>
#include <wx/dirctrl.h>
#include <wx/sizer.h>
#include "T100FileSystemCtrl.h"


class T100DiskBrowsePartDialog : public wxDialog
{
    public:
        T100DiskBrowsePartDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100DiskBrowsePartDialog();

        wxGenericDirCtrl*           GenericDirCtrl;
        T100FileSystemCtrl*         VDiskDirCtrl;

    protected:
        static const long ID_GENERICDIRCTRL;
        static const long ID_VDISKDIRCTRL;

    private:
        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100DISKBROWSEPARTDIALOG_H
