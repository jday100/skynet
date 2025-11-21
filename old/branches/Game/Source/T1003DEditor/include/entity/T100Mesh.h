#ifndef T100MESH_H
#define T100MESH_H

#include "T100Entity.h"

class T100Mesh : public T100Entity
{
    public:
        T100Mesh();
        virtual ~T100Mesh();

        static T100ENTITY_TYPE      Type;
        static T100WSTRING          Name;

        T100BYTE*                   VertexDataPtr       = T100NULL;
        T100BYTE*                   IndexDataPtr        = T100NULL;

        T100UINT                    VertexDataLength    = 0;
        T100UINT                    IndexDataLength     = 0;

        virtual T100VOID            Load(T100DX12Scene*);
        virtual T100DX12Model*      Convert(T100DX12Studio*);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100MESH_H
