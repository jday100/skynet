/***************************************************************
 * Name:      T100VM64Main.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-02-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100VM64MAIN_H
#define T100VM64MAIN_H

//(*Headers(T100VM64Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100VM64Frame: public wxFrame
{
    public:

        T100VM64Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100VM64Frame();

    private:

        //(*Handlers(T100VM64Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100VM64Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100VM64Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100VM64MAIN_H
