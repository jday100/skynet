/***************************************************************
 * Name:      T100WxWidgetsMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-08-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100WXWIDGETSMAIN_H
#define T100WXWIDGETSMAIN_H

//(*Headers(T100WxWidgetsFrame)
#include "T100DiskCtrl.h"
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/statusbr.h>
//*)

class T100WxWidgetsFrame: public wxFrame
{
    public:

        T100WxWidgetsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100WxWidgetsFrame();

    private:

        //(*Handlers(T100WxWidgetsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100WxWidgetsFrame)
        static const long ID_STATICBOX1;
        static const long ID_CUSTOM1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100WxWidgetsFrame)
        T100DiskCtrl* Custom1;
        wxPanel* Panel1;
        wxStaticBox* StaticBox1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100WXWIDGETSMAIN_H
