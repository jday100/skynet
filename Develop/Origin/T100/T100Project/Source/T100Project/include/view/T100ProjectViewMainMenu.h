#ifndef T100PROJECTVIEWMAINMENU_H
#define T100PROJECTVIEWMAINMENU_H

#include <wx/menu.h>
#include "T100Common.h"

class T100ProjectFrame;

class T100ProjectViewMainMenu
{
    public:
        T100ProjectViewMainMenu();
        virtual ~T100ProjectViewMainMenu();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    Clear();

        T100VOID                    WorkSpaceSelect();

        T100VOID                    ProjectSelect();

        T100VOID                    FileOpen();
        T100VOID                    FileModified();

        T100VOID                    FolderSelected();

    protected:
        T100ProjectFrame*           m_frame     = T100NULL;

        wxMenuItem*                 m_workNew       = T100NULL;
        wxMenuItem*                 m_workOpen      = T100NULL;
        wxMenuItem*                 m_workClose     = T100NULL;
        wxMenuItem*                 m_workSave      = T100NULL;
        wxMenuItem*                 m_workSaveAs    = T100NULL;
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

        wxMenuItem*                 m_undo          = T100NULL;
        wxMenuItem*                 m_redo          = T100NULL;
        wxMenuItem*                 m_cut           = T100NULL;
        wxMenuItem*                 m_copy          = T100NULL;
        wxMenuItem*                 m_paste         = T100NULL;

        wxMenuItem*                 m_workspace     = T100NULL;
        wxMenuItem*                 m_search        = T100NULL;
        wxMenuItem*                 m_output        = T100NULL;

        wxMenuItem*                 m_find          = T100NULL;
        wxMenuItem*                 m_replace       = T100NULL;

        wxMenuItem*                 m_build         = T100NULL;

        wxMenuItem*                 m_editor        = T100NULL;
        wxMenuItem*                 m_compiler      = T100NULL;

        wxMenuItem*                 m_about         = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PROJECTVIEWMAINMENU_H
