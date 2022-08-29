/***************************************************************
 * Name:      T100IDEMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100IDEMAIN_H
#define T100IDEMAIN_H

//(*Headers(T100IDEFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100IDEFrame: public wxFrame
{
    public:

        T100IDEFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100IDEFrame();

    private:

        //(*Handlers(T100IDEFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100IDEFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100IDEFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100IDEMAIN_H
