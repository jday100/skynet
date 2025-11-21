#ifndef T100DX12CONTEXTMANAGER_H
#define T100DX12CONTEXTMANAGER_H

#include "data/T100DX12Mesh.h"
#include "data/T100DX12Frame.h"
#include "data/T100DX12Context.h"
#include "context/T100DX12ContextManagerBase.h"

class T100DX12Studio;

class T100DX12ContextManager : public T100DX12ContextManagerBase
{
    public:
        T100DX12ContextManager(T100DX12Studio*);
        virtual ~T100DX12ContextManager();

        T100DX12Context*        Convert(T100DX12Frame*, T100DX12Mesh*);

    protected:
        T100DX12Studio*         m_studioPtr         = T100NULL;

    private:
        T100VOID                CreateConstantBuffers(T100DX12Context*);

        T100VOID                CreateConstantBuffer(T100DX12Context*);

        T100DX12Context*        ConvertSpace(T100DX12Frame*, T100DX12Mesh*);
        T100DX12Context*        ConvertScreen(T100DX12Frame*, T100DX12Mesh*);

        T100DX12Context*        ConvertCity(T100DX12Frame*, T100DX12Mesh*);
};

#endif // T100DX12CONTEXTMANAGER_H
