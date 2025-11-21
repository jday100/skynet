#ifndef T100DX12EVENT_H
#define T100DX12EVENT_H

#include <queue>
#include "dx12/T100DX12Header.h"

#define     T100DX12_EVENT_QUEUE            std::queue<T100DX12Event>

class T100DX12Event
{
    public:
        T100DX12Event();
        virtual ~T100DX12Event();

        T100UINT            Type            = 0;
        union{
            T100BOOL        BoolValue;
            T100UINT        UINTValue;
            T100VOID*       VoidValue;
            XMFLOAT3        Float3Value;
        };

    protected:

    private:
};

#endif // T100DX12EVENT_H
