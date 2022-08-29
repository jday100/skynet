#ifndef T100IDEVIEWHELP_H
#define T100IDEVIEWHELP_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewHelp : public T100IDEViewBase
{
    public:
        T100IDEViewHelp(T100IDEView*);
        virtual ~T100IDEViewHelp();

        T100BOOL            create_menu();

    protected:
        static const long ID_MENUITEM_HELP_ABOUT;

    private:
        void OnMenuHelpAboutSelected(wxCommandEvent& event);

};

#endif // T100IDEVIEWHELP_H
