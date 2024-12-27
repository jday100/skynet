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
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100EditorFrame: public wxFrame
{
    public:

        T100EditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100EditorFrame();

    private:

        //(*Handlers(T100EditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItemNewSelected(wxCommandEvent& event);
        void OnMenuItemOpenSelected(wxCommandEvent& event);
        void OnMenuItemCloseSelected(wxCommandEvent& event);
        void OnMenuItemSaveSelected(wxCommandEvent& event);
        void OnMenuItemSaveAsSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100EditorFrame)
        static const long ID_MENUITEM_NEW;
        static const long ID_MENUITEM_OPEN;
        static const long ID_MENUITEM_CLOSE;
        static const long ID_MENUITEM_SAVE;
        static const long ID_MENUITEM_SAVE_AS;
        static const long idMenuQuit;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM7;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100EditorFrame)
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenu* Menu5;
        wxMenu* Menu6;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxMenuItem* MenuItem9;
        wxMenuItem* MenuItemClose;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemOpen;
        wxMenuItem* MenuItemSave;
        wxMenuItem* MenuItemSaveAs;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100EDITORMAIN_H
