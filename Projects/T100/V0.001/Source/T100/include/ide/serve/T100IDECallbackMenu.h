#ifndef T100IDECALLBACKMENU_H
#define T100IDECALLBACKMENU_H

#include "T100IDECallback.h"


class T100IDECallbackMenu : public T100IDECallback
{
    public:
        T100IDECallbackMenu();
        virtual ~T100IDECallbackMenu();

        static T100BOOL             frame_menu_new(void* = T100NULL);

        static T100BOOL             frame_menu_open(void* = T100NULL);

        static T100BOOL             frame_menu_close(void* = T100NULL);

        static T100BOOL             frame_menu_quit(void* = T100NULL);

    protected:

    private:

};

#endif // T100IDECALLBACKMENU_H
