#ifndef T100DX12EDITOR_H
#define T100DX12EDITOR_H

#include "T100DX12.h"

class T100DX12Editor : public T100DX12
{
    public:
        T100DX12Editor();
        virtual ~T100DX12Editor();

        virtual T100VOID                    Start();
        virtual T100VOID                    Update();
        virtual T100VOID                    Render();

        virtual T100VOID                    Append(T100Entity*);

    protected:

    private:
        virtual T100VOID                    LoadAssets();
        virtual T100VOID                    LoadEntities();
        virtual T100VOID                    LoadEntity(T100Entity*);

        virtual T100VOID                    PopulateCommandList();


        virtual T100VOID                    LoadAssetsEmpty();
        virtual T100VOID                    PopulateCommandListEmpty();


};

#endif // T100DX12EDITOR_H
