#ifndef T100PAINTERSTORE_H
#define T100PAINTERSTORE_H

#include "T100Common.h"

class T100PainterStore
{
    public:
        T100PainterStore();
        virtual ~T100PainterStore();

        T100BOOL            OpenFile();

        T100BOOL            SaveFile();

    protected:

    private:
};

#endif // T100PAINTERSTORE_H
