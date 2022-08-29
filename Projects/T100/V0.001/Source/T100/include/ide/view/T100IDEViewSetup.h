#ifndef T100IDEVIEWSETUP_H
#define T100IDEVIEWSETUP_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewSetup : public T100IDEViewBase
{
    public:
        T100IDEViewSetup(T100IDEView*);
        virtual ~T100IDEViewSetup();

        T100BOOL            create_menu();

    protected:
        static const long ID_MENUITEM_SETUP_CONFIG;
        static const long ID_MENUITEM_SETUP_EDITOR;
        static const long ID_MENUITEM_SETUP_COMPILER;
        static const long ID_MENUITEM_SETUP_DEBUGGER;

    private:
        void OnMenuSetupConfigSelected(wxCommandEvent& event);
        void OnMenuSetupEditorSelected(wxCommandEvent& event);
        void OnMenuSetupCompilerSelected(wxCommandEvent& event);
        void OnMenuSetupDebuggerSelected(wxCommandEvent& event);
};

#endif // T100IDEVIEWSETUP_H
