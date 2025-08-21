#ifndef T100PROJECTINVOKING_H
#define T100PROJECTINVOKING_H

#include "T100Common.h"
class T100FileData;
class T100FolderData;
class T100ProjectData;
class T100ProjectFrame;
class T100ProjectSkeletal;
class T100WxProjectInfo;
class T100Pack;

class T100ProjectInvoking
{
    public:
        T100ProjectInvoking();
        virtual ~T100ProjectInvoking();

        static T100VOID                     Init(T100ProjectFrame*);
        static T100VOID                     Uninit();

        static T100VOID                     OnWorkSpaceNew();
        static T100VOID                     OnWorkSpaceOpen();
        static T100VOID                     OnWorkSpaceClose();
        static T100VOID                     OnWorkSpaceSave();
        static T100VOID                     OnWorkSpaceSaveAs();
        static T100VOID                     OnProjectNew();
        static T100VOID                     OnProjectOpen();
        static T100VOID                     OnProjectClose();
        static T100VOID                     OnProjectSave();
        static T100VOID                     OnProjectSaveAs();
        static T100VOID                     OnFileNew();
        static T100VOID                     OnFileOpen();
        static T100VOID                     OnFileClose();
        static T100VOID                     OnFileSave();
        static T100VOID                     OnFileSaveAs();
        static T100VOID                     OnEditUndo();
        static T100VOID                     OnEditRedo();
        static T100VOID                     OnEditCut();
        static T100VOID                     OnEditCopy();
        static T100VOID                     OnEditPaste();
        static T100VOID                     OnSearchFind();
        static T100VOID                     OnSearchReplace();
        static T100VOID                     OnCompileBuild();
        static T100VOID                     OnSetupEditor();
        static T100VOID                     OnSetupCompiler();
        static T100VOID                     OnHelpAbout();
        static T100VOID                     OnResize();
        static T100VOID                     OnQuit();

        static T100VOID                     OnFolderNew();
        static T100VOID                     OnFolderSelected();

        static T100VOID                     OnFileOpen(T100FileData*);
        static T100VOID                     OnFolderOpen(T100FolderData*);
        static T100VOID                     OnProjectOpen(T100ProjectData*);

        static T100VOID                     OnProjectSelected();
        static T100VOID                     OnWorkSpaceSelected();

        static T100VOID                     OnPageChanged();
        static T100VOID                     OnPageClosing(T100Pack*);
        static T100VOID                     OnPageClosed();

        static T100VOID                     OnItemExpanding();
        static T100VOID                     OnModified();

        static T100VOID                     OnProjectCreateWizardFinished(T100WxProjectInfo*);

    protected:

    private:
        static T100ProjectSkeletal*         m_skeletal;
};

#endif // T100PROJECTINVOKING_H
