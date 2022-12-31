#include "T100TransducerSource.h"

#include "T100TransducerTarget.h"

namespace T100Library{

T100TransducerSource::T100TransducerSource()
{
    //ctor
}

T100TransducerSource::~T100TransducerSource()
{
    //dtor
}

T100VOID T100TransducerSource::setTarget(T100TransducerTarget* target)
{
    m_target = target;
}

T100BOOL T100TransducerSource::serialize()
{
    return T100FALSE;
}

T100BOOL T100TransducerSource::deserialize()
{
    return T100FALSE;
}

}
