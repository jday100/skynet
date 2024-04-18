/***************************************************************
 * Name:      T100PainterMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-04-14
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100PAINTERMAIN_H
#define T100PAINTERMAIN_H

//(*Headers(T100PainterFrame)
#include <wx/aui/aui.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)
#include "T100Common.h"

class T100PainterFrame: public wxFrame
{
    public:

        T100PainterFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100PainterFrame();

        wxAuiManager*       getAuiManager();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:

        //(*Handlers(T100PainterFrame)
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
        void OnMenuItemConfigSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100PainterFrame)
        static const long ID_AUITOOLBARITEM1;
        static const long ID_AUITOOLBARLABEL1;
        static const long ID_AUITOOLBAR1;
        static const long ID_MENUITEM_NEW;
        static const long ID_MENUITEM_OPEN;
        static const long ID_MENUITEM_CLOSE;
        static const long ID_MENUITEM_SAVE;
        static const long ID_MENUITEM_SAVE_AS;
        static const long ID_MENUITEM_QUIT;
        static const long ID_MENUITEM_UNDO;
        static const long ID_MENUITEM_REDO;
        static const long ID_MENUITEM_CUT;
        static const long ID_MENUITEM_COPY;
        static const long ID_MENUITEM_PASTE;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM_CONFIG;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100PainterFrame)
        wxAuiManager* AuiManager1;
        wxAuiToolBar* AuiToolBar1;
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenu* Menu5;
        wxMenuItem* MenuItem13;
        wxMenuItem* MenuItem14;
        wxMenuItem* MenuItemClose;
        wxMenuItem* MenuItemConfig;
        wxMenuItem* MenuItemCopy;
        wxMenuItem* MenuItemCut;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemOpen;
        wxMenuItem* MenuItemPaste;
        wxMenuItem* MenuItemRedo;
        wxMenuItem* MenuItemSave;
        wxMenuItem* MenuItemSaveAs;
        wxMenuItem* MenuItemUndo;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100PAINTERMAIN_H
