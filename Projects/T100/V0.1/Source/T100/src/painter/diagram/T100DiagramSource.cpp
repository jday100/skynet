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

}

}
