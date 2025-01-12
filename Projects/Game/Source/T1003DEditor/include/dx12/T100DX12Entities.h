#ifndef T100DX12ENTITIES_H
#define T100DX12ENTITIES_H

#include "T100DX12.h"

class T100DX12Entities : public T100DX12
{
    public:
        T100DX12Entities();
        virtual ~T100DX12Entities();

        virtual T100VOID            Start();
        virtual T100VOID            Update();
        virtual T100VOID            Render();

        virtual T100VOID            Append(T100Entity*);

    protected:
        T100DX12_COMMANDLIST_VECTOR             m_commandLists;

    private:
        virtual T100VOID            LoadAssetsEmpty();
        virtual T100VOID            PopulateCommandListEmpty();

        virtual T100VOID            LoadAssets();
        virtual T100VOID            PopulateCommandList();
        virtual T100VOID            PopulateCommandListItem(ComPtr<ID3D12GraphicsCommandList>);

        virtual T100VOID            LoadEntities();
        virtual T100VOID            LoadEntity(T100Entity*);
};

#endif // T100DX12ENTITIES_H
