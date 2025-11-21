#ifndef T100DX12LIGHTMANAGER_H
#define T100DX12LIGHTMANAGER_H

#include "data/T100Light.h"
#include "renderer/data/T100DX12Light.h"

class T100DX12Studio;

class T100DX12LightManager
{
    public:
        T100DX12LightManager(T100DX12Studio*);
        virtual ~T100DX12LightManager();

        T100DX12_LIGHT_VECTOR&      GetLights();

        virtual T100VOID            Append(T100Light*);
        virtual T100VOID            Remove(T100Light*);

    protected:
        T100DX12Studio*             m_studioPtr         = T100NULL;
        T100DX12_LIGHT_VECTOR       m_lights;

    private:
        T100VOID                    ConvertLight(T100DX12Light*, T100Light*);
};

#endif // T100DX12LIGHTMANAGER_H
