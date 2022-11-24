#include "T100VariableParser.h"

#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100VariableParser::T100VariableParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100VariableParser::~T100VariableParser()
{
    //dtor
}

T100BOOL T100VariableParser::parse(T100OPERATOR& op)
{
    op.NAME         = getParent()->m_item->value;
    op.DATA_TYPE    = T100DATA_VARIABLE;
    op.PREFIX_TYPE  = getParent()->m_type;

    return getParent()->getBracketsParser().parse(op);
}

}
