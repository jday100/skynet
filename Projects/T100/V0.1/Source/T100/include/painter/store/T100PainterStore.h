#ifndef T100PAINTERSTORE_H
#define T100PAINTERSTORE_H

#include "T100String.h"
#include "T100PainterCommon.h"

namespace T100Painter{

class T100PainterStore
{
    public:
        T100PainterStore();
        virtual ~T100PainterStore();

        T100BOOL            OpenFile(T100STRING, T100PAINTER_ELEMENT_VECTOR*);

    protected:

    private:
};

}

#endif // T100PAINTERSTORE_H
