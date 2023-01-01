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

T100BOOL T100ElementSource::serialize()
{
    T100BOOL        result          = T100FALSE;

    result = m_target->setWORD(m_element->getType());

    return result;
}

T100BOOL T100ElementSource::deserialize()
{

}

}
