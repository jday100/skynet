#ifndef T100DCBASE_H
#define T100DCBASE_H

#include <windows.h>
#include "T100Common.h"
#include "gui/base/T100Pen.h"
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
        T100Pen*            GetPen();

        T100VOID            SetBrush(T100Brush*);
        T100Brush*          GetBrush();

    protected:
        T100Brush*          m_brushPtr          = T100NULL;
        T100Pen*            m_penPtr            = T100NULL;
        T100Window*         m_windowPtr         = T100NULL;
        HDC                 m_hdc;
        PAINTSTRUCT         m_paintStruct;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100DCBASE_H
