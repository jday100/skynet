#ifndef T1003DEDITOR_H
#define T1003DEDITOR_H

#include "T100DX12Base.h"
#include "T100Entity.h"

class T1003DEditor
{
    public:
        T1003DEditor();
        virtual ~T1003DEditor();

        virtual T100VOID            Create(HWND, UINT, UINT);
        virtual T100VOID            SetSize(UINT, UINT);

        virtual T100VOID            Append(T100Entity*);

        virtual T100VOID            Render();

    protected:
        UINT                        m_width;
        UINT                        m_height;
        T100DX12Base*               m_dx12          = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITOR_H
