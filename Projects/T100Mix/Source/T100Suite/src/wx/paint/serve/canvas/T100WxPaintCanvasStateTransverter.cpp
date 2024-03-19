#include "T100WxPaintCanvasStateTransverter.h"

T100WxPaintCanvasStateTransverter::T100WxPaintCanvasStateTransverter()
    :T100StateTransverter()
{
    //ctor
}

T100WxPaintCanvasStateTransverter::~T100WxPaintCanvasStateTransverter()
{
    //dtor
}

T100WxPaintCanvasStateBase* T100WxPaintCanvasStateTransverter::GetCurrent()
{
    std::lock_guard<std::mutex>         lock(m_mutex);

    return m_state;
}

T100BOOL T100WxPaintCanvasStateTransverter::Change(T100State* state)
{

}

T100VOID T100WxPaintCanvasStateTransverter::Change(T100WORD state)
{
    std::lock_guard<std::mutex>         lock(m_mutex);

    switch(state){
    case T100WX_PAINT_CANVAS_STATE_NONE:
        {
            if(!m_none){
                m_none  = T100NEW T100WxPaintCanvasStateNone();
            }
            m_current   = state;
            m_state     = m_none;
        }
        break;
    }
}
