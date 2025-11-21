/***************************************************************
 * Name:      T100ShellInstallerMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-07-31
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100SHELLINSTALLERMAIN_H
#define T100SHELLINSTALLERMAIN_H

//(*Headers(T100ShellInstallerDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class T100ShellInstallerDialog: public wxDialog
{
    public:

        T100ShellInstallerDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100ShellInstallerDialog();

    private:

        //(*Handlers(T100ShellInstallerDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100ShellInstallerDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(T100ShellInstallerDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100SHELLINSTALLERMAIN_H
