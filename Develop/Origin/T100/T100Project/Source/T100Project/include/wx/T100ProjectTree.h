#ifndef T100PROJECTTREE_H
#define T100PROJECTTREE_H

#include <wx/menu.h>
#include <wx/imaglist.h>
#include <wx/treectrl.h>
#include "T100Common.h"

#include "T100WorkSpaceInfo.h"
#include "T100ProjectInfo.h"
#include "T100ModuleInfo.h"

class T100ProjectTree : public wxTreeCtrl
{
    public:
        T100ProjectTree(wxWindow *parent, wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTreeCtrlNameStr);
        virtual ~T100ProjectTree();

        T100BOOL                    WorkSpaceOpen(T100WorkSpaceInfo*);

        T100BOOL                    ProjectAppend(T100ProjectInfo*);
        T100BOOL                    ProjectOpen(wxTreeItemId, T100ProjectInfo*);

        T100BOOL                    FolderList(wxTreeItemId, T100FolderInfo*);

        T100BOOL                    ModuleAppend(T100WorkSpaceInfo*, T100ProjectInfo*, T100ModuleInfo*);

        T100VOID                    ShowWorkSpacePopupMenu(T100BOOL);

        T100BOOL                    Remove(wxTreeItemId);

        T100BOOL                    Clear();

    protected:
        T100VOID                    OnMouseRightDown(wxMouseEvent&);

        T100VOID                    OnItemMenu(wxTreeEvent&);
        T100VOID                    OnItemChanged(wxTreeEvent&);
        T100VOID                    OnItemExpanding(wxTreeEvent&);
        T100VOID                    OnItemActivated(wxTreeEvent&);

        T100VOID                    OnProjectCreate(wxCommandEvent&);
        T100VOID                    OnModuleCreate(wxCommandEvent&);

    protected:
        wxImageList*                m_imageList     = T100NULL;

        wxTreeItemId                AppendRoot(T100WorkSpaceInfo*);
        wxTreeItemId                AppendProject(wxTreeItemId, T100ProjectInfo*);

        wxTreeItemId                AppendFile(wxTreeItemId, T100FileInfo*);
        wxTreeItemId                AppendFolder(wxTreeItemId, T100FolderInfo*);

    private:
        wxMenu*                     GetWorkSpaceMenu();
        wxMenu*                     GetWorkSpaceItemMenu();

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTTREE_H
