#ifndef T100IDECALLBACKPROJECT_H
#define T100IDECALLBACKPROJECT_H

#include "T100IDECallback.h"


class T100IDECallbackProject : public T100IDECallback
{
    public:
        T100IDECallbackProject();
        virtual ~T100IDECallbackProject();

        static T100BOOL             frame_menu_new(void* = T100NULL);

        static T100BOOL             frame_menu_open(void* = T100NULL);

        static T100BOOL             frame_menu_close(void* = T100NULL);

        static T100BOOL             frame_menu_quit(void* = T100NULL);

    protected:

    private:

};

#endif // T100IDECALLBACKPROJECT_H
