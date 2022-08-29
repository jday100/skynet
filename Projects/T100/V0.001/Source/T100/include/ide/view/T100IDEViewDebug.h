#ifndef T100IDEVIEWDEBUG_H
#define T100IDEVIEWDEBUG_H

#include <wx/menu.h>
#include "T100IDEViewBase.h"


class T100IDEViewDebug : public T100IDEViewBase
{
    public:
        T100IDEViewDebug(T100IDEView*);
        virtual ~T100IDEViewDebug();

        T100BOOL                create_menu();

        T100BOOL                step();
        T100BOOL                run();
        T100BOOL                pause();

    protected:
        static const long ID_MENUITEM_DEBUG_STEP;
        static const long ID_MENUITEM_DEBUG_RUN;
        static const long ID_MENUITEM_DEBUG_PAUSE;
        static const long ID_MENUITEM_DEBUG_STOP;

    private:
        void OnMenuDebugStepSelected(wxCommandEvent& event);
        void OnMenuDebugRunSelected(wxCommandEvent& event);
        void OnMenuDebugPauseSelected(wxCommandEvent& event);
        void OnMenuDebugStopSelected(wxCommandEvent& event);

    private:

};

#endif // T100IDEVIEWDEBUG_H
