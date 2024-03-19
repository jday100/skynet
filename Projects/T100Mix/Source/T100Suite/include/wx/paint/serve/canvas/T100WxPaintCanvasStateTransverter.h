#ifndef T100WXPAINTCANVASSTATETRANSVERTER_H
#define T100WXPAINTCANVASSTATETRANSVERTER_H

#include <mutex>
#include "T100StateTransverter.h"
#include "T100WxPaintCanvasStateNone.h"

typedef enum{
    T100WX_PAINT_CANVAS_STATE_NONE          = 0,
    T100WX_PAINT_CANVAS_STATE_COMMON
}T100WX_PAINT_CANVAS_STATE;


class T100WxPaintCanvasStateTransverter : public T100StateTransverter
{
    public:
        T100WxPaintCanvasStateTransverter();
        virtual ~T100WxPaintCanvasStateTransverter();

        T100WxPaintCanvasStateBase*         GetCurrent();
        T100BOOL                            Change(T100State*);

        T100VOID                            Change(T100WORD);

    protected:
        T100WxPaintCanvasStateBase*         m_state         = T100NULL;

    private:
        std::mutex                          m_mutex;

        T100WxPaintCanvasStateNone*         m_none          = T100NULL;
};

#endif // T100WXPAINTCANVASSTATETRANSVERTER_H
