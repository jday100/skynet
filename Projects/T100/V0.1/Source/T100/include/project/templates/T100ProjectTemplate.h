#ifndef T100PROJECTTEMPLATE_H
#define T100PROJECTTEMPLATE_H

#include "T100ProjectInfo.h"

namespace T100PROJECT{
class T100MansionDrawer;

class T100ProjectTemplate
{
    public:
        T100ProjectTemplate(T100MansionDrawer*, T100ProjectInfo*);
        virtual ~T100ProjectTemplate();

        virtual T100BOOL            Create() = 0;

        T100ProjectInfo*            getProjectInfo();
        T100MansionDrawer*          getMansionDrawer();

    protected:

    private:
        T100MansionDrawer*          m_drawer        = T100NULL;
        T100ProjectInfo*            m_info          = T100NULL;
};

}

#endif // T100PROJECTTEMPLATE_H
