#include "T100CanvasTransverter.h"

#include "T100PainterCommon.h"

namespace T100Component{

T100CanvasTransverter::T100CanvasTransverter()
    :T100StateTransverter()
{
    //ctor
}

T100CanvasTransverter::~T100CanvasTransverter()
{
    //dtor
}

T100Painter::T100CanvasState* T100CanvasTransverter::GetCurrent()
{
    return m_state;
}

T100VOID T100CanvasTransverter::Change(T100WORD state)
{
    switch(state){
    case T100Painter::T100CANVAS_STATE_NONE:
        {
            m_current   = state;
            m_state     = T100NULL;
        }
        break;
    case T100Painter::T100CANVAS_STATE_COMMON:
        {
            if(!m_common){
                m_common = T100NEW T100Painter::T100CanvasStateCommon();
            }
            m_current   = state;
            m_state     = m_common;
        }
        break;
    case T100Painter::T100CANVAS_STATE_PAINT:
        {
            if(!m_paint){
                m_paint = T100NEW T100Painter::T100CanvasStatePaint();
            }
            m_current   = state;
            m_state     = m_paint;
        }
        break;
    case T100Painter::T100CANVAS_STATE_SELECTED:
        {
            if(!m_selected){
                m_selected  = T100NEW T100Painter::T100CanvasStateSelected();
            }
            m_current   = state;
            m_state     = m_selected;
        }
        break;
    default:
        break;
    }
}

}
