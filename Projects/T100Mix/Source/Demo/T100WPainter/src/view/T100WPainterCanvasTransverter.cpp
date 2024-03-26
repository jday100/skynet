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

        }
        break;
    }

}
