#ifndef T100TESTDISKCTRL_H
#define T100TESTDISKCTRL_H

#include "T100DiskCtrl.h"


class T100TestDiskCtrl : public T100DiskCtrl
{
    public:
        T100TestDiskCtrl(wxWindow* parent, wxWindowID id,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxControlNameStr);
        virtual ~T100TestDiskCtrl();

    protected:
        T100BOOL                        OnMenuCreate(void*);
        T100BOOL                        OnMenuEdit(void*);
        T100BOOL                        OnMenuRemove(void*);

        T100BOOL                        OnMenuFormat(void*);
        T100BOOL                        OnMenuBrowse(void*);

        T100BOOL                        OnFolderCreate(void*);
        T100BOOL                        OnFolderRemove(void*);
        T100BOOL                        OnFileCopy(void*);
        T100BOOL                        OnFileRemove(void*);

        T100BOOL                        OnGetAllDrivers(wxArrayString&, wxArrayString&, wxArrayInt&);

    private:
};

#endif // T100TESTDISKCTRL_H
