#ifndef T100PROJECTDRAWER_H
#define T100PROJECTDRAWER_H

#include "T100ProjectInfo.h"
#include "T100ProjectTemplateDrawer.h"


namespace T100PROJECT{
class T100MansionDrawer;

class T100ProjectDrawer
{
    friend class T100TemplateProjectEmpty;
    public:
        T100ProjectDrawer(T100MansionDrawer*);
        virtual ~T100ProjectDrawer();

        T100BOOL            Create(T100ProjectInfo*);

        T100BOOL            Load();

        T100BOOL            Open(T100ProjectInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            mkdir(T100ProjectInfo*);

    private:
        T100PROJECT_INFO_VECTOR             m_projects;
        T100MansionDrawer*                  m_mansion_drawer        = T100NULL;
        T100ProjectTemplateDrawer*          m_template_drawer       = T100NULL;
};

}

#endif // T100PROJECTDRAWER_H
