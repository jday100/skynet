/***************************************************************
 * Name:      T1003DEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-01-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T1003DEDITORMAIN_H
#define T1003DEDITORMAIN_H

//(*Headers(T1003DEditorFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100Common.h"
#include "T1003DEditor.h"
#include "T1003DEditorView.h"

class T1003DEditorFrame: public wxFrame
{
    public:

        T1003DEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T1003DEditorFrame();

    private:
        T1003DEditor*           m_editor            = T100NULL;
        T1003DEditorView*       m_view              = T100NULL;

        //(*Handlers(T1003DEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnEraseBackground(wxEraseEvent& event);
        void OnKeyDown(wxKeyEvent& event);
        void OnKeyUp(wxKeyEvent& event);
        void OnMouseWheel(wxMouseEvent& event);
        void OnResize(wxSizeEvent& event);
        void OnMouseMove(wxMouseEvent& event);
        void OnLeftDown(wxMouseEvent& event);
        void OnLeftUp(wxMouseEvent& event);
        void OnRightDown(wxMouseEvent& event);
        void OnRightUp(wxMouseEvent& event);
        //*)

        //(*Identifiers(T1003DEditorFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T1003DEditorFrame)
        wxStatusBar* StatusBar1;
        //*)

        T100VOID                create();
        T100VOID                destroy();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORMAIN_H
