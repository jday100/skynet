/***************************************************************
 * Name:      T100ThreadMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100THREADMAIN_H
#define T100THREADMAIN_H

//(*Headers(T100ThreadFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100ThreadFrame: public wxFrame
{
    public:

        T100ThreadFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100ThreadFrame();

        static const long ID_THREAD_OPEN;

    private:
        void OnThreadOpen(wxThreadEvent& event);

    private:

        //(*Handlers(T100ThreadFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItemOpenSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100ThreadFrame)
        static const long ID_MENUITEM_OPEN;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100ThreadFrame)
        wxMenuItem* MenuItemOpen;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100THREADMAIN_H
