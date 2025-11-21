#ifndef T100EDITORFRAME_H
#define T100EDITORFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100TextCtrl.h"
#include "editor/T100Editor.h"
#include "gui/T100AllEvents.h"
#include "gui/common/T100EventCommon.h"

using namespace T100WINDOWS;

enum{
    T100MENU_NEW        = T100MENU_ID_USER,
    T100MENU_OPEN,
    T100MENU_CLOSE,
    T100MENU_SAVE,
    T100MENU_SAVE_AS,
    T100MENU_QUIT,
    T100MENU_UNDO,
    T100MENU_REDO,
    T100MENU_CUT,
    T100MENU_COPY,
    T100MENU_PASTE,
    T100MENU_FONT,
    T100MENU_FIND,
    T100MENU_REPLACE,
    T100MENU_CONFIG,
    T100MENU_ABOUT
};

class T100EditorFrame : public T100Frame
{
    public:
        T100EditorFrame();
        virtual ~T100EditorFrame();

        virtual T100VOID            Create(T100Win32Application*);
        virtual T100VOID            Destroy();

        T100TextCtrl*               GetTextCtrl();

        T100VOID                    SetDirty();
        T100VOID                    ClearDirty();

        T100VOID                    SetTitle(T100WSTRING);

    protected:
        T100Editor*                 m_editor        = T100NULL;
        T100TextCtrl*               m_textCtrl      = T100NULL;

        T100MenuBar*                m_menuBar       = T100NULL;
        T100Menu*                   m_fileMenu      = T100NULL;
        T100Menu*                   m_editMenu      = T100NULL;
        T100Menu*                   m_viewMenu      = T100NULL;
        T100Menu*                   m_searchMenu    = T100NULL;
        T100Menu*                   m_settingMenu   = T100NULL;
        T100Menu*                   m_helpMenu      = T100NULL;

        T100MenuItem*               m_newItem       = T100NULL;
        T100MenuItem*               m_openItem      = T100NULL;
        T100MenuItem*               m_closeItem     = T100NULL;
        T100MenuItem*               m_saveItem      = T100NULL;
        T100MenuItem*               m_saveAsItem    = T100NULL;
        T100MenuItem*               m_quitItem      = T100NULL;

        T100MenuItem*               m_undoItem      = T100NULL;
        T100MenuItem*               m_redoItem      = T100NULL;
        T100MenuItem*               m_cutItem       = T100NULL;
        T100MenuItem*               m_copyItem      = T100NULL;
        T100MenuItem*               m_pasteItem     = T100NULL;

        T100MenuItem*               m_fontItem      = T100NULL;

        T100MenuItem*               m_findItem      = T100NULL;
        T100MenuItem*               m_replaceItem   = T100NULL;

        T100MenuItem*               m_configItem    = T100NULL;

        T100MenuItem*               m_aboutItem     = T100NULL;

    private:
        T100VOID                    OnMenuNew(T100MenuEvent&);
        T100VOID                    OnMenuOpen(T100MenuEvent&);
        T100VOID                    OnMenuClose(T100MenuEvent&);
        T100VOID                    OnMenuSave(T100MenuEvent&);
        T100VOID                    OnMenuSaveAs(T100MenuEvent&);
        T100VOID                    OnMenuQuit(T100MenuEvent&);
        T100VOID                    OnMenuUndo(T100MenuEvent&);
        T100VOID                    OnMenuRedo(T100MenuEvent&);
        T100VOID                    OnMenuCut(T100MenuEvent&);
        T100VOID                    OnMenuCopy(T100MenuEvent&);
        T100VOID                    OnMenuPaste(T100MenuEvent&);
        T100VOID                    OnMenuFont(T100MenuEvent&);
        T100VOID                    OnMenuFind(T100MenuEvent&);
        T100VOID                    OnMenuReplace(T100MenuEvent&);
        T100VOID                    OnMenuConfig(T100MenuEvent&);
        T100VOID                    OnMenuAbout(T100MenuEvent&);

        T100VOID                    OnKeyDown(T100KeyEvent&);

    private:
        T100WSTRING                 m_project       = L"T100Editor";
        T100WSTRING                 m_filename;
};


#endif // T100EDITORFRAME_H
