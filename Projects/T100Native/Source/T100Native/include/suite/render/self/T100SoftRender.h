#ifndef T100SOFTRENDER_H
#define T100SOFTRENDER_H

#include "T100RenderBase.h"

class T100SoftRender : public T100RenderBase
{
    public:
        T100SoftRender();
        virtual ~T100SoftRender();

        T100VOID            Start();
        T100VOID            Stop();

        T100VOID            Draw();

        T100VOID            SetSize(T100INT, T100INT);

        T100BYTE*           GetData();
        T100INT             GetWidth();
        T100INT             GetHeight();

    protected:
        T100INT             m_width             = 0;
        T100INT             m_height            = 0;
        T100INT             m_length            = 0;

        T100BYTE*           m_screen            = T100NULL;

    private:
};

#endif // T100SOFTRENDER_H
