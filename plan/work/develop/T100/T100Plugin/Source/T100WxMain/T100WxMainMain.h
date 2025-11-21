/***************************************************************
 * Name:      T100WxMainMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100WXMAINMAIN_H
#define T100WXMAINMAIN_H

//(*Headers(T100WxMainFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100PluginManager.h"

class T100WxMainFrame: public wxFrame
{
    public:

        T100WxMainFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100WxMainFrame();

    private:
        T100PluginManager           m_manager;

        //(*Handlers(T100WxMainFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100WxMainFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100WxMainFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100WXMAINMAIN_H
