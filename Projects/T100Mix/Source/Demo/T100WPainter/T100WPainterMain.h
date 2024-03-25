/***************************************************************
 * Name:      T100WPainterMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-24
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100WPAINTERMAIN_H
#define T100WPAINTERMAIN_H

//(*Headers(T100WPainterFrame)
#include <wx/aui/aui.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100Common.h"
#include "T100WPainterCanvas.h"
#include "T100WPainterElementsPanel.h"

class T100WPainterFrame: public wxFrame
{
    public:

        T100WPainterFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100WPainterFrame();

    private:

        //(*Handlers(T100WPainterFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnResize(wxSizeEvent& event);
        void OnMenuItemNewSelected(wxCommandEvent& event);
        void OnMenuItemOpenSelected(wxCommandEvent& event);
        void OnMenuItemSaveSelected(wxCommandEvent& event);
        void OnMenuItemSaveAsSelected(wxCommandEvent& event);
        void OnMenuItemCloseSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100WPainterFrame)
        static const long ID_MENUITEM_NEW;
        static const long ID_MENUITEM_OPEN;
        static const long ID_MENUITEM_SAVE;
        static const long ID_MENUITEM_SAVE_AS;
        static const long ID_MENUITEM_CLOSE;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100WPainterFrame)
        wxAuiManager* AuiManager1;
        wxMenuItem* MenuItemClose;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemOpen;
        wxMenuItem* MenuItemSave;
        wxMenuItem* MenuItemSaveAs;
        wxStatusBar* StatusBar1;
        //*)

        T100WPainterCanvas*                 m_canvas                    = T100NULL;
        T100WPainterElementsPanel*          m_elements_panel            = T100NULL;

    private:
        T100VOID            create();
        T100VOID            destroy();

        DECLARE_EVENT_TABLE()
};

#endif // T100WPAINTERMAIN_H
