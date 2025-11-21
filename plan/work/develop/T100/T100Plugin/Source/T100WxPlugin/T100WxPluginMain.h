/***************************************************************
 * Name:      T100WxPluginMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100WXPLUGINMAIN_H
#define T100WXPLUGINMAIN_H

//(*Headers(T100WxPluginFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100WxPluginFrame: public wxFrame
{
    public:

        T100WxPluginFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100WxPluginFrame();

    private:

        //(*Handlers(T100WxPluginFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100WxPluginFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100WxPluginFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100WXPLUGINMAIN_H
