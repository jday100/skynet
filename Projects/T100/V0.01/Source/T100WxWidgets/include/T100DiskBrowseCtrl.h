#ifndef T100DISKBROWSECTRL_H
#define T100DISKBROWSECTRL_H

#include <wx/wx.h>
#include <wx/generic/dirctrlg.h>
#include "T100DiskBrowseData.h"
#include "T100DiskCtrl.h"


class T100DiskBrowseCtrl : public wxGenericDirCtrl
{
    public:
        T100DiskBrowseCtrl(wxWindow* parent);
        virtual ~T100DiskBrowseCtrl();

        T100BOOL                SetDiskCtrl(T100DiskCtrl*);
        T100BOOL                Load();

    protected:
        wxTreeCtrl*             CreateTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long treeStyle);
        void                    ExpandDir(wxTreeItemId parentId);
        T100DiskBrowseData*     GetItemData(wxTreeItemId);
        wxTreeItemId            AddPart(wxString&, wxString&, int);
        wxTreeItemId            AddItem(wxTreeItemId, wxString&, wxString&, int);

        void                    ShowMenu();

    private:
        static const long ID_MENU_FOLDER_CREATE;
        static const long ID_MENU_FOLDER_REMOVE;
        static const long ID_MENU_FILE_COPY;
        static const long ID_MENU_FILE_REMOVE;

    private:
        void                    OnExpandItem(wxTreeEvent& event);
        void                    OnCollapseItem(wxTreeEvent& event);
        void                    OnBeginEditItem(wxTreeEvent& event);
        void                    OnEndEditItem(wxTreeEvent& event);
        void                    OnTreeSelChange(wxTreeEvent& event);
        void                    OnSize(wxSizeEvent& event);
        void                    OnTreeBeginDrag(wxTreeEvent& event);
        void                    OnTreeEndDrag(wxTreeEvent& event);
        void                    OnTreeDeleteItem(wxTreeEvent& event);
        void                    OnTreeItemMenu(wxTreeEvent& event);

        void                    OnCreateFolder(wxCommandEvent& event);
        void                    OnRemoveFolder(wxCommandEvent& event);
        void                    OnRemoveFile(wxCommandEvent& event);

    private:
        wxTreeItemId            m_root_id;
        wxTreeItemId            m_current;

        wxMenu                  m_menu;
        wxMenu                  m_folder_menu;
        wxMenu                  m_file_menu;
        wxTreeCtrl*             m_tree          = T100NULL;
        T100DiskCtrl*           m_disk          = T100NULL;

        void BuildContent(wxWindow *parent);

		DECLARE_EVENT_TABLE()
};

#endif // T100DISKBROWSECTRL_H
