/***************************************************************
 * Name:      T100DiagramMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-10-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100DIAGRAMMAIN_H
#define T100DIAGRAMMAIN_H

//(*Headers(T100DiagramFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include <wx/aui/aui.h>
#include "T100Common.h"

class T100DiagramFrame: public wxFrame
{
    public:

        T100DiagramFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100DiagramFrame();

    private:
        T100VOID            OnFileCreate(wxCommandEvent&);
        T100VOID            OnFileOpen(wxCommandEvent&);
        T100VOID            OnFileClose(wxCommandEvent&);
        T100VOID            OnFileSave(wxCommandEvent&);
        T100VOID            OnFileSaveAs(wxCommandEvent&);
        T100VOID            OnFileQuit(wxCommandEvent&);

        T100VOID            OnEditUndo(wxCommandEvent&);
        T100VOID            OnEditRedo(wxCommandEvent&);
        T100VOID            OnEditCut(wxCommandEvent&);
        T100VOID            OnEditCopy(wxCommandEvent&);
        T100VOID            OnEditPaste(wxCommandEvent&);

        T100VOID            OnViewManager(wxCommandEvent&);
        T100VOID            OnViewProperty(wxCommandEvent&);

        T100VOID            OnSearchFind(wxCommandEvent&);

        T100VOID            OnSourceImport(wxCommandEvent&);

        T100VOID            OnSetupConfig(wxCommandEvent&);

        T100VOID            OnHelpAbout(wxCommandEvent&);

        T100VOID            OnAuiPaneClose(wxAuiManagerEvent&);

    private:

        //(*Handlers(T100DiagramFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100DiagramFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100DiagramFrame)
        wxStatusBar* StatusBar1;
        //*)

        T100VOID            init();
        T100VOID            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100DIAGRAMMAIN_H
