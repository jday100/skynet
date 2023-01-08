#include "T100PainterTransverter.h"

namespace T100Component{

T100PainterTransverter::T100PainterTransverter()
    :T100StateTransverter()
{
    //ctor
}

T100PainterTransverter::~T100PainterTransverter()
{
    //dtor
}

T100BOOL T100PainterTransverter::Change(T100State* state)
{

}

T100BOOL T100PainterTransverter::Change(T100WORD state)
{
    switch(state){
    case T100Painter::T100PAINTER_STATE_NONE:
        {
            m_current   = state;
            m_state     = T100NULL;
        }
        break;
    case T100Painter::T100PAINTER_STATE_ALONE:
        {
            if(!m_alone){
                m_alone = T100NEW T100Painter::T100StateAlone();
            }
            m_current   = state;
            m_state     = m_alone;
        }
        break;
    case T100Painter::T100PAINTER_STATE_EMBED:
        {
            if(!m_embed){
                m_embed = T100NEW T100Painter::T100StateEmbed();
            }
            m_current   = state;
            m_state     = m_embed;
        }
        break;
    default:
        return T100FALSE;
    }
    return T100TRUE;
}

T100Painter::T100PainterState* T100PainterTransverter::GetCurrent()
{
    return m_state;
}

}
