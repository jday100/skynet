#include "T100ProjectTransverter.h"

namespace T100Component{

T100ProjectTransverter::T100ProjectTransverter()
    :T100StateTransverter()
{
    //ctor
}

T100ProjectTransverter::~T100ProjectTransverter()
{
    //dtor
}

T100BOOL T100ProjectTransverter::Change(T100WORD state)
{
    switch(state){
    case T100PROJECT::T100PROJECT_STATE_NONE:
        {
            m_current   = state;
            m_state     = T100NULL;
        }
        break;
    case T100PROJECT::T100PROJECT_STATE_ALONE:
        {
            if(!m_alone){
                m_alone = T100NEW T100PROJECT::T100ProjectStateAlone();
            }
            m_current   = state;
            m_state     = m_alone;
        }
        break;
    case T100PROJECT::T100PROJECT_STATE_EMBED:
        {
            if(!m_embed){
                m_embed = T100NEW T100PROJECT::T100ProjectStateEmbed();
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

T100PROJECT::T100ProjectState* T100ProjectTransverter::GetCurrent()
{
    return m_state;
}

}
