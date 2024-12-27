/***************************************************************
 * Name:      T100EditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100EDITORMAIN_H
#define T100EDITORMAIN_H

//(*Headers(T100EditorFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100EditorFrame: public wxFrame
{
    public:

        T100EditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100EditorFrame();

    private:

        //(*Handlers(T100EditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100EditorFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100EditorFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100EDITORMAIN_H
