/***************************************************************
 * Name:      T100PluginMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-18
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100PLUGINMAIN_H
#define T100PLUGINMAIN_H

//(*Headers(T100PluginFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100PluginFrame: public wxFrame
{
    public:

        T100PluginFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100PluginFrame();

    private:

        //(*Handlers(T100PluginFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100PluginFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100PluginFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100PLUGINMAIN_H
