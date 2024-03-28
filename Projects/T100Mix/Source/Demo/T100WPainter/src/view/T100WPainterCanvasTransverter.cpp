#include "T100WPainterCanvasTransverter.h"

T100WPainterCanvasTransverter::T100WPainterCanvasTransverter()
{
    //ctor
}

T100WPainterCanvasTransverter::~T100WPainterCanvasTransverter()
{
    //dtor
}

T100WPainterCanvasState* T100WPainterCanvasTransverter::GetCurrent()
{
    std::lock_guard<std::mutex>         lock(m_mutex);
    return m_state;
}

T100VOID T100WPainterCanvasTransverter::Change(T100WORD state)
{
    std::lock_guard<std::mutex>         lock(m_mutex);

    switch(state){
    case T100CANVAS_STATE_NONE:
        {
            if(!m_none){
                m_none      = T100NEW T100WPainterCanvasStateNone();
            }
            m_state     = m_none;
        }
        break;
    case T100CANVAS_STATE_EDIT:
        {
            if(!m_edit){
                m_edit      = T100NEW T100WPainterCanvasStateEdit();
            }
            m_state     = m_edit;
        }
        break;
    case T100CANVAS_STATE_PAINT:
        {
            if(!m_paint){
                m_paint     = T100NEW T100WPainterCanvasStatePaint();
            }
            m_state     = m_paint;
        }
        break;
    case T100CANVAS_STATE_SIZING:
        {
            if(!m_sizing){
                m_sizing    = T100NEW T100WPainterCanvasStateSizing();
            }
            m_state     = m_sizing;
        }
        break;
    case T100CANVAS_STATE_SELECTED:
        {
            if(!m_selected){
                m_selected  = T100NEW T100WPainterCanvasStateSelected();
            }
            m_state     = m_selected;
        }
        break;
    }

}
