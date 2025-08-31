/***************************************************************
 * Name:      T100ProjectMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-07-08
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100PROJECTMAIN_H
#define T100PROJECTMAIN_H

//(*Headers(T100ProjectFrame)
#include <wx/frame.h>
#include <wx/imaglist.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100Common.h"

class T100ProjectFrame: public wxFrame
{
    public:

        T100ProjectFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100ProjectFrame();

    private:
        T100VOID            OnWorkSpaceNew(wxCommandEvent&);
        T100VOID            OnWorkSpaceOpen(wxCommandEvent&);
        T100VOID            OnWorkSpaceClose(wxCommandEvent&);
        T100VOID            OnWorkSpaceSave(wxCommandEvent&);
        T100VOID            OnWorkSpaceSaveAs(wxCommandEvent&);
        T100VOID            OnProjectNew(wxCommandEvent&);
        T100VOID            OnProjectOpen(wxCommandEvent&);
        T100VOID            OnProjectClose(wxCommandEvent&);
        T100VOID            OnProjectSave(wxCommandEvent&);
        T100VOID            OnProjectSaveAs(wxCommandEvent&);
        T100VOID            OnFileNew(wxCommandEvent&);
        T100VOID            OnFileOpen(wxCommandEvent&);
        T100VOID            OnFileClose(wxCommandEvent&);
        T100VOID            OnFileSave(wxCommandEvent&);
        T100VOID            OnFileSaveAs(wxCommandEvent&);
        T100VOID            OnEditUndo(wxCommandEvent&);
        T100VOID            OnEditRedo(wxCommandEvent&);
        T100VOID            OnEditCut(wxCommandEvent&);
        T100VOID            OnEditCopy(wxCommandEvent&);
        T100VOID            OnEditPaste(wxCommandEvent&);
        T100VOID            OnSearchFind(wxCommandEvent&);
        T100VOID            OnSearchReplace(wxCommandEvent&);
        T100VOID            OnCompileClean(wxCommandEvent&);
        T100VOID            OnCompileBuild(wxCommandEvent&);
        T100VOID            OnCompileRebuild(wxCommandEvent&);
        T100VOID            OnSetupEditor(wxCommandEvent&);
        T100VOID            OnSetupCompiler(wxCommandEvent&);
        T100VOID            OnHelpAbout(wxCommandEvent&);

    private:
        T100VOID            init();

        //(*Handlers(T100ProjectFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnResize(wxSizeEvent& event);
        //*)

        //(*Identifiers(T100ProjectFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100ProjectFrame)
        wxImageList* ImageList1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTMAIN_H
