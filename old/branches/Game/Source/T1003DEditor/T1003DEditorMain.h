/***************************************************************
 * Name:      T1003DEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-01-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T1003DEDITORMAIN_H
#define T1003DEDITORMAIN_H

//(*Headers(T1003DEditorFrame)
#include <wx/frame.h>
#include <wx/imaglist.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100Common.h"

class T1003DEditorSkeletal;

class T1003DEditorFrame: public wxFrame
{
    public:

        T1003DEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T1003DEditorFrame();

    private:
        T1003DEditorSkeletal*       m_skeletal          = T100NULL;

        //(*Handlers(T1003DEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnEraseBackground(wxEraseEvent& event);
        void OnKeyDown(wxKeyEvent& event);
        void OnKeyUp(wxKeyEvent& event);
        void OnMouseWheel(wxMouseEvent& event);
        void OnResize(wxSizeEvent& event);
        void OnMouseMove(wxMouseEvent& event);
        void OnLeftDown(wxMouseEvent& event);
        void OnLeftUp(wxMouseEvent& event);
        void OnRightDown(wxMouseEvent& event);
        void OnRightUp(wxMouseEvent& event);
        void OnMenuItemConfigSelected(wxCommandEvent& event);
        void OnChar(wxKeyEvent& event);
        void OnMenuItemNewSelected(wxCommandEvent& event);
        void OnMenuItemOpenSelected(wxCommandEvent& event);
        void OnMenuItemSaveSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T1003DEditorFrame)
        static const long ID_MENU_NEW;
        static const long ID_MENU_OPEN;
        static const long ID_MENUITEM3;
        static const long ID_MENU_SAVE;
        static const long ID_MENUITEM5;
        static const long idMenuQuit;
        static const long ID_MENUITEM_CONFIG;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T1003DEditorFrame)
        wxImageList* ImageList1;
        wxMenu* Menu3;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItemConfig;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemOpen;
        wxMenuItem* MenuItemSave;
        wxStatusBar* StatusBar1;
        //*)

        T100VOID                        init();
        T100VOID                        uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORMAIN_H
