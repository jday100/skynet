/***************************************************************
 * Name:      T100VPCMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-09-14
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100VPCMAIN_H
#define T100VPCMAIN_H

//(*Headers(T100VPCFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100VPCFrame: public wxFrame
{
    public:

        T100VPCFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100VPCFrame();

    private:

        //(*Handlers(T100VPCFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItemStartSelected(wxCommandEvent& event);
        void OnMenuItemStopSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100VPCFrame)
        static const long ID_MENUITEM_START;
        static const long ID_MENUITEM_STOP;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100VPCFrame)
        wxMenuItem* MenuItemStart;
        wxMenuItem* MenuItemStop;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100VPCMAIN_H
