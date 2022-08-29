#ifndef T100IDECALLBACKDEBUG_H
#define T100IDECALLBACKDEBUG_H

#include "T100IDECallback.h"


class T100IDECallbackDebug : public T100IDECallback
{
    public:
        T100IDECallbackDebug();
        virtual ~T100IDECallbackDebug();

        static T100BOOL             frame_menu_step(void* = T100NULL);

        static T100BOOL             frame_menu_pause(void* = T100NULL);

        static T100BOOL             frame_menu_run(void* = T100NULL);

        static T100BOOL             frame_menu_stop(void* = T100NULL);

    protected:

    private:

};

#endif // T100IDECALLBACKDEBUG_H
