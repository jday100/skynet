/***************************************************************
 * Name:      T100VMMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-08-10
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100VMMAIN_H
#define T100VMMAIN_H

//(*Headers(T100VMFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100VMFrame: public wxFrame
{
    public:

        T100VMFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100VMFrame();

    private:

        //(*Handlers(T100VMFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuStartSelected(wxCommandEvent& event);
        void OnMenuStopSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100VMFrame)
        static const long ID_MENU_START;
        static const long ID_MENUSTOP;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100VMFrame)
        wxMenuItem* MenuStart;
        wxMenuItem* MenuStop;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100VMMAIN_H
