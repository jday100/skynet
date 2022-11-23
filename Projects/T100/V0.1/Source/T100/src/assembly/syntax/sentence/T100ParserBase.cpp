#include "T100ParserBase.h"

namespace T100SentenceBase{

T100ParserBase::T100ParserBase(T100SentenceBase* base)
    :m_parent(base)
{
    //ctor
}

T100ParserBase::~T100ParserBase()
{
    //dtor
}

T100SentenceBase* T100ParserBase::getParent()
{
    return m_parent;
}

}
