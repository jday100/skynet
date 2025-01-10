#ifndef T1003DEDITOR_H
#define T1003DEDITOR_H

#include "T100DX12Base.h"

class T1003DEditor
{
    public:
        T1003DEditor();
        virtual ~T1003DEditor();

        virtual T100VOID            Create(HWND, UINT, UINT);
        virtual T100VOID            SetSize(UINT, UINT);

        virtual T100VOID            Render();

    protected:
        T100DX12Base*               m_dx12          = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITOR_H
