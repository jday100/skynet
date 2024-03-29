#ifndef T100WPAINTERELEMENTDRAWER_H
#define T100WPAINTERELEMENTDRAWER_H

#include "T100Common.h"
#include "T100ElementBase.h"
#include "T100ElementInfo.h"

class T100WPainterElementDrawer
{
    public:
        T100WPainterElementDrawer();
        virtual ~T100WPainterElementDrawer();


        T100ElementBase*            Create();

        T100BOOL                    Select(T100ElementInfo*);

    protected:

    private:
        T100ElementInfo*            m_current           = T100NULL;
};

#endif // T100WPAINTERELEMENTDRAWER_H
