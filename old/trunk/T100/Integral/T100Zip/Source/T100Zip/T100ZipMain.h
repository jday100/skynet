/***************************************************************
 * Name:      T100ZipMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-09-29
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100ZIPMAIN_H
#define T100ZIPMAIN_H

//(*Headers(T100ZipDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100ZipDialog: public wxDialog
{
    public:

        T100ZipDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100ZipDialog();

    private:

        //(*Handlers(T100ZipDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100ZipDialog)
        static const long ID_STATICTEXT1;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_DIRPICKERCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_STATICTEXT3;
        static const long ID_FILEPICKERCTRL2;
        static const long ID_STATICTEXT4;
        static const long ID_FILEPICKERCTRL3;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_PANEL2;
        static const long ID_NOTEBOOK1;
        //*)

        //(*Declarations(T100ZipDialog)
        wxBoxSizer* BoxSizer1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxDirPickerCtrl* DirPickerCtrl1;
        wxFilePickerCtrl* FilePickerCtrl1;
        wxFilePickerCtrl* FilePickerCtrl2;
        wxFilePickerCtrl* FilePickerCtrl3;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100ZIPMAIN_H
