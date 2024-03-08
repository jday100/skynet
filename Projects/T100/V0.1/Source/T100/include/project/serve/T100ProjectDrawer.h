#ifndef T100PROJECTDRAWER_H
#define T100PROJECTDRAWER_H

#include "T100ProjectInfo.h"
#include "T100ProjectTemplateDrawer.h"


namespace T100PROJECT{
class T100MansionDrawer;

class T100ProjectDrawer
{
    public:
        T100ProjectDrawer(T100MansionDrawer*);
        virtual ~T100ProjectDrawer();

        T100BOOL            Create(T100ProjectInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100MansionDrawer*                  m_mansion_drawer        = T100NULL;
        T100ProjectTemplateDrawer*          m_template_drawer       = T100NULL;
};

}

#endif // T100PROJECTDRAWER_H
