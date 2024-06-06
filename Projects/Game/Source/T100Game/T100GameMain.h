/***************************************************************
 * Name:      T100GameMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-05
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100GAMEMAIN_H
#define T100GAMEMAIN_H

//(*Headers(T100GameFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100GameFrame: public wxFrame
{
    public:

        T100GameFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100GameFrame();

    private:

        //(*Handlers(T100GameFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100GameFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100GameFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100GAMEMAIN_H
