#ifndef T100IDEVIEWVIEW_H
#define T100IDEVIEWVIEW_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewView : public T100IDEViewBase
{
    public:
        T100IDEViewView(T100IDEView*);
        virtual ~T100IDEViewView();

        T100BOOL            create_menu();

    protected:
        static const long ID_MENUITEM_VIEW_PROJECT;

    private:
        void OnMenuViewProjectSelected(wxCommandEvent& event);

};

#endif // T100IDEVIEWVIEW_H
