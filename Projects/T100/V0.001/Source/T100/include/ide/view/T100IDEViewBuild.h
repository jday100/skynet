#ifndef T100IDEVIEWBUILD_H
#define T100IDEVIEWBUILD_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewBuild : public T100IDEViewBase
{
    public:
        T100IDEViewBuild(T100IDEView*);
        virtual ~T100IDEViewBuild();

        T100BOOL                create_menu();

    protected:
        static const long ID_MENUITEM_BUILD_BUILD;
        static const long ID_MENUITEM_BUILD_RUN;
        static const long ID_MENUITEM_BUILD_CLEAN;
        static const long ID_MENUITEM_BUILD_STOP;

    private:
        void OnMenuBuildBuildSelected(wxCommandEvent& event);
        void OnMenuBuildRunSelected(wxCommandEvent& event);
        void OnMenuBuildCleanSelected(wxCommandEvent& event);
        void OnMenuBuildStopSelected(wxCommandEvent& event);

};

#endif // T100IDEVIEWBUILD_H
