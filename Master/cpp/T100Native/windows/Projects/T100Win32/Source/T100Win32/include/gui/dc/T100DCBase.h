#ifndef T100DCBASE_H
#define T100DCBASE_H

#include <windows.h>
#include "gui/T100Font.h"
#include "base/T100Size.h"
#include "base/T100Point.h"
#include "gui/T100Pen.h"
#include "gui/T100Brush.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100Window;

class T100DCBase : public T100Class
{
    public:
        T100DCBase(T100Window*);
        virtual ~T100DCBase();

        T100VOID                        SetPen(const T100Pen&);
        const T100Pen&                  GetPen();

        T100VOID                        SetBrush(const T100Brush&);
        const T100Brush&                GetBrush();

        T100VOID                        SetFont(const T100Font&);
        const T100Font&                 GetFont();

    protected:
        HDC                             m_hdc;
        T100Pen                         m_pen;
        T100Brush                       m_brush;
        T100Font                        m_font;
        T100Window*                     m_window        = T100NULL;
        PAINTSTRUCT                     m_paintStruct;

    private:
        T100VOID                        init();
        T100VOID                        uninit();
};

}

#endif // T100DCBASE_H
