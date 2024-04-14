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
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100PainterFrame: public wxFrame
{
    public:

        T100PainterFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100PainterFrame();

    private:

        //(*Handlers(T100PainterFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100PainterFrame)
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long idMenuQuit;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM13;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100PainterFrame)
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenu* Menu5;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItem12;
        wxMenuItem* MenuItem13;
        wxMenuItem* MenuItem14;
        wxMenuItem* MenuItem15;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxMenuItem* MenuItem9;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100PAINTERMAIN_H
