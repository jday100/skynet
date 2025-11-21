#ifndef T100MAINMENU_H
#define T100MAINMENU_H

#include <wx/menu.h>
#include "T100Common.h"

class T100DiagramFrame;

class T100MainMenu
{
    public:
        T100MainMenu();
        virtual ~T100MainMenu();

        virtual T100VOID            Create(T100DiagramFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    Dirty();
        T100VOID                    Open();
        T100VOID                    Close();
        T100VOID                    Save();

        T100VOID                    ViewManager(T100BOOL);
        T100VOID                    ViewProperty(T100BOOL);

    protected:
        T100DiagramFrame*           m_frame         = T100NULL;

        wxMenuItem*                 m_fileCreate    = T100NULL;
        wxMenuItem*                 m_fileOpen      = T100NULL;
        wxMenuItem*                 m_fileClose     = T100NULL;
        wxMenuItem*                 m_fileSave      = T100NULL;
        wxMenuItem*                 m_fileSaveAs    = T100NULL;
        wxMenuItem*                 m_fileQuit      = T100NULL;

        wxMenuItem*                 m_undo          = T100NULL;
        wxMenuItem*                 m_redo          = T100NULL;
        wxMenuItem*                 m_cut           = T100NULL;
        wxMenuItem*                 m_copy          = T100NULL;
        wxMenuItem*                 m_paste         = T100NULL;

        wxMenuItem*                 m_viewManager   = T100NULL;
        wxMenuItem*                 m_viewProperty  = T100NULL;

        wxMenuItem*                 m_find          = T100NULL;

        wxMenuItem*                 m_import        = T100NULL;

        wxMenuItem*                 m_config        = T100NULL;

        wxMenuItem*                 m_about         = T100NULL;

    private:
        T100VOID                    init();
};

#endif // T100MAINMENU_H
