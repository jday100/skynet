/***************************************************************
 * Name:      T100ViewMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-14
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100VIEWMAIN_H
#define T100VIEWMAIN_H

//(*Headers(T100ViewFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100ViewFrame: public wxFrame
{
    public:

        T100ViewFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100ViewFrame();

    private:

        //(*Handlers(T100ViewFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100ViewFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100ViewFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100VIEWMAIN_H
