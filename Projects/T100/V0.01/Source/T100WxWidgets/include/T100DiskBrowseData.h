#ifndef T100DISKBROWSEDATA_H
#define T100DISKBROWSEDATA_H

#include <wx/wx.h>
#include <wx/generic/dirctrlg.h>
#include "T100Common.h"


class T100DiskBrowseData : public wxDirItemData
{
    public:
        T100DiskBrowseData(const wxString& path, const wxString& name, bool isDir);
        virtual ~T100DiskBrowseData();

        T100VOID            setPart(T100BOOL);
        T100BOOL            isPart();
        wxString            part;
        T100BOOL            loaded          = T100FALSE;

    protected:

    private:
        T100BOOL            m_part          = T100FALSE;

};

#endif // T100DISKBROWSEDATA_H
