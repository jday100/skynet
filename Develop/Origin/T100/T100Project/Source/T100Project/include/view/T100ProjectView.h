#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include "T100WorkSpaceInfo.h"
#include "T100ProjectViewBase.h"

class T100ProjectView : public T100ProjectViewBase
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();


        T100VOID                    WorkSpaceOpen(T100WorkSpaceInfo*);
        T100BOOL                    WorkSpaceClose();
        T100VOID                    WorkSpaceSave();
        T100VOID                    WorkSpaceSelected();

        T100VOID                    ProjectOpen(T100ProjectInfo*);
        T100VOID                    ProjectSelected();

        T100VOID                    FileModified();

        T100VOID                    FileOpen(wxTreeItemId, T100FileInfo*);
        T100VOID                    FolderOpen(wxTreeItemId, T100FolderInfo*);

        T100VOID                    FolderSelected();

        T100VOID                    ProjectOpen(wxTreeItemId, T100ProjectInfo*);

        T100VOID                    ShowFileName(T100WSTRING&);
        T100VOID                    ShowSetupEditorDialog();
        T100VOID                    ShowSetupCompilerDialog();

        T100VOID                    Load(const T100PROJECT_INFO_VECTOR&);

        T100VOID                    New();

        T100VOID                    Clear();

        T100VOID                    About();

        T100VOID                    OnResize();


        T100VOID                    New(T100FileInfo*);
        T100VOID                    Open(T100FileInfo*);


        T100VOID                    FileSave();

        T100VOID                    PageChanged();
        T100VOID                    PageClose();

    protected:

    private:
};

#endif // T100PROJECTVIEW_H
