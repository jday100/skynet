#ifndef T100IDECALLBACKEDIT_H
#define T100IDECALLBACKEDIT_H

#include "T100IDECallback.h"


class T100IDECallbackEdit : public T100IDECallback
{
    public:
        T100IDECallbackEdit();
        virtual ~T100IDECallbackEdit();

        static T100BOOL             frame_menu_undo(void* = T100NULL);

        static T100BOOL             frame_menu_redo(void* = T100NULL);

        static T100BOOL             frame_menu_cut(void* = T100NULL);

        static T100BOOL             frame_menu_copy(void* = T100NULL);

        static T100BOOL             frame_menu_paste(void* = T100NULL);

    protected:

    private:
};

#endif // T100IDECALLBACKEDIT_H
