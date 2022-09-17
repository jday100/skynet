#ifndef T100FILESYSTEMCTRL_H
#define T100FILESYSTEMCTRL_H

#include <wx/wx.h>
#include <wx/generic/dirctrlg.h>
#include "T100DiskCtrl.h"


class T100FileSystemCtrl : public wxGenericDirCtrl
{
    public:
        T100FileSystemCtrl(wxWindow *parent);
        virtual ~T100FileSystemCtrl();

        T100BOOL            SetDiskCtrl(T100DiskCtrl*);

        T100BOOL            Load();

    protected:
        void                SetupSections();

        size_t              getAllDrives(wxArrayString& paths, wxArrayString& names, wxArrayInt& icon_ids);

        void                PopulateNode(wxTreeItemId parentId);

    private:
        void                OnExpandItem(wxTreeEvent& event);
        void                OnCollapseItem(wxTreeEvent& event);
        void                OnBeginEditItem(wxTreeEvent& event);
        void                OnEndEditItem(wxTreeEvent& event);
        void                OnTreeSelChange(wxTreeEvent& event);
        void                OnSize(wxSizeEvent& event);
        void                OnTreeBeginDrag(wxTreeEvent& event);
        void                OnTreeEndDrag(wxTreeEvent& event);
        void                OnTreeDeleteItem(wxTreeEvent& event);
        void                OnTreeItemMenu(wxTreeEvent& event);

    private:
        void                DoExpandItem(wxTreeItemId);
        void                DoCollapseItem();
        void                DoBeginEditItem();
        void                DoEndEditItem();
        void                DoSelectChange();
        void                DoBeginDrag();
        void                DoEndDrag();
        void                DoDeleteItem();
        void                DoItemMenu();

    private:
        void                ExpandDir(wxTreeItemId parentId);

    private:
        T100DiskCtrl*       m_disk          = T100NULL;

        void BuildContent(wxWindow *parent);

		DECLARE_EVENT_TABLE()
};

#endif // T100FILESYSTEMCTRL_H
