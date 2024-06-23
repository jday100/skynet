#ifndef T100WXVIEW_H
#define T100WXVIEW_H

#include "T100ViewBase.h"

class T100WxView : public T100ViewBase
{
    public:
        T100WxView();
        virtual ~T100WxView();

        T100VOID            Draw(T100VOID* = T100NULL);

    protected:

    private:
};

#endif // T100WXVIEW_H
