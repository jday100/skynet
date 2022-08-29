#ifndef T100IDEVIEWPROJECT_H
#define T100IDEVIEWPROJECT_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"
#include "T100IDEProjectData.h"


class T100IDEViewProject : public T100IDEViewBase
{
    public:
        T100IDEViewProject(T100IDEView*);
        virtual ~T100IDEViewProject();

        T100BOOL                create_menu();

        T100BOOL                show(T100IDE_PROJECT_VECTOR&);

        T100BOOL                create();
        T100BOOL                open();
        T100BOOL                close();

        T100BOOL                opened();

        T100BOOL                quit();

    protected:
        static const long ID_MENUITEM_PROJECT_NEW;
        static const long ID_MENUITEM_PROJECT_OPEN;
        static const long ID_MENUITEM_PROJECT_CLOSE;
        static const long ID_MENUITEM_PROJECT_QUIT;

    private:
        void OnMenuProjectNewSelected(wxCommandEvent& event);
        void OnMenuProjectOpenSelected(wxCommandEvent& event);
        void OnMenuProjectCloseSelected(wxCommandEvent& event);
        void OnMenuProjectQuitSelected(wxCommandEvent& event);

    private:

};

#endif // T100IDEVIEWPROJECT_H
