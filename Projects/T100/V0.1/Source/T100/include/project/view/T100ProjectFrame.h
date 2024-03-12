#ifndef T100PROJECTFRAME_H
#define T100PROJECTFRAME_H

#include <wx/frame.h>
#include <wx/statusbr.h>
#include "T100Common.h"


namespace T100PROJECT{

class T100ProjectFrame : public wxFrame
{
    friend class T100ProjectView;
    public:
        T100ProjectFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100ProjectFrame();

    public:
        static const long ID_MENUITEM_NEW;
        static const long ID_MENUITEM_OPEN;
        static const long ID_MENUITEM_CLOSE;
        static const long ID_MENUITEM_SAVE;
        static const long ID_MENUITEM_SAVE_AS;
        static const long ID_MENUITEM_QUIT;

        static const long ID_MENUITEM_UNDO;
        static const long ID_MENUITEM_REDO;
        static const long ID_MENUITEM_CUT;
        static const long ID_MENUITEM_COPY;
        static const long ID_MENUITEM_PASTE;

        static const long ID_MENUITEM_PROJECTS;

        static const long ID_MENUITEM_ABOUT;

    protected:
        static const long ID_STATUSBAR;

        void OnMenuNewSelected(wxCommandEvent& event);
        void OnMenuOpenSelected(wxCommandEvent& event);
        void OnMenuCloseSelected(wxCommandEvent& event);
        void OnMenuSaveSelected(wxCommandEvent& event);
        void OnMenuSaveAsSelected(wxCommandEvent& event);
        void OnMenuQuitSelected(wxCommandEvent& event);

        void OnMenuUndoSelected(wxCommandEvent& event);
        void OnMenuRedoSelected(wxCommandEvent& event);
        void OnMenuCutSelected(wxCommandEvent& event);
        void OnMenuCopySelected(wxCommandEvent& event);
        void OnMenuPasteSelected(wxCommandEvent& event);

        void OnMenuProjectsSelected(wxCommandEvent& event);

        void OnMenuAboutSelected(wxCommandEvent& event);

        void OnClose(wxCloseEvent& event);

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100BOOL                create_menu();
        T100BOOL                update_menu();
        T100BOOL                reset_menu();

    private:
        wxStatusBar*            StatusBar;

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100PROJECTFRAME_H
