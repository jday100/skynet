#ifndef T100DX12CONTEXTMANAGER_H
#define T100DX12CONTEXTMANAGER_H

#include "renderer/data/T100DX12Model.h"
#include "renderer/data/T100DX12Context.h"
#include "renderer/context/T100DX12ContextManagerBase.h"

class T100DX12Frame;
class T100DX12Studio;

class T100DX12ContextManager : public T100DX12ContextManagerBase
{
    friend class T100DX12Frame;
    public:
        T100DX12ContextManager(T100DX12Studio*);
        virtual ~T100DX12ContextManager();

        virtual T100VOID            Convert(T100DX12Frame*, T100DX12Model*, T100DX12Context**);

        virtual T100VOID            Update(T100DX12Frame*, T100DX12Context*);

        virtual T100VOID            Render(T100DX12Frame*, T100DX12Context*);

    protected:
        T100DX12Studio*             m_studio            = T100NULL;

    protected:
        T100VOID                    ContextManagerConvert(T100DX12Frame*, T100DX12Model*, T100DX12Context**);
        T100VOID                    ContextManagerUpdate(T100DX12Frame*, T100DX12Context*);
        T100VOID                    ContextManagerRender(T100DX12Frame*, T100DX12Context*);

        T100VOID                    ConvertDot(T100DX12Frame*, T100DX12Model*, T100DX12Context**);
        T100VOID                    ConvertLine(T100DX12Frame*, T100DX12Model*, T100DX12Context**);
        T100VOID                    ConvertTriangle(T100DX12Frame*, T100DX12Model*, T100DX12Context**);
        T100VOID                    ConvertPlane(T100DX12Frame*, T100DX12Model*, T100DX12Context**);
        T100VOID                    ConvertCity(T100DX12Frame*, T100DX12Model*, T100DX12Context**);
        T100VOID                    ConvertSphere(T100DX12Frame*, T100DX12Model*, T100DX12Context**);
        T100VOID                    ConvertRectangle(T100DX12Frame*, T100DX12Model*, T100DX12Context**);

    private:
        T100VOID                    Events(T100DX12Context*);
        T100VOID                    RunEvent(T100DX12Event&, T100DX12Context*);
};

#endif // T100DX12CONTEXTMANAGER_H
