#include "T100CanvasTransverter.h"

T100CanvasTransverter::T100CanvasTransverter()
{
    //ctor
}

T100CanvasTransverter::~T100CanvasTransverter()
{
    //dtor
}

T100CanvasState* T100CanvasTransverter::Current()
{
    std::lock_guard<std::mutex>         lock(m_mutex);
    return m_state;
}

T100VOID T100CanvasTransverter::Change(T100WORD state)
{
    std::lock_guard<std::mutex>         lock(m_mutex);

    switch(state){
    case T100CANVAS_STATE_NONE:
        {
            if(!m_none){
                m_none      = T100NEW T100CanvasStateNone();
            }
            m_state     = m_none;
        }
        break;
    case T100CANVAS_STATE_EDIT:
        {
            if(!m_edit){
                m_edit      = T100NEW T100CanvasStateEdit();
            }
            m_state     = m_edit;
        }
        break;
    case T100CANVAS_STATE_PAINT:
        {
            if(!m_paint){
                m_paint     = T100NEW T100CanvasStatePaint();
            }
            m_state     = m_paint;
        }
        break;
    case T100CANVAS_STATE_SIZING:
        {
            if(!m_sizing){
                m_sizing    = T100NEW T100CanvasStateSizing();
            }
            m_state     = m_sizing;
        }
        break;
    case T100CANVAS_STATE_SELECTED:
        {
            if(!m_selected){
                m_selected  = T100NEW T100CanvasStateSelected();
            }
            m_state     = m_selected;
        }
        break;
    }
}
