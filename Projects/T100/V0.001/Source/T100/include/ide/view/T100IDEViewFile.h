#ifndef T100IDEVIEWFILE_H
#define T100IDEVIEWFILE_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewFile : public T100IDEViewBase
{
    public:
        T100IDEViewFile(T100IDEView*);
        virtual ~T100IDEViewFile();

        T100BOOL            create_menu();

        T100BOOL            create_menu_old();

        T100BOOL            create();
        T100BOOL            remove();

        T100BOOL            open(T100STDSTRING&);
        T100BOOL            close();

    protected:
        static const long ID_MENUITEM_FILE_NEW;
        static const long ID_MENUITEM_FILE_DELETE;
        static const long ID_MENUITEM_FILE_OPEN;
        static const long ID_MENUITEM_FILE_CLOSE;
        static const long ID_MENUITEM_FILE_SAVE;
        static const long ID_MENUITEM_FILE_SAVE_AS;

    private:
        void OnMenuFileNewSelected(wxCommandEvent& event);
        void OnMenuFileDeleteSelected(wxCommandEvent& event);
        void OnMenuFileOpenSelected(wxCommandEvent& event);
        void OnMenuFileCloseSelected(wxCommandEvent& event);
        void OnMenuFileSaveSelected(wxCommandEvent& event);
        void OnMenuFileSaveAsSelected(wxCommandEvent& event);

};

#endif // T100IDEVIEWFILE_H
