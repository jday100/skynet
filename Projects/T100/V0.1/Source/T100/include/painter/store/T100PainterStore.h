#ifndef T100PAINTERSTORE_H
#define T100PAINTERSTORE_H

#include "T100String.h"
#include "T100DiagramInfo.h"


namespace T100Painter{

class T100PainterStore
{
    public:
        T100PainterStore();
        virtual ~T100PainterStore();

        T100BOOL            OpenFile(T100STRING, T100DiagramInfo*&);

        T100BOOL            SaveAsFile(T100STRING, T100DiagramInfo*);

    protected:

    private:

};

}

#endif // T100PAINTERSTORE_H
