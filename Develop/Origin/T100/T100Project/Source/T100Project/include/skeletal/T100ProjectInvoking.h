#ifndef T100PROJECTINVOKING_H
#define T100PROJECTINVOKING_H

#include "T100Common.h"

class T100FileData;
class T100FolderData;
class T100ProjectData;
class T100ProjectFrame;
class T100ProjectSkeletal;
class T100ProjectInfo;
class T100WorkSpaceInfo;
class T100Pack;
class T100ModuleInfo;
class wxAuiPaneInfo;

class T100ProjectInvoking
{
    public:
        T100ProjectInvoking();
        virtual ~T100ProjectInvoking();

        static T100VOID                         Init(T100ProjectFrame*);
        static T100VOID                         Uninit();

        static T100VOID                         OnWorkSpaceCreate();
        static T100VOID                         OnWorkSpaceCreateDone(T100WorkSpaceInfo*);
        static T100VOID                         OnWorkSpaceRemove();
        static T100VOID                         OnWorkSpaceOpen();
        static T100VOID                         OnWorkSpaceOpenDone();
        static T100VOID                         OnWorkSpaceClose();
        static T100VOID                         OnWorkSpaceSave();
        static T100VOID                         OnWorkSpaceSaveAs();
        static T100VOID                         OnWorkSpaceQuit();
        static T100VOID                         OnWorkSpaceMouseRightDown();

        static T100VOID                         OnProjectCreate();
        static T100VOID                         OnProjectCreateDone(T100ProjectInfo*);
        static T100VOID                         OnProjectRemove();
        static T100VOID                         OnProjectOpen(T100ProjectData*);
        static T100VOID                         OnProjectClose();
        static T100VOID                         OnProjectSave();
        static T100VOID                         OnProjectSaveAs();
        static T100VOID                         OnProjectActivated();
        static T100VOID                         OnProjectSelect();

        static T100VOID                         OnFileCreate();
        static T100VOID                         OnFileRemove();
        static T100VOID                         OnFileOpen();
        static T100VOID                         OnFileOpenDone(T100FileData*);
        static T100VOID                         OnFileClose();
        static T100VOID                         OnFileSave();
        static T100VOID                         OnFileSaveAs();
        static T100VOID                         OnFileSelect();

        static T100VOID                         OnEditUndo();
        static T100VOID                         OnEditRedo();
        static T100VOID                         OnEditCut();
        static T100VOID                         OnEditCopy();
        static T100VOID                         OnEditPaste();

        static T100VOID                         OnViewWorkSpaceTree(T100BOOL);
        static T100VOID                         OnViewSearchResult(T100BOOL);
        static T100VOID                         OnViewCompileOutput(T100BOOL);

        static T100VOID                         OnSearchFind();
        static T100VOID                         OnSearchReplace();

        static T100VOID                         OnCompileRun();
        static T100VOID                         OnCompileBuildAndRun();
        static T100VOID                         OnCompileBuild();
        static T100VOID                         OnCompileClean();
        static T100VOID                         OnCompileRebuild();

        static T100VOID                         OnDebugStart();
        static T100VOID                         OnDebugStop();

        static T100VOID                         OnDebugPrint(const T100WSTRING&);

        static T100VOID                         OnSetupEditor();
        static T100VOID                         OnSetupCompiler();

        static T100VOID                         OnHelpAbout();

        static T100VOID                         OnFolderCreate();
        static T100VOID                         OnFolderRemove();
        static T100VOID                         OnFolderList(T100FolderData*);
        static T100VOID                         OnFolderClose();

        static T100VOID                         OnMainPanelPageChanged();
        static T100VOID                         OnMainPanelPageClosing(T100Pack*);
        static T100VOID                         OnMainPanelPageClosed(T100Pack*);

        static T100VOID                         OnModified(const T100WSTRING&);

        static T100VOID                         OnModuleCreate();
        static T100VOID                         OnModuleCreateDone(T100ModuleInfo*);

        static T100VOID                         OnAuiPaneClose(wxAuiPaneInfo*);

    protected:

    private:
        static T100ProjectSkeletal*             m_skeletal;
};

#endif // T100PROJECTINVOKING_H
