/***************************************************************
 * Name:      T1003DEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-01-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T1003DEDITORMAIN_H
#define T1003DEDITORMAIN_H

//(*Headers(T1003DEditorFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T1003DEditorFrame: public wxFrame
{
    public:

        T1003DEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T1003DEditorFrame();

    private:

        //(*Handlers(T1003DEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T1003DEditorFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T1003DEditorFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORMAIN_H
