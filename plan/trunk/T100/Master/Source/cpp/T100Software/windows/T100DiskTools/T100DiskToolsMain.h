/***************************************************************
 * Name:      T100DiskToolsMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-07-28
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100DISKTOOLSMAIN_H
#define T100DISKTOOLSMAIN_H

//(*Headers(T100DiskToolsFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100DiskToolsFrame: public wxFrame
{
    public:

        T100DiskToolsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100DiskToolsFrame();

    private:

        //(*Handlers(T100DiskToolsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100DiskToolsFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100DiskToolsFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100DISKTOOLSMAIN_H
