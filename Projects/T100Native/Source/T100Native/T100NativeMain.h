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

#include "T100Common.h"
#include "T100WxRender.h"

class T100NativeFrame: public wxFrame
{
    public:

        T100NativeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100NativeFrame();

        T100VOID            SetRender(T100WxRender*);
        T100WxRender&       GetRender();

    private:

        //(*Handlers(T100NativeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnKeyDown(wxKeyEvent& event);
        void OnChar(wxKeyEvent& event);
        //*)

        //(*Identifiers(T100NativeFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100NativeFrame)
        wxStatusBar* StatusBar1;
        //*)

    private:
        T100WxRender*       m_render            = T100NULL;

        T100VOID            TurnOn();
        T100VOID            TurnOff();

        DECLARE_EVENT_TABLE()
};

#endif // T100NATIVEMAIN_H
