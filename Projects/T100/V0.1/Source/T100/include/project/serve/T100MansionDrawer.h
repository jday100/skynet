#ifndef T100MANSIONDRAWER_H
#define T100MANSIONDRAWER_H

#include "T100MansionInfo.h"
#include "T100ProjectInfo.h"
#include "T100ProjectDrawer.h"

namespace T100PROJECT{

class T100MansionDrawer
{
    public:
        T100MansionDrawer();
        virtual ~T100MansionDrawer();

        T100BOOL                    load(T100MansionInfo*, T100PROJECT_INFO_VECTOR*);

        T100STRING                  getName();
        T100ProjectDrawer*          getProjectDrawer();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100MansionInfo*            m_info                      = T100NULL;
        T100ProjectDrawer*          m_project_drawer            = T100NULL;
};

}

#endif // T100MANSIONDRAWER_H
