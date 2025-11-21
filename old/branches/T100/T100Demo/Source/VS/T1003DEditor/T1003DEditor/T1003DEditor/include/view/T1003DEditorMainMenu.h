#ifndef T1003DEDITORMAINMENU_H
#define T1003DEDITORMAINMENU_H

#include <wx/menu.h>
#include "T100Common.h"

class wxFrame;

class T1003DEditorMainMenu
{
    public:
        T1003DEditorMainMenu();
        virtual ~T1003DEditorMainMenu();

        T100VOID            Create(wxFrame*);

        T100VOID            New();
        T100VOID            Open();
        T100VOID            Save();

        T100VOID            SetSave(T100BOOL = T100TRUE);

        T100VOID            SetManager(T100BOOL = T100TRUE);
        T100VOID            UpdateManager();
        T100VOID            SetProperties(T100BOOL = T100TRUE);

    public:
        static const long ID_MENU_NEW;
        static const long ID_MENU_OPEN;
        static const long ID_MENU_CLOSE;
        static const long ID_MENU_SAVE;
        static const long ID_MENU_SAVE_AS;
        static const long ID_MENU_IMPORT;
        static const long ID_MENU_EXPORT;

        static const long ID_MENU_QUIT;

        static const long ID_MENU_UNDO;
        static const long ID_MENU_REDO;
        static const long ID_MENU_CUT;
        static const long ID_MENU_COPY;
        static const long ID_MENU_PASTE;

        static const long ID_MENU_MANAGER;
        static const long ID_MENU_PROPERTIES;

        static const long ID_MENU_CONFIG;

    protected:
        wxFrame*                    m_framePtr          = T100NULL;
        wxMenuBar*                  m_menuBarPtr        = T100NULL;

        wxMenu*                     m_menuFilePtr       = T100NULL;
        wxMenu*                     m_menuEditPtr       = T100NULL;
        wxMenu*                     m_menuViewPtr       = T100NULL;
        wxMenu*                     m_menuSettingsPtr   = T100NULL;
        wxMenu*                     m_menuHelpPtr       = T100NULL;

        wxMenuItem*                 m_itemNewPtr        = T100NULL;
        wxMenuItem*                 m_itemOpenPtr       = T100NULL;
        wxMenuItem*                 m_itemClosePtr      = T100NULL;
        wxMenuItem*                 m_itemSavePtr       = T100NULL;
        wxMenuItem*                 m_itemSaveAsPtr     = T100NULL;
        wxMenuItem*                 m_itemImportPtr     = T100NULL;
        wxMenuItem*                 m_itemExportPtr     = T100NULL;
        wxMenuItem*                 m_itemQuitPtr       = T100NULL;

        wxMenuItem*                 m_itemUndoPtr       = T100NULL;
        wxMenuItem*                 m_itemRedoPtr       = T100NULL;
        wxMenuItem*                 m_itemCutPtr        = T100NULL;
        wxMenuItem*                 m_itemCopyPtr       = T100NULL;
        wxMenuItem*                 m_itemPastePtr      = T100NULL;

        wxMenuItem*                 m_itemManagerPtr    = T100NULL;
        wxMenuItem*                 m_itemPropertiesPtr = T100NULL;

        wxMenuItem*                 m_itemConfigPtr     = T100NULL;

        wxMenuItem*                 m_itemAboutPtr      = T100NULL;

    protected:
        void OnMenuItemManagerSelected(wxCommandEvent& event);
        void OnMenuItemPropertiesSelected(wxCommandEvent& event);

    private:
        T100VOID                    init();
        T100VOID                    uninit();

        T100VOID                    createFileMenu();
        T100VOID                    createEditMenu();
        T100VOID                    createViewMenu();
        T100VOID                    createSettingsMenu();
        T100VOID                    createHelpMenu();

        T100VOID                    Destroy();
};

#endif // T1003DEDITORMAINMENU_H
