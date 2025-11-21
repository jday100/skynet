#ifndef T100PROJECTMAINMENU_H
#define T100PROJECTMAINMENU_H

#include "gui/T100Menu.h"
#include "gui/T100MenuBar.h"
#include "T100ProjectMainMenuActuator.h"

using namespace T100WINDOWS;

#define     T100PROJECT_VIEW_MAIN_MENU_FILE_NEW                         L"T100Project.View.Main.Menu.File.New"
#define     T100PROJECT_VIEW_MAIN_MENU_FILE_OPEN                        L"T100Project.View.Main.Menu.File.Open"
#define     T100PROJECT_VIEW_MAIN_MENU_FILE_CLOSE                       L"T100Project.View.Main.Menu.File.Close"
#define     T100PROJECT_VIEW_MAIN_MENU_FILE_SAVE                        L"T100Project.View.Main.Menu.File.Save"
#define     T100PROJECT_VIEW_MAIN_MENU_FILE_SAVE_AS                     L"T100Project.View.Main.Menu.File.Save.As"
#define     T100PROJECT_VIEW_MAIN_MENU_FILE_QUIT                        L"T100Project.View.Main.Menu.File.Quit"

#define     T100PROJECT_VIEW_MAIN_MENU_EDIT_UNDO                        L"T100Project.View.Main.Menu.Edit.Undo"
#define     T100PROJECT_VIEW_MAIN_MENU_EDIT_REDO                        L"T100Project.View.Main.Menu.Edit.Redo"
#define     T100PROJECT_VIEW_MAIN_MENU_EDIT_CUT                         L"T100Project.View.Main.Menu.Edit.Cut"
#define     T100PROJECT_VIEW_MAIN_MENU_EDIT_COPY                        L"T100Project.View.Main.Menu.Edit.Copy"
#define     T100PROJECT_VIEW_MAIN_MENU_EDIT_PASTE                       L"T100Project.View.Main.Menu.Edit.Paste"

#define     T100PROJECT_VIEW_MAIN_MENU_VIEW                             L"T100Project.View.Main.Menu.View"

#define     T100PROJECT_VIEW_MAIN_MENU_SEARCH_FIND                      L"T100Project.View.Main.Menu.Search.Find"
#define     T100PROJECT_VIEW_MAIN_MENU_SEARCH_REPLACE                   L"T100Project.View.Main.Menu.Search.Replace"

#define     T100PROJECT_VIEW_MAIN_MENU_HELP_ABOUT                       L"T100Project.View.Main.Menu.Help.About"


enum {
    T100MAIN_MENU_FILE_NEW          = 1000,
    T100MAIN_MENU_FILE_OPEN,
    T100MAIN_MENU_FILE_CLOSE,
    T100MAIN_MENU_FILE_SAVE,
    T100MAIN_MENU_FILE_SAVE_AS,
    T100MAIN_MENU_FILE_QUIT,

    T100MAIN_MENU_EDIT_UNDO,
    T100MAIN_MENU_EDIT_REDO,
    T100MAIN_MENU_EDIT_CUT,
    T100MAIN_MENU_EDIT_COPY,
    T100MAIN_MENU_EDIT_PASTE,

    T100MAIN_MENU_SEARCH_FIND,
    T100MAIN_MENU_SEARCH_REPLACE,

    T100MAIN_MENU_HELP_ABOUT
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

        T100Menu*                   m_editMenu      = T100NULL;

        T100MenuItem*               m_undoItem      = T100NULL;
        T100MenuItem*               m_redoItem      = T100NULL;
        T100MenuItem*               m_cutItem       = T100NULL;
        T100MenuItem*               m_copyItem      = T100NULL;
        T100MenuItem*               m_pasteItem     = T100NULL;

        T100Menu*                   m_searchMenu    = T100NULL;

        T100MenuItem*               m_findItem      = T100NULL;
        T100MenuItem*               m_replaceItem   = T100NULL;

        T100Menu*                   m_helpMenu      = T100NULL;

        T100MenuItem*               m_aboutItem     = T100NULL;

    private:
        T100ProjectMainMenuActuator             m_actuator;
};

#endif // T100PROJECTMAINMENU_H
