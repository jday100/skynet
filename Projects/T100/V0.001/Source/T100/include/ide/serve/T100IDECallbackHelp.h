#ifndef T100IDECALLBACKHELP_H
#define T100IDECALLBACKHELP_H

#include "T100IDECallback.h"


class T100IDECallbackHelp : public T100IDECallback
{
    public:
        T100IDECallbackHelp();
        virtual ~T100IDECallbackHelp();

        static T100BOOL             frame_menu_about(void* = T100NULL);

    protected:

    private:
};

#endif // T100IDECALLBACKHELP_H
