#ifndef T100DC_H
#define T100DC_H

#include <windows.h>
#include "T100Common.h"
#include "gui/base/T100Point.h"

class T100Window;

class T100DC
{
    public:
        T100DC(T100Window*);
        virtual ~T100DC();

        T100VOID            Clear();

        T100VOID            DrawArc();
        T100VOID            DrawBitmap();
        T100VOID            DrawCircle();
        T100VOID            DrawEllipse();
        T100VOID            DrawEllipticArc();
        T100VOID            DrawIcon();
        T100VOID            DrawLabel();
        T100VOID            DrawLine(T100Point, T100Point);
        T100VOID            DrawLines();
        T100VOID            DrawPoint();
        T100VOID            DrawPolygon();
        T100VOID            DrawPolyPolygon();
        T100VOID            DrawRectangle();
        T100VOID            DrawRotatedText();
        T100VOID            DrawRoundedRectangle();
        T100VOID            DrawSpline();
        T100VOID            DrawText();

    protected:
        T100Window*         m_windowPtr         = T100NULL;
        HDC                 m_hdc;
        PAINTSTRUCT         m_paintStruct;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100DC_H
