#include "T100ElementSource.h"

#include "T100ElementTransducerTarget.h"

namespace T100Painter{

T100ElementSource::T100ElementSource()
    :T100ElementSourceBase()
{
    //ctor
}

T100ElementSource::~T100ElementSource()
{
    //dtor
}

T100WORD T100ElementSource::getType()
{
    return m_type;
}

T100BOOL T100ElementSource::serialize()
{
    T100BOOL        result          = T100FALSE;

    result = m_target->setWORD(m_element->getType());

    return result;
}

T100BOOL T100ElementSource::deserialize()
{
    T100BOOL        result          = T100FALSE;

    if(m_element){
        result = m_target->getWORD(m_element->m_type);
    }else{
        result = m_target->getWORD(m_type);
    }

    return result;
}

}
