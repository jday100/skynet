/***************************************************************
 * Name:      T100LibraryMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100LIBRARYMAIN_H
#define T100LIBRARYMAIN_H

//(*Headers(T100LibraryFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100LibraryFrame: public wxFrame
{
    public:

        T100LibraryFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100LibraryFrame();

    private:

        //(*Handlers(T100LibraryFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100LibraryFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100LibraryFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100LIBRARYMAIN_H
