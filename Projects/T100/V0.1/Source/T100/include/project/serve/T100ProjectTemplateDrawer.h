#ifndef T100PROJECTTEMPLATEDRAWER_H
#define T100PROJECTTEMPLATEDRAWER_H

#include "T100ProjectInfo.h"

namespace T100PROJECT{
class T100MansionDrawer;

class T100ProjectTemplateDrawer
{
    public:
        T100ProjectTemplateDrawer(T100MansionDrawer*);
        virtual ~T100ProjectTemplateDrawer();

        T100BOOL            Create(T100ProjectInfo*);

    protected:

    private:
        T100MansionDrawer*          m_drawer            = T100NULL;
};

}

#endif // T100PROJECTTEMPLATEDRAWER_H
