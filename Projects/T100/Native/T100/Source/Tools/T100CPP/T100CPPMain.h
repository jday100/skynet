/***************************************************************
 * Name:      T100CPPMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-09-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100CPPMAIN_H
#define T100CPPMAIN_H

//(*Headers(T100CPPFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100CPPFrame: public wxFrame
{
    public:

        T100CPPFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100CPPFrame();

    private:

        //(*Handlers(T100CPPFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100CPPFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100CPPFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100CPPMAIN_H
