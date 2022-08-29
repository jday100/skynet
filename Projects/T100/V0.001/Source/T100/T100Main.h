/***************************************************************
 * Name:      T100App.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (China SuZhou)   jdayskynet@outlook.com
 * Created:   2020-08-16
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100MAIN_H
#define T100MAIN_H

//(*Headers(T100Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100Frame: public wxFrame
{
    public:

        T100Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100Frame();

    private:

        //(*Handlers(T100Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100MAIN_H
