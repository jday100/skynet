#ifndef T100PROJECTSKELETAL_H
#define T100PROJECTSKELETAL_H

#include "T100ProjectView.h"
#include "T100WorkSpaceServe.h"

#include "T100ProjectSkeletalBase.h"

class T100FileData;
class T100FolderData;

class T100ProjectSkeletal : public T100ProjectSkeletalBase
{
    public:
        T100ProjectSkeletal();
        virtual ~T100ProjectSkeletal();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    OnWorkSpaceNew();
        T100VOID                    OnWorkSpaceOpen();
        T100VOID                    OnWorkSpaceClose();
        T100VOID                    OnWorkSpaceSave();
        T100VOID                    OnWorkSpaceSaveAs();
        T100VOID                    OnProjectNew();
        T100VOID                    OnProjectOpen();
        T100VOID                    OnProjectClose();
        T100VOID                    OnProjectSave();
        T100VOID                    OnProjectSaveAs();
        T100VOID                    OnFileNew();
        T100VOID                    OnFileOpen();
        T100VOID                    OnFileClose();
        T100VOID                    OnFileSave();
        T100VOID                    OnFileSaveAs();
        T100VOID                    OnEditUndo();
        T100VOID                    OnEditRedo();
        T100VOID                    OnEditCut();
        T100VOID                    OnEditCopy();
        T100VOID                    OnEditPaste();
        T100VOID                    OnSearchFind();
        T100VOID                    OnSearchReplace();
        T100VOID                    OnCompileBuild();
        T100VOID                    OnSetupEditor();
        T100VOID                    OnSetupCompiler();
        T100VOID                    OnHelpAbout();

        T100VOID                    OnResize();
        T100VOID                    OnQuit();

        T100VOID                    OnFolderNew();
        T100VOID                    OnFolderSelected();

        T100VOID                    OnFileOpen(T100FileData*);
        T100VOID                    OnFolderOpen(T100FolderData*);

        T100VOID                    OnProjectSelected();

        T100VOID                    OnPageClosed();

        T100VOID                    OnItemExpanding();
        T100VOID                    OnModified();

        T100VOID                    OnProjectCreateWizardFinished();

    protected:

    private:
};

#endif // T100PROJECTSKELETAL_H
