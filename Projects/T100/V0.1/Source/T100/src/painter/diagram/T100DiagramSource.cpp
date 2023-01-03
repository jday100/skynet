#include "T100DiagramSource.h"

#include "T100DiagramTransducerTarget.h"

namespace T100Painter{

T100DiagramSource::T100DiagramSource()
    :T100DiagramSourceBase()
{
    //ctor
}

T100DiagramSource::~T100DiagramSource()
{
    //dtor
}

T100WORD T100DiagramSource::getSign()
{
    return m_sign;
}

T100WORD T100DiagramSource::getType()
{
    return m_type;
}

T100WORD T100DiagramSource::getVersion()
{
    return m_version;
}

T100BOOL T100DiagramSource::serialize()
{
    T100BOOL                result      = T100FALSE;
    T100DIAGRAM_HEAD*       head        = T100NULL;

    head = m_diagram->getHead();
    if(head){
        result = m_target->setWORD(head->COMMON.SIGN);
        if(!result)return T100FALSE;

        result = m_target->setWORD(head->TYPE);
        if(!result)return T100FALSE;

        result = m_target->setWORD(head->VERSION);

    }

    return result;
}

T100BOOL T100DiagramSource::deserialize()
{
    T100BOOL        result          = T100FALSE;

    if(m_diagram){
        result = m_target->getWORD(m_diagram->getHead()->COMMON.SIGN);
        if(!result)return T100FALSE;

        result = m_target->getWORD(m_diagram->getHead()->TYPE);
        if(!result)return T100FALSE;

        result = m_target->getWORD(m_diagram->getHead()->VERSION);
    }else{
        result = m_target->getWORD(m_sign);
        if(!result)return T100FALSE;

        result = m_target->getWORD(m_type);
        if(!result)return T100FALSE;

        result = m_target->getWORD(m_version);
    }

    return result;
}

}
