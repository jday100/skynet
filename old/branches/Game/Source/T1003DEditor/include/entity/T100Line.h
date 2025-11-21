#ifndef T100LINE_H
#define T100LINE_H

#include "T100Editable.h"

struct D3D12_INPUT_ELEMENT_DESC;

class T100Line : public T100Editable
{
    public:
        T100Line();
        virtual ~T100Line();

        static T100WSTRING          Name;
        static T100ENTITY_TYPE      Type;

        virtual T100VOID            Load(T100DX12Scene*);
        virtual T100DX12Model*      Convert(T100DX12Studio*);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

        Vertex*                     vertex;
        T100UINT                    Length;

        T100VOID                    SetTerminus(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetTerminus(T100Vector3);
        T100Vector3                 GetTerminus();

        T100VOID                    SetLength(T100FLOAT);
        T100FLOAT                   GetLength();

    protected:
        T100FLOAT                   m_length            = 0.0f;
        T100Vector3                 m_terminus;

    private:
        T100VOID                    Convert(D3D12_INPUT_ELEMENT_DESC**, T100UINT*);

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100LINE_H
