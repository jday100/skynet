#ifndef T100IDECALLBACKFILE_H
#define T100IDECALLBACKFILE_H

#include "T100IDECallback.h"


class T100IDECallbackFile : public T100IDECallback
{
    public:
        T100IDECallbackFile();
        virtual ~T100IDECallbackFile();

        static T100BOOL             frame_menu_new(void* = T100NULL);

        static T100BOOL             frame_menu_delete(void* = T100NULL);

        static T100BOOL             frame_menu_open(void* = T100NULL);

        static T100BOOL             frame_menu_close(void* = T100NULL);

        static T100BOOL             frame_menu_save(void* = T100NULL);

        static T100BOOL             frame_menu_save_as(void* = T100NULL);

    protected:

    private:
};

#endif // T100IDECALLBACKFILE_H
