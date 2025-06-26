#ifndef T100PROJECTMAINMENU_H
#define T100PROJECTMAINMENU_H

#include "gui/T100Menu.h"
#include "gui/T100MenuBar.h"
#include "T100ProjectMainMenuActuator.h"

using namespace T100WINDOWS;

#define     T100PROJECT_VIEW_MAIN_MENU_FILE_QUIT                        L"T100Project.View.Main.Menu.File.Quit"

enum {
    T100MAIN_MENU_FILE_NEW          = 1000,
    T100MAIN_MENU_FILE_OPEN,
    T100MAIN_MENU_FILE_CLOSE,
    T100MAIN_MENU_FILE_SAVE,
    T100MAIN_MENU_FILE_SAVE_AS,
    T100MAIN_MENU_FILE_QUIT
};

class T100ProjectMainMenu
{
    public:
        T100ProjectMainMenu(T100Win32Application*);
        virtual ~T100ProjectMainMenu();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

        T100MenuBar*                GetMenuBar();

    protected:
        T100MenuBar*                m_menuBar       = T100NULL;

        T100Menu*                   m_fileMenu      = T100NULL;

        T100MenuItem*               m_newItem       = T100NULL;
        T100MenuItem*               m_openItem      = T100NULL;
        T100MenuItem*               m_closeItem     = T100NULL;
        T100MenuItem*               m_saveItem      = T100NULL;
        T100MenuItem*               m_saveAsItem    = T100NULL;
        T100MenuItem*               m_quitItem      = T100NULL;

    private:
        T100ProjectMainMenuActuator             m_actuator;
};

#endif // T100PROJECTMAINMENU_H
