#ifndef T100PAINTERSERVE_H
#define T100PAINTERSERVE_H

#include "T100Common.h"
#include "T100PainterEntryDrawer.h"

class T100PainterServe
{
    public:
        T100PainterServe();
        virtual ~T100PainterServe();

        T100PainterEntryDrawer*         getEntryDrawer();

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

    private:
        T100PainterEntryDrawer*         m_entry_drawer          = T100NULL;
};

#endif // T100PAINTERSERVE_H
