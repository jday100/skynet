/***************************************************************
 * Name:      T100NeuroidMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-18
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100NEUROIDMAIN_H
#define T100NEUROIDMAIN_H

//(*Headers(T100NeuroidFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100NeuroidFrame: public wxFrame
{
    public:

        T100NeuroidFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100NeuroidFrame();

    private:

        //(*Handlers(T100NeuroidFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100NeuroidFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100NeuroidFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100NEUROIDMAIN_H
