#ifndef T100PROJECTSKELETAL_H
#define T100PROJECTSKELETAL_H

#include "T100ProjectSkeletalBase.h"

class T100FolderInfo;
class T100ProjectInfo;
class T100FileData;
class T100FolderData;
class T100ProjectData;
class T100ProjectFrame;
class T100Pack;
class T100ModuleInfo;
class wxAuiPaneInfo;

class T100ProjectSkeletal : public T100ProjectSkeletalBase
{
    public:
        T100ProjectSkeletal();
        virtual ~T100ProjectSkeletal();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    OnWorkSpaceCreate();
        T100VOID                    OnWorkSpaceCreateDone(T100WorkSpaceInfo*);
        T100VOID                    OnWorkSpaceRemove();
        T100VOID                    OnWorkSpaceOpen();
        T100VOID                    OnWorkSpaceOpenDone();
        T100VOID                    OnWorkSpaceClose();
        T100VOID                    OnWorkSpaceSave();
        T100VOID                    OnWorkSpaceSaveAs();
        T100VOID                    OnWorkSpaceQuit();
        T100VOID                    OnWorkSpaceMouseRightDown();

        T100VOID                    OnProjectCreate();
        T100VOID                    OnProjectCreateDone(T100ProjectInfo*);
        T100VOID                    OnProjectRemove();
        T100VOID                    OnProjectOpen(T100ProjectData*);
        T100VOID                    OnProjectClose();
        T100VOID                    OnProjectSave();
        T100VOID                    OnProjectSaveAs();
        T100VOID                    OnProjectActivated();
        T100VOID                    OnProjectSelect();

        T100VOID                    OnFileCreate();
        T100VOID                    OnFileRemove();
        T100VOID                    OnFileOpen();
        T100VOID                    OnFileOpenDone(T100FileData*);
        T100VOID                    OnFileClose();
        T100VOID                    OnFileSave();
        T100VOID                    OnFileSaveAs();
        T100VOID                    OnFileSelect();

        T100VOID                    OnEditUndo();
        T100VOID                    OnEditRedo();
        T100VOID                    OnEditCut();
        T100VOID                    OnEditCopy();
        T100VOID                    OnEditPaste();

        T100VOID                    OnViewWorkSpaceTree(T100BOOL);
        T100VOID                    OnViewSearchResult(T100BOOL);
        T100VOID                    OnViewCompileOutput(T100BOOL);

        T100VOID                    OnSearchFind();
        T100VOID                    OnSearchReplace();

        T100VOID                    OnCompileRun();
        T100VOID                    OnCompileBuildAndRun();
        T100VOID                    OnCompileBuild();
        T100VOID                    OnCompileClean();
        T100VOID                    OnCompileRebuild();

        T100VOID                    OnDebugStart();
        T100VOID                    OnDebugStop();

        T100VOID                    OnDebugPrint(const T100WSTRING&);

        T100VOID                    OnSetupEditor();
        T100VOID                    OnSetupCompiler();

        T100VOID                    OnHelpAbout();

        T100VOID                    OnFolderList(T100FolderData*);

        T100VOID                    OnMainPanelPageChanged();
        T100VOID                    OnMainPanelPageClosing(T100Pack*);
        T100VOID                    OnMainPanelPageClosed(T100Pack*);

        T100VOID                    OnModified(const T100WSTRING&);

        T100VOID                    OnModuleCreate();
        T100VOID                    OnModuleCreateDone(T100ModuleInfo*);

        T100VOID                    OnAuiPaneClose(wxAuiPaneInfo*);

    protected:

    private:
};

#endif // T100PROJECTSKELETAL_H
