#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include "T100ProjectViewBase.h"

class T100WorkSpaceInfo;
class T100ProjectInfo;
class T100ModuleInfo;
class wxTreeItemId;

class T100ProjectView : public T100ProjectViewBase
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

        T100BOOL                    WorkSpaceOpen(T100WorkSpaceInfo*);
        T100BOOL                    WorkSpaceClose();

        T100BOOL                    ProjectAppend(T100ProjectInfo*);
        T100BOOL                    ProjectOpen(wxTreeItemId, T100ProjectInfo*);
        T100BOOL                    ProjectSelect();
        T100BOOL                    ProjectBuild();


        T100BOOL                    FolderList(wxTreeItemId, T100FolderInfo*);

        T100BOOL                    FileSelect();
        T100BOOL                    FileSelect(wxTreeItemId, T100FileInfo*);
        T100BOOL                    FileSelect(T100FileInfo*);
        T100BOOL                    FileOpen(wxTreeItemId, T100FileInfo*);
        T100BOOL                    FileOpen(T100FileInfo*);
        T100VOID                    FileModified();
        T100BOOL                    FileSave();
        T100BOOL                    FileSaveAs(T100WxFileInfo*);
        T100BOOL                    FileRemove(T100FileInfo*);
        T100BOOL                    FileRemove(wxTreeItemId, T100FileInfo*);

        T100BOOL                    DebugPrint(const T100WSTRING&);

        T100BOOL                    Clear();
        T100BOOL                    Quit();

        T100BOOL                    ModuleAppend(T100WorkSpaceInfo*, T100ProjectInfo*, T100ModuleInfo*);

        wxTreeItemId                GetSelection();
        const T100WSTRING           GetCurrentFilePath();

    protected:
        T100BOOL                    CheckMainPanel();

    private:
};

#endif // T100PROJECTVIEW_H
