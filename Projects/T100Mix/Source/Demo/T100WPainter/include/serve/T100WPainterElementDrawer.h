#ifndef T100WPAINTERELEMENTDRAWER_H
#define T100WPAINTERELEMENTDRAWER_H

#include "T100Common.h"
#include "T100ElementBase.h"

class T100WPainterElementDrawer
{
    public:
        T100WPainterElementDrawer();
        virtual ~T100WPainterElementDrawer();


        T100ElementBase*            Create();

    protected:

    private:
};

#endif // T100WPAINTERELEMENTDRAWER_H
