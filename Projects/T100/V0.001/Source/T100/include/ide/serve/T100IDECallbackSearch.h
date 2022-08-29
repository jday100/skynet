#ifndef T100IDECALLBACKSEARCH_H
#define T100IDECALLBACKSEARCH_H

#include "T100IDECallback.h"


class T100IDECallbackSearch : public T100IDECallback
{
    public:
        T100IDECallbackSearch();
        virtual ~T100IDECallbackSearch();

        static T100BOOL             frame_menu_find(void* = T100NULL);

        static T100BOOL             frame_menu_replace(void* = T100NULL);

    protected:

    private:
};

#endif // T100IDECALLBACKSEARCH_H
