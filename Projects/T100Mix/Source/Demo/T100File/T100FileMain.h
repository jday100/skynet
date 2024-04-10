/***************************************************************
 * Name:      T100FileMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-04-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100FILEMAIN_H
#define T100FILEMAIN_H

//(*Headers(T100FileFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100FileFrame: public wxFrame
{
    public:

        T100FileFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100FileFrame();

    private:

        //(*Handlers(T100FileFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100FileFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100FileFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100FILEMAIN_H
