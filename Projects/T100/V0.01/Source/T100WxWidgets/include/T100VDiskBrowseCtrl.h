#ifndef T100VDISKBROWSECTRL_H
#define T100VDISKBROWSECTRL_H

#include <wx/wx.h>
#include <wx/generic/dirctrlg.h>
#include "T100DiskCtrl.h"


class T100VDiskBrowseCtrl : public wxGenericDirCtrl
{
    public:
        T100VDiskBrowseCtrl(wxWindow* parent);
        virtual ~T100VDiskBrowseCtrl();

        T100BOOL            SetDiskCtrl(T100DiskCtrl*);
        T100BOOL            Load();
        T100BOOL            GetFolders(wxString);

    protected:
        wxTreeCtrl*         CreateTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long treeStyle);

        void                ExpandDir(wxTreeItemId parentId);
        void                CollapseDir(wxTreeItemId parentId);

        wxDirItemData*      GetItemData(wxTreeItemId itemId);

    private:
        wxTreeCtrl*         m_tree          = T100NULL;
        T100DiskCtrl*       m_disk          = T100NULL;

        void BuildContent(wxWindow *parent);

		DECLARE_EVENT_TABLE()
};

#endif // T100VDISKBROWSECTRL_H
