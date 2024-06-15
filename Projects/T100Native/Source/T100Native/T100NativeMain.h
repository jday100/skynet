/***************************************************************
 * Name:      T100NativeMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100NATIVEMAIN_H
#define T100NATIVEMAIN_H

//(*Headers(T100NativeFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100NativeFrame: public wxFrame
{
    public:

        T100NativeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100NativeFrame();

    private:

        //(*Handlers(T100NativeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100NativeFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100NativeFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100NATIVEMAIN_H
