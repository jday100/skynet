#ifndef T100IDECALLBACKVIEW_H
#define T100IDECALLBACKVIEW_H

#include "T100IDECallback.h"


class T100IDECallbackView : public T100IDECallback
{
    public:
        T100IDECallbackView();
        virtual ~T100IDECallbackView();

        static T100BOOL             frame_menu_project(void* = T100NULL);

    protected:

    private:
};

#endif // T100IDECALLBACKVIEW_H
