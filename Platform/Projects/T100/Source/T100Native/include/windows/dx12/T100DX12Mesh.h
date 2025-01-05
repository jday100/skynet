#ifndef T100DX12MESH_H
#define T100DX12MESH_H

#include <vector>
#include <d3d12.h>
#include <DirectXMath.h>


class T100DX12Mesh
{
    public:
        T100DX12Mesh();
        virtual ~T100DX12Mesh();

        std::vector<DirectX::XMFLOAT3>      VERTEX;

    protected:

    private:
};

#endif // T100DX12MESH_H
