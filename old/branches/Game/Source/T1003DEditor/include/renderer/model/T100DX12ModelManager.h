#ifndef T100DX12MODELMANAGER_H
#define T100DX12MODELMANAGER_H

#include "entity/T100City.h"
#include "renderer/data/T100DX12Model.h"
#include "renderer/data/T100DX12Context.h"
#include "renderer/model/T100DX12ModelManagerBase.h"

class T100DX12Studio;

class T100DX12ModelManager : public T100DX12ModelManagerBase
{
    friend class T100DX12Model;
    friend class T100DX12SceneManager;
    friend class T100DX12FrameManager;
    friend class T100DX12ModelManagerBase;
    public:
        T100DX12ModelManager(T100DX12Studio*);
        virtual ~T100DX12ModelManager();

        virtual T100VOID                Append(T100DX12Model*);
        virtual T100VOID                Remove(T100DX12Model*);

    protected:
        T100DX12Studio*                 m_studio            = T100NULL;
        T100DX12_MODEL_VECTOR           m_models;

        T100City*                       m_entity            = T100NULL;
        T100DX12Model*                  m_model             = T100NULL;
        T100DX12Context*                m_context           = T100NULL;

        ComPtr<ID3D12RootSignature>             m_rootSignature;

    protected:
        T100VOID                        ModelManagerAppend(T100DX12Model*);
        T100VOID                        ModelManagerRemove(T100DX12Model*);

    private:
};

#endif // T100DX12MODELMANAGER_H
