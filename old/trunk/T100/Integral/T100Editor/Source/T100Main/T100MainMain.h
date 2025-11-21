/***************************************************************
 * Name:      T100MainMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-19
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100MAINMAIN_H
#define T100MAINMAIN_H

//(*Headers(T100MainFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "plugin\T100PluginManager.h"

class T100MainFrame: public wxFrame
{
    public:

        T100MainFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100MainFrame();

    private:

        //(*Handlers(T100MainFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100MainFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100MainFrame)
        wxStatusBar* StatusBar1;
        //*)

        T100PluginManager           m_manager;

        DECLARE_EVENT_TABLE()
};

#endif // T100MAINMAIN_H
