#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100Common.h"
#include "T100EditorView.h"
#include "T100EditorServe.h"
#include "T100EditorStore.h"

class T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        T100VOID                run();
        T100VOID*               getFrame();

        T100BOOL                renew();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100EditorView*         m_view          = T100NULL;
        T100EditorServe*        m_serve         = T100NULL;
        T100EditorStore*        m_store         = T100NULL;
};

#endif // T100EDITOR_H
