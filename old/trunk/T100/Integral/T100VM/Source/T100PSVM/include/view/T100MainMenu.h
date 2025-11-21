#ifndef T100MAINMENU_H
#define T100MAINMENU_H

#include <wx/menu.h>
#include "T100Common.h"

class T100PSVMFrame;

class T100MainMenu
{
    public:
        T100MainMenu();
        virtual ~T100MainMenu();

        virtual T100VOID            Create(T100PSVMFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    Create();
        T100VOID                    Open();
        T100VOID                    Close();
        T100VOID                    Save();
        T100VOID                    Dirty();

        T100VOID                    Start();
        T100VOID                    Stop();

    protected:
        T100PSVMFrame*              m_frame     = T100NULL;

        wxMenuItem*                 m_fileCreate    = T100NULL;
        wxMenuItem*                 m_fileOpen      = T100NULL;
        wxMenuItem*                 m_fileClose     = T100NULL;
        wxMenuItem*                 m_fileSave      = T100NULL;
        wxMenuItem*                 m_fileSaveAs    = T100NULL;
        wxMenuItem*                 m_fileQuit      = T100NULL;

        wxMenuItem*                 m_vmStart       = T100NULL;
        wxMenuItem*                 m_vmStop        = T100NULL;

        wxMenuItem*                 m_debugStart    = T100NULL;
        wxMenuItem*                 m_debugStop     = T100NULL;

        wxMenuItem*                 m_helpAbout     = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100MAINMENU_H
