/***************************************************************
 * Name:      T100DiskerMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-12
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100DISKERMAIN_H
#define T100DISKERMAIN_H

//(*Headers(T100DiskerFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100DiskerFrame: public wxFrame
{
    public:

        T100DiskerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100DiskerFrame();

    private:

        //(*Handlers(T100DiskerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100DiskerFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100DiskerFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100DISKERMAIN_H
