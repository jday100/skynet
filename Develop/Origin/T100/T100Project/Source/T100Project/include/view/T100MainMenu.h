#ifndef T100MAINMENU_H
#define T100MAINMENU_H

#include <wx/menu.h>
#include "T100Common.h"

class T100ProjectFrame;

class T100MainMenu
{
    public:
        T100MainMenu();
        virtual ~T100MainMenu();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    WorkSpaceOpen();
        T100VOID                    WorkSpaceClose();
        T100VOID                    WorkSpaceModify();
        T100VOID                    WorkSpaceSave();

        T100VOID                    ProjectOpen();
        T100VOID                    ProjectSelect();
        T100VOID                    ProjectBuild();

        T100VOID                    FolderSelect();

        T100VOID                    FileOpen();
        T100VOID                    FileSelect();
        T100VOID                    FileModified();
        T100VOID                    FileSave();

        T100VOID                    ViewWorkSpaceTree(T100BOOL = T100TRUE);
        T100VOID                    ViewSearchResult(T100BOOL = T100TRUE);
        T100VOID                    ViewCompileOutput(T100BOOL = T100TRUE);

        T100VOID                    Clear();

    protected:
        T100ProjectFrame*           m_frame         = T100NULL;

        wxMenuItem*                 m_workNew       = T100NULL;
        wxMenuItem*                 m_workOpen      = T100NULL;
        wxMenuItem*                 m_workClose     = T100NULL;
        wxMenuItem*                 m_workSave      = T100NULL;
        wxMenuItem*                 m_workQuit      = T100NULL;

        wxMenuItem*                 m_projectNew    = T100NULL;
        wxMenuItem*                 m_projectOpen   = T100NULL;
        wxMenuItem*                 m_projectClose  = T100NULL;
        wxMenuItem*                 m_projectSave   = T100NULL;
        wxMenuItem*                 m_projectSaveAs = T100NULL;

        wxMenuItem*                 m_fileNew       = T100NULL;
        wxMenuItem*                 m_fileOpen      = T100NULL;
        wxMenuItem*                 m_fileClose     = T100NULL;
        wxMenuItem*                 m_fileSave      = T100NULL;
        wxMenuItem*                 m_fileSaveAs    = T100NULL;
        wxMenuItem*                 m_fileRemove    = T100NULL;

        wxMenuItem*                 m_undo          = T100NULL;
        wxMenuItem*                 m_redo          = T100NULL;
        wxMenuItem*                 m_cut           = T100NULL;
        wxMenuItem*                 m_copy          = T100NULL;
        wxMenuItem*                 m_paste         = T100NULL;

        wxMenuItem*                 m_viewWork      = T100NULL;
        wxMenuItem*                 m_viewSearch    = T100NULL;
        wxMenuItem*                 m_viewOutput    = T100NULL;

        wxMenuItem*                 m_find          = T100NULL;
        wxMenuItem*                 m_replace       = T100NULL;

        wxMenuItem*                 m_run           = T100NULL;
        wxMenuItem*                 m_buildAndRun   = T100NULL;
        wxMenuItem*                 m_build         = T100NULL;
        wxMenuItem*                 m_clean         = T100NULL;
        wxMenuItem*                 m_rebuild       = T100NULL;

        wxMenuItem*                 m_start         = T100NULL;
        wxMenuItem*                 m_stop          = T100NULL;

        wxMenuItem*                 m_setupEditor   = T100NULL;
        wxMenuItem*                 m_setupCompiler = T100NULL;

        wxMenuItem*                 m_about         = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100MAINMENU_H
