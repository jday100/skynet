/***************************************************************
 * Name:      T100PSVMMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-10
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100PSVMMAIN_H
#define T100PSVMMAIN_H

//(*Headers(T100PSVMFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include "T100Common.h"

class T100PSVMFrame: public wxFrame
{
    public:

        T100PSVMFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100PSVMFrame();

        T100VOID            Log(T100STRING&);

    private:
        T100VOID    OnMenuFileCreate(wxCommandEvent&);
        T100VOID    OnMenuFileOpen(wxCommandEvent&);
        T100VOID    OnMenuFileClose(wxCommandEvent&);
        T100VOID    OnMenuFileSave(wxCommandEvent&);
        T100VOID    OnMenuFileSaveAs(wxCommandEvent&);
        T100VOID    OnMenuFileQuit(wxCommandEvent&);

        T100VOID    OnMenuVMStart(wxCommandEvent&);
        T100VOID    OnMenuVMStop(wxCommandEvent&);

        T100VOID    OnMenuDebugStart(wxCommandEvent&);
        T100VOID    OnMenuDebugStop(wxCommandEvent&);

        T100VOID    OnMenuHelpAbout(wxCommandEvent&);

        //(*Handlers(T100PSVMFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100PSVMFrame)
        static const long ID_TEXTCTRL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100PSVMFrame)
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl;
        //*)

        T100VOID            init();
        T100VOID            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100PSVMMAIN_H
