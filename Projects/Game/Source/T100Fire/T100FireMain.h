/***************************************************************
 * Name:      T100FireMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-05
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100FIREMAIN_H
#define T100FIREMAIN_H

//(*Headers(T100FireFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100Common.h"
#include "T100FireGame.h"

class T100FireFrame: public wxFrame
{
    public:

        T100FireFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100FireFrame();

    private:
        T100FireGame*                   m_game          = T100NULL;

        //(*Handlers(T100FireFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnKeyDown(wxKeyEvent& event);
        void OnKeyUp(wxKeyEvent& event);
        void OnResize(wxSizeEvent& event);
        //*)

        //(*Identifiers(T100FireFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100FireFrame)
        wxStatusBar* StatusBar1;
        //*)

        T100VOID                        create();
        T100VOID                        destroy();

        DECLARE_EVENT_TABLE()
};

#endif // T100FIREMAIN_H
