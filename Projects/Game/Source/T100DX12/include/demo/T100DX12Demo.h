#ifndef T100DX12DEMO_H
#define T100DX12DEMO_H

#include "T100Game.h"

class T100DX12Demo : public T100Game
{
    public:
        T100DX12Demo(UINT width, UINT height, std::wstring name);
        virtual ~T100DX12Demo();

        virtual T100VOID            OnInit();
        virtual T100VOID            OnUpdate();
        virtual T100VOID            OnRender();
        virtual T100VOID            OnDestroy();

    protected:

    private:
};

#endif // T100DX12DEMO_H
