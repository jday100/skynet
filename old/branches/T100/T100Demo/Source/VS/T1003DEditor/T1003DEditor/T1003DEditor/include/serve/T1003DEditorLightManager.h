#ifndef T1003DEDITORLIGHTMANAGER_H
#define T1003DEDITORLIGHTMANAGER_H

#include <atomic>
#include "T100Common.h"
#include "link/T1003DLight.h"

class T1003DEditorLightManager
{
    public:
        T1003DEditorLightManager();
        virtual ~T1003DEditorLightManager();

        T1003DLight*            GetLight();

    protected:
        std::atomic_int         m_lightCount;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T1003DEDITORLIGHTMANAGER_H
