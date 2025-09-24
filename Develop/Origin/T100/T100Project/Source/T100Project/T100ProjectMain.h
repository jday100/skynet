/***************************************************************
 * Name:      T100ProjectMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-09-03
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100PROJECTMAIN_H
#define T100PROJECTMAIN_H

//(*Headers(T100ProjectFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include <wx/aui/aui.h>
#include "T100Common.h"

class T100ProjectFrame: public wxFrame
{
    public:

        T100ProjectFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100ProjectFrame();

        T100VOID            OnAuiPaneClose(wxAuiManagerEvent&);

    private:
        T100VOID            OnWorkSpaceCreate(wxCommandEvent&);
        T100VOID            OnWorkSpaceOpen(wxCommandEvent&);
        T100VOID            OnWorkSpaceClose(wxCommandEvent&);
        T100VOID            OnWorkSpaceSave(wxCommandEvent&);
        T100VOID            OnWorkSpaceQuit(wxCommandEvent&);

        T100VOID            OnProjectCreate(wxCommandEvent&);
        T100VOID            OnProjectRemove(wxCommandEvent&);
        T100VOID            OnProjectOpen(wxCommandEvent&);
        T100VOID            OnProjectClose(wxCommandEvent&);
        T100VOID            OnProjectSave(wxCommandEvent&);
        T100VOID            OnProjectSaveAs(wxCommandEvent&);

        T100VOID            OnFileCreate(wxCommandEvent&);
        T100VOID            OnFileRemove(wxCommandEvent&);
        T100VOID            OnFileOpen(wxCommandEvent&);
        T100VOID            OnFileClose(wxCommandEvent&);
        T100VOID            OnFileSave(wxCommandEvent&);
        T100VOID            OnFileSaveAs(wxCommandEvent&);

        T100VOID            OnEditUndo(wxCommandEvent&);
        T100VOID            OnEditRedo(wxCommandEvent&);
        T100VOID            OnEditCut(wxCommandEvent&);
        T100VOID            OnEditCopy(wxCommandEvent&);
        T100VOID            OnEditPaste(wxCommandEvent&);

        T100VOID            OnViewWorkSpaceTree(wxCommandEvent&);
        T100VOID            OnViewSearchResult(wxCommandEvent&);
        T100VOID            OnViewCompileOutput(wxCommandEvent&);

        T100VOID            OnSearchFind(wxCommandEvent&);
        T100VOID            OnSearchReplace(wxCommandEvent&);

        T100VOID            OnCompileRun(wxCommandEvent&);
        T100VOID            OnCompileBuildAndRun(wxCommandEvent&);
        T100VOID            OnCompileBuild(wxCommandEvent&);
        T100VOID            OnCompileClean(wxCommandEvent&);
        T100VOID            OnCompileRebuild(wxCommandEvent&);

        T100VOID            OnDebugStart(wxCommandEvent&);
        T100VOID            OnDebugStop(wxCommandEvent&);

        T100VOID            OnSetupEditor(wxCommandEvent&);
        T100VOID            OnSetupCompiler(wxCommandEvent&);

        T100VOID            OnHelpAbout(wxCommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();

        //(*Handlers(T100ProjectFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100ProjectFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100ProjectFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTMAIN_H
