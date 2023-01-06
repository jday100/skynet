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
    T100Painter::T100CanvasState*        result          = T100NULL;

    switch(m_current){
    case T100Painter::T100CANVAS_STATE_NONE:
        {

        }
        break;
    case T100Painter::T100CANVAS_STATE_PAINT:
        {
            result = m_paint;
        }
        break;
    case T100Painter::T100CANVAS_STATE_SELECTED:
        {
            result = m_selected;
        }
        break;
    default:
        break;
    }

    return result;
}

T100VOID T100CanvasTransverter::Change(T100WORD state)
{
    switch(state){
    case T100Painter::T100CANVAS_STATE_NONE:
        {
            m_current   = state;
        }
        break;
    case T100Painter::T100CANVAS_STATE_PAINT:
        {
            if(!m_paint){
                m_paint = T100NEW T100Painter::T100CanvasStatePaint();
            }
            m_current   = state;
        }
        break;
    case T100Painter::T100CANVAS_STATE_SELECTED:
        {
            if(!m_selected){
                m_selected  = T100NEW T100Painter::T100CanvasStateSelected();
            }
            m_current   = state;
        }
        break;
    default:
        break;
    }
}

}
