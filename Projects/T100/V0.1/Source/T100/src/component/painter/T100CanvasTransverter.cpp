#include "T100CanvasTransverter.h"

#include "T100PainterCommon.h"

#include "T100TestTools.h"

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

T100WORD T100CanvasTransverter::GetState()
{
    return m_current;
}

T100Painter::T100CanvasState* T100CanvasTransverter::GetCurrent()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    if(!m_state){
        T100Library::T100TestTools::Print(L"NULL");
    }
    return m_state;
}

T100VOID T100CanvasTransverter::Change(T100WORD state)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    switch(state){
    case T100Painter::T100CANVAS_STATE_NONE:
        {
            if(!m_none){
                m_none  = T100NEW T100Painter::T100CanvasStateNone();
            }
            m_current   = state;
            m_state     = m_none;
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
    case T100Painter::T100CANVAS_STATE_SIZING:
        {
            if(!m_sizing){
                m_sizing  = T100NEW T100Painter::T100CanvasStateSizing();
            }
            m_current   = state;
            m_state     = m_sizing;
        }
        break;
    case T100Painter::T100CANVAS_STATE_EDIT:
        {
            if(!m_edit){
                m_edit  = T100NEW T100Painter::T100CanvasStateEdit();
            }
            m_current   = state;
            m_state     = m_edit;
        }
        break;
    default:
        break;
    }
}

}
