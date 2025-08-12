#ifndef T100PROJECTTREE_H
#define T100PROJECTTREE_H

#include <wx/imaglist.h>
#include <wx/treectrl.h>
#include "T100WorkSpaceInfo.h"

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

        virtual T100VOID            WorkSpaceOpen(T100WorkSpaceInfo*);

        virtual T100VOID            ProjectOpen(T100ProjectInfo*);

        virtual T100VOID            FolderOpen(T100FolderInfo*);

        virtual T100VOID            Clear();

        virtual T100VOID            Load(const T100PROJECT_INFO_VECTOR&);

    protected:
        T100VOID                    OnItemMenu(wxTreeEvent&);
        T100VOID                    OnItemExpanding(wxTreeEvent&);
        T100VOID                    OnProjectCreate(wxCommandEvent&);

    private:
        wxImageList*                m_imageList;

        T100VOID                    init();
        T100VOID                    uninit();

        wxTreeItemId                AppendRoot();
        T100VOID                    AppendProject(wxTreeItemId, T100ProjectInfo*);

        T100VOID                    AppendFile(wxTreeItemId, T100FileInfo*);
        T100VOID                    AppendFolder(wxTreeItemId, T100FolderInfo*);

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTTREE_H
