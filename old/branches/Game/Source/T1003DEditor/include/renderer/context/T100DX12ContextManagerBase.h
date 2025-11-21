#ifndef T100DX12CONTEXTMANAGERBASE_H
#define T100DX12CONTEXTMANAGERBASE_H

#include "dx12/T100DX12Header.h"
#include "renderer/data/T100DX12Frame.h"
#include "renderer/data/T100DX12Context.h"

class T100DX12Studio;

class T100DX12ContextManagerBase
{
    public:
        T100DX12ContextManagerBase();
        virtual ~T100DX12ContextManagerBase();

    protected:
        T100VOID                    CreateRootSignature(T100DX12Studio*, T100DX12Context*);
        T100VOID                    CreateAndCloseCommandList(T100DX12Studio*, T100DX12Frame*, T100DX12Context*);

        T100VOID                    CreateConstantBufferView(T100DX12Studio*, T100DX12Context*);
        T100VOID                    CreateBundle(T100DX12Studio*, T100DX12Context*);

        T100VOID                    ConvertModel(T100DX12Model*, T100DX12Context*);

        T100VOID                    SetBundlePositions(T100DX12Context*);

        T100VOID                    CreateBundle1(T100DX12Studio*, T100DX12Context*);

    private:
};

#endif // T100DX12CONTEXTMANAGERBASE_H
