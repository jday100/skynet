#ifndef T100TRIANGLE_H
#define T100TRIANGLE_H

#include "T100Entity.h"

class T100Triangle : public T100Entity
{
    public:
        T100Triangle();
        virtual ~T100Triangle();

        Vertex      triangleVertices[3] =
        {
            { { 0.0f, 0.25f, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
            { { 0.25f, -0.25f, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
            { { -0.25f, -0.25f, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
        };
        T100WSTRING         file            = L"shaders.hlsl";
        std::string         vertexName      = "VSMain";
        std::string         vertexID        = "vs_5_0";
        std::string         pixelName       = "PSMain";
        std::string         pixelID         = "ps_5_0";

        T100UINT            Size(){
                                return sizeof(triangleVertices);
                            }

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();
};

#endif // T100TRIANGLE_H
