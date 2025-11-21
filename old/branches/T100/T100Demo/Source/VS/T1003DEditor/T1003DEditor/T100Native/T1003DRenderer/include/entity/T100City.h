#ifndef T100CITY_H
#define T100CITY_H

#include "link/T100Entity.h"

class T100City : public T100Entity
{
    public:
        T100City();
        virtual ~T100City();

        static T100WSTRING          Name;
        static T100UINT             Type;

        virtual T100VOID            Load();
        virtual T100VOID            Clear();

        T100VOID                    SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetPosition(T100Vector3f&);

        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3f&);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

        const T100UINT StandardVertexStride = 44;

        const T100DXGI_FORMAT StandardIndexFormat = T100DXGI_FORMAT_R32_UINT;

        const T100UINT VertexDataOffset     = 524288;
        const T100UINT VertexDataLength     = 820248;
        const T100UINT IndexDataOffset      = 1344536;
        const T100UINT IndexDataLength      = 74568;

        TextureResource Textures[1] =
        {
            { 1024, 1024, 1, T100DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } },
        };

        DrawParameters Draws[1] =
        {
            { 0, -1, -1, 0, 18642, 0 },
        };

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100CITY_H
