#ifndef T100DX12CONTEXTRECTANGLE_H
#define T100DX12CONTEXTRECTANGLE_H

#include "T100DX12Context.h"

class T100DX12ContextRectangle : public T100DX12Context
{
    public:
        T100DX12ContextRectangle();
        virtual ~T100DX12ContextRectangle();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

        virtual T100VOID            Update();
        virtual T100VOID            Render();

    protected:
        T100VOID                    CreateSingle();
        T100VOID                    UpdateSingle();
        T100VOID                    RenderSingle();

        T100VOID                    CreateBundle();
        T100VOID                    UpdateBundle();
        T100VOID                    RenderBundle();

    private:
};

#endif // T100DX12CONTEXTRECTANGLE_H
