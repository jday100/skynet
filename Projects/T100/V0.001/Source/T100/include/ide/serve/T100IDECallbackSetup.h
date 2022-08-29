#ifndef T100IDECALLBACKSETUP_H
#define T100IDECALLBACKSETUP_H

#include "T100IDECallback.h"


class T100IDECallbackSetup : public T100IDECallback
{
    public:
        T100IDECallbackSetup();
        virtual ~T100IDECallbackSetup();

        static T100BOOL             frame_menu_config(void* = T100NULL);

        static T100BOOL             frame_menu_editor(void* = T100NULL);

        static T100BOOL             frame_menu_compiler(void* = T100NULL);

        static T100BOOL             frame_menu_debugger(void* = T100NULL);

    protected:

    private:
};

#endif // T100IDECALLBACKSETUP_H
