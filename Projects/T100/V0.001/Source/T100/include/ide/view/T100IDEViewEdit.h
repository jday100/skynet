#ifndef T100IDEVIEWEDIT_H
#define T100IDEVIEWEDIT_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewEdit : public T100IDEViewBase
{
    public:
        T100IDEViewEdit(T100IDEView*);
        virtual ~T100IDEViewEdit();

        T100BOOL            create_menu();

    protected:
        static const long ID_MENUITEM_EDIT_UNDO;
        static const long ID_MENUITEM_EDIT_REDO;
        static const long ID_MENUITEM_EDIT_CUT;
        static const long ID_MENUITEM_EDIT_COPY;
        static const long ID_MENUITEM_EDIT_PASTE;

    private:
        void OnMenuEditUndoSelected(wxCommandEvent& event);
        void OnMenuEditRedoSelected(wxCommandEvent& event);
        void OnMenuEditCutSelected(wxCommandEvent& event);
        void OnMenuEditCopySelected(wxCommandEvent& event);
        void OnMenuEditPasteSelected(wxCommandEvent& event);

};

#endif // T100IDEVIEWEDIT_H
