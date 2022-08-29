#ifndef T100IDECALLBACKBUILD_H
#define T100IDECALLBACKBUILD_H

#include "T100IDECallback.h"


class T100IDECallbackBuild : public T100IDECallback
{
    public:
        T100IDECallbackBuild();
        virtual ~T100IDECallbackBuild();

        static T100BOOL             frame_menu_build(void* = T100NULL);

        static T100BOOL             frame_menu_run(void* = T100NULL);

        static T100BOOL             frame_menu_clean(void* = T100NULL);

        static T100BOOL             frame_menu_stop(void* = T100NULL);

    protected:

    private:

};

#endif // T100IDECALLBACKBUILD_H
