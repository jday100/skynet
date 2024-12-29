/***************************************************************
 * Name:      T100EditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100EDITORMAIN_H
#define T100EDITORMAIN_H

//(*Headers(T100EditorFrame)
#include <wx/aui/aui.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100Common.h"

class T100EditorFrame: public wxFrame
{
    public:

        T100EditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100EditorFrame();

        wxAuiManager*           getAuiManager();

    private:
        T100VOID                create();
        T100VOID                destroy();

    private:

        //(*Handlers(T100EditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
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
        void OnMenuItemFindSelected(wxCommandEvent& event);
        void OnMenuItemReplaceSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100EditorFrame)
        static const long ID_AUITOOLBARITEM1;
        static const long ID_AUITOOLBAR1;
        static const long ID_MENUITEM_NEW;
        static const long ID_MENUITEM_OPEN;
        static const long ID_MENUITEM_CLOSE;
        static const long ID_MENUITEM_SAVE;
        static const long ID_MENUITEM_SAVE_AS;
        static const long idMenuQuit;
        static const long ID_MENUITEM_UNDO;
        static const long ID_MENUITEM_REDO;
        static const long ID_MENUITEM_CUT;
        static const long ID_MENUITEM_COPY;
        static const long ID_MENUITEM_PASTE;
        static const long ID_MENUITEM_FIND;
        static const long ID_MENUITEM_REPLACE;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100EditorFrame)
        wxAuiManager* AuiManager;
        wxAuiToolBar* AuiToolBar1;
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenu* Menu5;
        wxMenu* Menu6;
        wxMenuItem* MenuItemClose;
        wxMenuItem* MenuItemCopy;
        wxMenuItem* MenuItemCut;
        wxMenuItem* MenuItemFind;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemOpen;
        wxMenuItem* MenuItemPaste;
        wxMenuItem* MenuItemRedo;
        wxMenuItem* MenuItemReplace;
        wxMenuItem* MenuItemSave;
        wxMenuItem* MenuItemSaveAs;
        wxMenuItem* MenuItemUndo;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100EDITORMAIN_H
