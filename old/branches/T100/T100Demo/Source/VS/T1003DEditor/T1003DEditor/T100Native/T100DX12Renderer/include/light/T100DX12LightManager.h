#ifndef T100DX12LIGHTMANAGER_H
#define T100DX12LIGHTMANAGER_H

#include "data/T100DX12Light.h"

class T100DX12Studio;

class T100DX12LightManager
{
    public:
        T100DX12LightManager(T100DX12Studio*);
        virtual ~T100DX12LightManager();

    protected:
        T100DX12Studio*         m_studio            = T100NULL;

    private:
};

#endif // T100DX12LIGHTMANAGER_H
