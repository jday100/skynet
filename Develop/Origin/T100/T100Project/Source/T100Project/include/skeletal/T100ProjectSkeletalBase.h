#ifndef T100PROJECTSKELETALBASE_H
#define T100PROJECTSKELETALBASE_H

#include "T100ProjectView.h"
#include "T100WxFolderInfo.h"
#include "T100WorkSpaceServe.h"

class T100ProjectSkeletalBase
{
    public:
        T100ProjectSkeletalBase();
        virtual ~T100ProjectSkeletalBase();

        T100BOOL                    WorkSpaceNew(const T100WxFolderInfo&);
        T100VOID                    WorkSpaceOpen(const T100WxFolderInfo&);
        T100BOOL                    WorkSpaceClose();
        T100VOID                    WorkSpaceSave();
        T100VOID                    WorkSpaceSaveAs();
        T100VOID                    ProjectNew();
        T100VOID                    ProjectOpen();
        T100VOID                    ProjectClose();
        T100VOID                    ProjectSave();
        T100VOID                    ProjectSaveAs();
        T100VOID                    FileNew();
        T100VOID                    FileOpen();
        T100VOID                    FileClose();
        T100VOID                    FileSave();
        T100VOID                    FileSaveAs();
        T100VOID                    EditUndo();
        T100VOID                    EditRedo();
        T100VOID                    EditCut();
        T100VOID                    EditCopy();
        T100VOID                    EditPaste();
        T100VOID                    SearchFind();
        T100VOID                    SearchReplace();
        T100VOID                    CompileBuild();
        T100VOID                    SetupEditor();
        T100VOID                    SetupCompiler();
        T100VOID                    HelpAbout();

    protected:
        T100ProjectView*            m_view      = T100NULL;
        T100WorkSpaceServe*         m_serve     = T100NULL;

    private:
};

#endif // T100PROJECTSKELETALBASE_H
