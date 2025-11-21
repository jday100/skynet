#ifndef T100DOT_H
#define T100DOT_H

#include "T100Editable.h"

struct D3D12_INPUT_ELEMENT_DESC;

class T100Dot : public T100Editable
{
    public:
        T100Dot();
        virtual ~T100Dot();

        static T100ENTITY_TYPE      Type;
        static T100WSTRING          Name;

        Vertex                      vertex;
        T100UINT                    Length;

        virtual T100VOID            Load(T100DX12Scene*);
        virtual T100DX12Model*      Convert(T100DX12Studio*);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

    protected:
        T100VOID                    Convert(D3D12_INPUT_ELEMENT_DESC**, T100UINT*);

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100DOT_H
