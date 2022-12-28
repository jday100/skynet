#ifndef T100PAINTERSERVE_H
#define T100PAINTERSERVE_H

#include "T100Common.h"
#include "T100String.h"

namespace T100Painter{

class T100PainterServe
{
    public:
        T100PainterServe();
        virtual ~T100PainterServe();

        T100BOOL            SaveFile(T100STRING);
        T100BOOL            LoadFile(T100STRING);

        T100BOOL            IsModified();
        T100VOID            DiscardEdits();


    protected:

    private:
};

}

#endif // T100PAINTERSERVE_H
