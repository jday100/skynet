/***************************************************************
 * Name:      T100ProjectMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100PROJECTMAIN_H
#define T100PROJECTMAIN_H

//(*Headers(T100ProjectFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100ProjectFrame: public wxFrame
{
    public:

        T100ProjectFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100ProjectFrame();

    private:

        //(*Handlers(T100ProjectFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100ProjectFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100ProjectFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTMAIN_H
