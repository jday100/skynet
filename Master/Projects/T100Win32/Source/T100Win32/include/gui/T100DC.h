#ifndef T100DC_H
#define T100DC_H

#include "gui/dc/T100DCBase.h"

class T100DC : public T100DCBase
{
    public:
        T100DC(T100Window*);
        virtual ~T100DC();

        T100VOID            Clear();

        T100VOID            DrawArc();
        T100VOID            DrawBitmap();
        T100VOID            DrawCircle(T100Point, T100WORD);
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
        T100VOID            DrawRoundedRectangle(T100Point, T100Size, T100FLOAT);
        T100VOID            DrawSpline();
        T100VOID            DrawText();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100DC_H
