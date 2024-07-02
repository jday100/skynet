#ifndef T100SOFTRASTERIZE_H
#define T100SOFTRASTERIZE_H

#include "T100RasterizeBase.h"
#include "T100RenderBase.h"

class T100SoftRasterize : public T100RasterizeBase
{
    public:
        T100SoftRasterize();
        virtual ~T100SoftRasterize();

        T100VOID                SetRender(T100RenderBase*);
        T100RenderBase*         GetRender();

        T100VOID                SetSize(T100INT, T100INT);

        T100VOID                Draw();

        T100VOID                Pyramid(T100INT, T100INT);
        T100VOID                CrossPoint();

    protected:
        T100RenderBase*         m_render            = T100NULL;

        T100INT                 m_width             = 400;
        T100INT                 m_height            = 300;

    private:
};

#endif // T100SOFTRASTERIZE_H
