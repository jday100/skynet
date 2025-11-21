#ifndef T100DX12LIGHT_H
#define T100DX12LIGHT_H

#include <vector>
#include "T100Common.h"
#include "math/T100Vector3.h"

#define     T100DX12_LIGHT_VECTOR           std::vector<T100DX12Light*>

class T100Light;

class T100DX12Light
{
    friend class T100DX12LightManager;
    public:
        T100DX12Light();
        virtual ~T100DX12Light();

        T100VOID                    SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetPosition(T100Vector3);
        T100Vector3                 GetPosition();

        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3);
        T100Vector3                 GetRotation();

    protected:
        T100Light*                  m_source            = T100NULL;

        T100Vector3                 m_position;
        T100Vector3                 m_rotation;

    private:
};

#endif // T100DX12LIGHT_H
