#ifndef T100PAINTERSTORE_H
#define T100PAINTERSTORE_H

#include "T100Common.h"
#include "T100DiagramInfo.h"

class T100PainterStore
{
    public:
        T100PainterStore();
        virtual ~T100PainterStore();

        T100BOOL            Load(T100STRING, T100DiagramInfo&);
        T100BOOL            Save(T100STRING, T100DiagramInfo&);

    protected:

    private:
};

#endif // T100PAINTERSTORE_H
