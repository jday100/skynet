#include "T100CanvasTransverter.h"

#include "T100DiagramCommon.h"
#include "T100DiagramInvoking.h"

T100CanvasTransverter::T100CanvasTransverter() :
    T100StateTransverter()
{
    //ctor
}

T100CanvasTransverter::~T100CanvasTransverter()
{
    //dtor
}

T100UINT T100CanvasTransverter::GetState()
{
    return m_current;
}

T100CanvasState* T100CanvasTransverter::GetCurrent()
{
    return m_state;
}

T100VOID T100CanvasTransverter::Change(T100UINT state)
{
    switch(state){
    case T100CANVAS_STATE_NONE:
        {
            if(!m_none){
                m_none  = T100NEW T100CanvasStateNone();
            }
            m_current   = state;
            m_state     = m_none;
            T100DiagramInvoking::OnCanvasState("None");
        }
        break;
    case T100CANVAS_STATE_SHOW:
        {
            if(!m_show){
                m_show  = T100NEW T100CanvasStateShow();
            }
            m_current   = state;
            m_state     = m_show;
            T100DiagramInvoking::OnCanvasState("Show");
        }
        break;
    case T100CANVAS_STATE_CREATE:
        {
            if(!m_create){
                m_create  = T100NEW T100CanvasStateCreate();
            }
            m_current   = state;
            m_state     = m_create;
            T100DiagramInvoking::OnCanvasState("Create");
        }
        break;
    case T100CANVAS_STATE_EDIT:
        {
            if(!m_edit){
                m_edit  = T100NEW T100CanvasStateEdit();
            }
            m_current   = state;
            m_state     = m_edit;
            T100DiagramInvoking::OnCanvasState("Edit");
        }
        break;
    case T100CANVAS_STATE_PAINT:
        {
            if(!m_paint){
                m_paint = T100NEW T100CanvasStatePaint();
            }
            m_current   = state;
            m_state     = m_paint;
            T100DiagramInvoking::OnCanvasState("Paint");
        }
        break;
    case T100CANVAS_STATE_MOVING:
        {
            if(!m_moving){
                m_moving    = T100NEW T100CanvasStateMoving();
            }
            m_current       = state;
            m_state         = m_moving;
            T100DiagramInvoking::OnCanvasState("Moving");
        }
        break;
    case T100CANVAS_STATE_SELECTED:
        {
            if(!m_selected){
                m_selected    = T100NEW T100CanvasStateSelected();
            }
            m_current       = state;
            m_state         = m_selected;
            T100DiagramInvoking::OnCanvasState("Selected");
        }
        break;
    case T100CANVAS_STATE_TIE_START:
        {
            if(!m_tieStart){
                m_tieStart      = T100NEW T100CanvasStateTieStart();
            }
            m_current       = state;
            m_state         = m_tieStart;
            T100DiagramInvoking::OnCanvasState("TieStart");
        }
        break;
    case T100CANVAS_STATE_TIE_END:
        {
            if(!m_tieEnd){
                m_tieEnd        = T100NEW T100CanvasStateTieEnd();
            }
            m_current       = state;
            m_state         = m_tieEnd;
            T100DiagramInvoking::OnCanvasState("TieEnd");
        }
        break;
    }
}
