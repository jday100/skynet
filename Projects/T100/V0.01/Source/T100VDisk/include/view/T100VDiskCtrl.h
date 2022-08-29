#ifndef T100VDISKCTRL_H
#define T100VDISKCTRL_H

#include "T100DiskCtrl.h"


class T100VDiskCtrl : public T100DiskCtrl
{
    public:
        T100VDiskCtrl(wxWindow* parent, wxWindowID id,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxControlNameStr);
        virtual ~T100VDiskCtrl();

    protected:
        T100BOOL            OnMenuCreate(void* = T100NULL);
        T100BOOL            OnMenuEdit(void* = T100NULL);
        T100BOOL            OnMenuRemove(void* = T100NULL);
        T100BOOL            OnMenuBrowse(void* = T100NULL);
        T100BOOL            OnMenuFormat(void* = T100NULL);

    private:
};

#endif // T100VDISKCTRL_H
