#ifndef T100IDEPLATENMANAGER_H
#define T100IDEPLATENMANAGER_H

#include "T100IDEView.h"
#include "T100IDEAllPlatens.h"


namespace T100IDE{
class T100IDEPlatenBase;


class T100IDEPlatenManager
{
    public:
        T100IDEPlatenManager(T100IDEView*);
        virtual ~T100IDEPlatenManager();

        T100IDEDefaultPlaten*       getDefault();
        T100IDEPlatenBase*          getCurrent();

        T100BOOL                    Change(T100IDE_TYPE);

        T100BOOL                    Exists(T100IDE_TYPE);

        T100IDEPlatenBase*          getPlaten(T100IDE_TYPE);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100IDEView*                m_view          = T100NULL;
        T100IDEPlatenBase*          m_current       = T100NULL;

        T100IDEDefaultPlaten*       m_default       = T100NULL;
        T100IDEEditorPlaten*        m_editor        = T100NULL;
        T100IDEPainterPlaten*       m_painter       = T100NULL;

};

}

#endif // T100IDEPLATENMANAGER_H
