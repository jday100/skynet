/***************************************************************
 * Name:      T100WxEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100WXEDITORMAIN_H
#define T100WXEDITORMAIN_H

//(*Headers(T100WxEditorFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100WxEditorFrame: public wxFrame
{
    public:

        T100WxEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100WxEditorFrame();

    private:

        //(*Handlers(T100WxEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100WxEditorFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100WxEditorFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100WXEDITORMAIN_H
