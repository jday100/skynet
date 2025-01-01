#ifndef T100PROJECTPLATENMANAGER_H
#define T100PROJECTPLATENMANAGER_H

#include "T100ProjectView.h"
#include "T100ProjectAllPlatens.h"

class T100ProjectPlatenManager
{
    public:
        T100ProjectPlatenManager(T100ProjectView*);
        virtual ~T100ProjectPlatenManager();

        T100ProjectDefaultPlaten*       getDefault();
        T100ProjectPlatenBase*          getCurrent();

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

    private:
        T100ProjectView*                m_view          = T100NULL;

        T100ProjectDefaultPlaten*       m_default       = T100NULL;
        T100ProjectPlatenBase*          m_current       = T100NULL;
};

#endif // T100PROJECTPLATENMANAGER_H
