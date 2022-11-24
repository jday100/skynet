#include "T100BuilderBase.h"

namespace T100SentenceBase{

T100BuilderBase::T100BuilderBase(T100SentenceBase* base)
    :m_parent(base)
{
    //ctor
}

T100BuilderBase::~T100BuilderBase()
{
    //dtor
}

T100SentenceBase* T100BuilderBase::getParent()
{
    return m_parent;
}

}
