#ifndef T100GROUPEDENTRYDRAWER_H
#define T100GROUPEDENTRYDRAWER_H

#include "T100Common.h"
#include "base\T100Entry.h"
#include "T100Grouper.h"

class T100GroupedEntryDrawer
{
    public:
        T100GroupedEntryDrawer();
        virtual ~T100GroupedEntryDrawer();

        T100BOOL                append(T100Entry*);
        T100BOOL                remove(T100Entry*);

        T100VOID                setGrouper(T100Grouper*);
        T100Grouper*            getGrouper();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100Grouper*            m_grouper           = T100NULL;
};

#endif // T100GROUPEDENTRYDRAWER_H
