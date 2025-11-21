#include "T100TransducerSource.h"

T100TransducerSource::T100TransducerSource()
{
    //ctor
}

T100TransducerSource::~T100TransducerSource()
{
    //dtor
}

T100VOID T100TransducerSource::SetTarget(T100TransducerTarget* target)
{
    m_target = target;
}

T100BOOL T100TransducerSource::Serialize()
{
    return T100FALSE;
}

T100BOOL T100TransducerSource::Deserialize()
{
    return T100FALSE;
}
