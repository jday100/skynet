#ifndef T100IDEVIEWSEARCH_H
#define T100IDEVIEWSEARCH_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewSearch : public T100IDEViewBase
{
    public:
        T100IDEViewSearch(T100IDEView*);
        virtual ~T100IDEViewSearch();

        T100BOOL            create_menu();

    protected:
        static const long ID_MENUITEM_SEARCH_FIND;
        static const long ID_MENUITEM_SEARCH_REPLACE;

    private:
        void OnMenuSearchFindSelected(wxCommandEvent& event);
        void OnMenuSearchReplaceSelected(wxCommandEvent& event);

};

#endif // T100IDEVIEWSEARCH_H
