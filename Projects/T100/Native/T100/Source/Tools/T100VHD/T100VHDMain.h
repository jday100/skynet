/***************************************************************
 * Name:      T100VHDMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-02-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100VHDMAIN_H
#define T100VHDMAIN_H

//(*Headers(T100VHDFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100VHDFrame: public wxFrame
{
    public:

        T100VHDFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100VHDFrame();

    private:

        //(*Handlers(T100VHDFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItemNewSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100VHDFrame)
        static const long ID_MENUITEM_NEW;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100VHDFrame)
        wxMenuItem* MenuItemNew;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100VHDMAIN_H
