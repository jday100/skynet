#ifndef T100EDITORSERVE_H
#define T100EDITORSERVE_H

#include "T100Common.h"
#include "T100Entity.h"
#include "T100Render.h"
class T100Editor;

class T100EditorServe
{
    public:
        T100EditorServe(T100Editor*);
        virtual ~T100EditorServe();

        T100VOID            SetEntityID(T100INT);
        T100VOID            SetRender(T100Render*);

        T100VOID            Create(T100INT, T100INT);
        T100VOID            Second();
        T100VOID            Finished(T100INT, T100INT);

    protected:
        T100INT             m_entity_id         = 0;
        T100Entity*         m_current           = T100NULL;
        T100Render*         m_render            = T100NULL;

    private:
        T100Editor*         m_editor            = T100NULL;
};

#endif // T100EDITORSERVE_H
