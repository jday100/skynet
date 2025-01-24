#ifndef T100ENTITY_H
#define T100ENTITY_H

#include <vector>
#include "d3d12/DirectXMath.h"
#include "T100Common.h"

#define     T100DX12_ENTITY_VECTOR          std::vector<T100Entity*>

using namespace DirectX;

struct Vertex
{
    XMFLOAT3    position;
    XMFLOAT4    color;
};

class T100Entity
{
    public:
        T100Entity();
        virtual ~T100Entity();

        XMFLOAT3        position;

        Vertex*         vertex          = T100NULL;

        T100UINT        size            = 0;

        virtual T100VOID            load();

    protected:


    private:
};

#endif // T100ENTITY_H
