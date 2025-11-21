#ifndef T1003DEDITORLIGHTMANAGER_H
#define T1003DEDITORLIGHTMANAGER_H

#include <atomic>
#include "T100Common.h"
#include "data/T100Light.h"

class T1003DEditorServe;

class T1003DEditorLightManager
{
    public:
        T1003DEditorLightManager(T1003DEditorServe*);
        virtual ~T1003DEditorLightManager();

        T100Light*              GetLight();

    protected:
        T1003DEditorServe*      m_servePtr      = T100NULL;
        std::atomic_int         m_lightCount;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T1003DEDITORLIGHTMANAGER_H
