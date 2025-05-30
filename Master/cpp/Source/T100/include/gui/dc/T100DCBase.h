#ifndef T100DCBASE_H
#define T100DCBASE_H

#include <windows.h>
#include "T100Common.h"
#include "gui/base/T100Pen.h"
#include "gui/font/T100Font.h"
#include "gui/base/T100Size.h"
#include "gui/base/T100Point.h"
#include "gui/base/T100Brush.h"

class T100Window;

class T100DCBase : public T100Class
{
    public:
        T100DCBase(T100Window*);
        virtual ~T100DCBase();

        T100VOID            SetPen(T100Pen*);
        T100Pen*            GetPenPtr();

        T100VOID            SetBrush(T100Brush*);
        T100Brush*          GetBrushPtr();

        T100VOID            SetFont(T100Font);
        T100Font&           GetFont();

    protected:
        T100Brush*          m_brushPtr          = T100NULL;
        T100Pen*            m_penPtr            = T100NULL;
        T100Window*         m_windowPtr         = T100NULL;
        HDC                 m_hdc;
        PAINTSTRUCT         m_paintStruct;

        T100Font            m_font;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100DCBASE_H
