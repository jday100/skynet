#ifndef T100IDEMENU_H
#define T100IDEMENU_H

#include <wx/menu.h>
#include "T100Common.h"


class T100IDEMenu
{
    public:
        T100IDEMenu(wxFrame*);
        virtual ~T100IDEMenu();

        T100BOOL            create();

    protected:
        T100VOID            destroy();

        static const long ID_MENUITEM_NEW;
        static const long ID_MENUITEM_OPEN;
        static const long ID_MENUITEM_CLOSE;
        static const long ID_MENUITEM_QUIT;

        T100VOID            create_main();

    private:
        void OnMenuNewSelected(wxCommandEvent& event);
        void OnMenuOpenSelected(wxCommandEvent& event);
        void OnMenuCloseSelected(wxCommandEvent& event);
        void OnMenuQuitSelected(wxCommandEvent& event);

    private:
        wxFrame*            m_frame             = T100NULL;
        wxMenuBar*          m_menu_bar          = T100NULL;

};

#endif // T100IDEMENU_H
