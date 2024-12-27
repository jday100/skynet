/***************************************************************
 * Name:      T100SuiteMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100SUITEMAIN_H
#define T100SUITEMAIN_H

//(*Headers(T100SuiteFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100SuiteFrame: public wxFrame
{
    public:

        T100SuiteFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100SuiteFrame();

    private:

        //(*Handlers(T100SuiteFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100SuiteFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100SuiteFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100SUITEMAIN_H
