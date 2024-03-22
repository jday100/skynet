/***************************************************************
 * Name:      T100PainterMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-14
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

#include "T100PaintCtrl.h"
#include "T100PaintElementsPanel.h"

class T100PainterFrame: public wxFrame
{
    public:

        T100PainterFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100PainterFrame();

    private:
        void            create();
        void            destroy();

        //(*Handlers(T100PainterFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItemNewSelected(wxCommandEvent& event);
        void OnMenuItemOpenSelected(wxCommandEvent& event);
        void OnMenuItemSaveSelected(wxCommandEvent& event);
        void OnMenuItemSaveAsSelected(wxCommandEvent& event);
        void OnMenuItemCloseSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100PainterFrame)
        static const long ID_MENUITEM_NEW;
        static const long ID_MENUITEM_OPEN;
        static const long ID_MENUITEM_SAVE;
        static const long ID_MENUITEM_SAVE_AS;
        static const long ID_MENUITEM_CLOSE;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100PainterFrame)
        wxAuiManager* AuiManager1;
        wxMenuItem* MenuItemClose;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemOpen;
        wxMenuItem* MenuItemSave;
        wxMenuItem* MenuItemSaveAs;
        wxStatusBar* StatusBar1;
        //*)

        T100PaintCtrl*                  m_paint         = nullptr;
        T100PaintElementsPanel*         m_elements_panel            = nullptr;

        DECLARE_EVENT_TABLE()
};

#endif // T100PAINTERMAIN_H
