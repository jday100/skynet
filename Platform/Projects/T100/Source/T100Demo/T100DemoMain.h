/***************************************************************
 * Name:      T100DemoMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100DEMOMAIN_H
#define T100DEMOMAIN_H

//(*Headers(T100DemoFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100DemoFrame: public wxFrame
{
    public:

        T100DemoFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100DemoFrame();

    private:

        //(*Handlers(T100DemoFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100DemoFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100DemoFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100DEMOMAIN_H
