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

        T100VOID            Init();

        T100VOID            New();
        T100VOID            Open();
        T100VOID            Close();
        T100VOID            Save();

        T100VOID            SetSave(T100BOOL = T100TRUE);

        T100VOID            SetManager(T100BOOL = T100TRUE);
        T100VOID            UpdateManager();
        T100VOID            SetProperties(T100BOOL = T100TRUE);

    protected:
        wxFrame*            m_frame         = T100NULL;
        wxMenuBar*          m_menuBar       = T100NULL;
        wxMenu*             m_menuFile      = T100NULL;
        wxMenu*             m_menuEdit      = T100NULL;
        wxMenu*             m_menuView      = T100NULL;
        wxMenu*             m_menuSettings  = T100NULL;
        wxMenu*             m_menuHelp      = T100NULL;

        wxMenuItem*         m_itemNew           = T100NULL;
        wxMenuItem*         m_itemOpen          = T100NULL;
        wxMenuItem*         m_itemClose         = T100NULL;
        wxMenuItem*         m_itemSave          = T100NULL;
        wxMenuItem*         m_itemSaveAs        = T100NULL;
        wxMenuItem*         m_itemImport        = T100NULL;
        wxMenuItem*         m_itemExport        = T100NULL;
        wxMenuItem*         m_itemQuit          = T100NULL;
        wxMenuItem*         m_itemUndo          = T100NULL;
        wxMenuItem*         m_itemRedo          = T100NULL;
        wxMenuItem*         m_itemCut           = T100NULL;
        wxMenuItem*         m_itemCopy          = T100NULL;
        wxMenuItem*         m_itemPaste         = T100NULL;
        wxMenuItem*         m_itemManager       = T100NULL;
        wxMenuItem*         m_itemProperties    = T100NULL;
        wxMenuItem*         m_itemConfig        = T100NULL;
        wxMenuItem*         m_itemAbout         = T100NULL;

    private:
        T100VOID            init();
        T100VOID            uninit();

        T100VOID            Destroy();
};

#endif // T1003DEDITORMAINMENU_H
