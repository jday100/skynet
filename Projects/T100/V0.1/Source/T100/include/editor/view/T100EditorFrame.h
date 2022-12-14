#ifndef T100EDITORFRAME_H
#define T100EDITORFRAME_H

#include <wx/frame.h>
#include "T100Common.h"

namespace T100Editor{

class T100EditorFrame : public wxFrame
{
    public:
        T100EditorFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100EditorFrame();


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

        static const long ID_MENUITEM_SEARCH;
        static const long ID_MENUITEM_REPLACE;

        static const long ID_MENUITEM_ABOUT;

    protected:
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

        void OnMenuSearchSelected(wxCommandEvent& event);
        void OnMenuReplaceSelected(wxCommandEvent& event);
        void OnMenuAboutSelected(wxCommandEvent& event);

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100BOOL                create_menu();

    private:

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100EDITORFRAME_H
