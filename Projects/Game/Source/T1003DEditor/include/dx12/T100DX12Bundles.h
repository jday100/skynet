#ifndef T100DX12BUNDLES_H
#define T100DX12BUNDLES_H

#include "T100DX12Base.h"

class T100DX12Bundles : public T100DX12Base
{
    public:
        T100DX12Bundles();
        virtual ~T100DX12Bundles();

        virtual T100VOID                    Append(T100Entity*);

    protected:
        virtual T100VOID                    LoadEntity(T100Entity*);

        virtual T100VOID                    LoadVertexBuffer(T100Entity*);
        virtual T100VOID                    LoadPixelBuffer(T100Entity*);
        virtual T100VOID                    LoadTexture(T100Entity*);

    private:
};

#endif // T100DX12BUNDLES_H
