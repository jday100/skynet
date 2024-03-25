#ifndef T100WPAINTERSTORE_H
#define T100WPAINTERSTORE_H

#include "T100Common.h"
#include "T100DiagramInfo.h"

class T100WPainterStore
{
    public:
        T100WPainterStore();
        virtual ~T100WPainterStore();

        T100BOOL            Load(T100STRING, T100DiagramInfo&);
        T100BOOL            Save(T100STRING, T100DiagramInfo&);

    protected:

    private:
};

#endif // T100WPAINTERSTORE_H
