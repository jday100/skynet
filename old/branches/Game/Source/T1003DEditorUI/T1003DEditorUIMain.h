/***************************************************************
 * Name:      T1003DEditorUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-03-02
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T1003DEDITORUIMAIN_H
#define T1003DEDITORUIMAIN_H

//(*Headers(T1003DEditorUIFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include <wx/aui/aui.h>

#include "T100Common.h"

class T1003DEditorUIFrame: public wxFrame
{
    public:

        T1003DEditorUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T1003DEditorUIFrame();

        T100VOID            SetStatus(T100UINT, wxString);

    private:
        T100VOID            init();
        T100VOID            uninit();

        void OnAuiPaneClose(wxAuiManagerEvent& event);

        //(*Handlers(T1003DEditorUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnMenuItemNewSelected(wxCommandEvent& event);
        void OnMenuItemOpenSelected(wxCommandEvent& event);
        void OnMenuItemCloseSelected(wxCommandEvent& event);
        void OnMenuItemSaveSelected(wxCommandEvent& event);
        void OnMenuItemSaveAsSelected(wxCommandEvent& event);
        void OnMenuItemUndoSelected(wxCommandEvent& event);
        void OnMenuItemRedoSelected(wxCommandEvent& event);
        void OnMenuItemCutSelected(wxCommandEvent& event);
        void OnMenuItemCopySelected(wxCommandEvent& event);
        void OnMenuItemPasteSelected(wxCommandEvent& event);
        void OnMenuItemManagerSelected(wxCommandEvent& event);
        void OnMenuItemPropertiesSelected(wxCommandEvent& event);
        void OnMenuItemConfigSelected(wxCommandEvent& event);
        void OnMenuItemImportSelected(wxCommandEvent& event);
        void OnMenuItemExportSelected(wxCommandEvent& event);
        void OnMenuItemSettingsSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T1003DEditorUIFrame)
        static const long ID_MENU_NEW;
        static const long ID_MENU_OPEN;
        static const long ID_MENU_CLOSE;
        static const long ID_MENU_SAVE;
        static const long ID_MENU_SAVE_AS;
        static const long ID_MENU_IMPORT;
        static const long ID_MENU_EXPORT;
        static const long idMenuQuit;
        static const long ID_MENU_UNDO;
        static const long ID_MENU_REDO;
        static const long ID_MENU_CUT;
        static const long ID_MENU_COPY;
        static const long ID_MENU_PASTE;
        static const long ID_MENU_MANAGER;
        static const long ID_MENU_PROPERTIES;
        static const long ID_MENU_CONFIG;
        static const long ID_MENU_SETTINGS;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T1003DEditorUIFrame)
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenu* Menu5;
        wxMenuItem* MenuItemClose;
        wxMenuItem* MenuItemConfig;
        wxMenuItem* MenuItemCopy;
        wxMenuItem* MenuItemCut;
        wxMenuItem* MenuItemExport;
        wxMenuItem* MenuItemImport;
        wxMenuItem* MenuItemManager;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemOpen;
        wxMenuItem* MenuItemPaste;
        wxMenuItem* MenuItemProperties;
        wxMenuItem* MenuItemRedo;
        wxMenuItem* MenuItemSave;
        wxMenuItem* MenuItemSaveAs;
        wxMenuItem* MenuItemSettings;
        wxMenuItem* MenuItemUndo;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORUIMAIN_H
