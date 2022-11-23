#include "T100SentenceBase.h"

#include "T100SentenceScanner.h"

namespace T100SentenceBase{

T100SentenceBase::T100SentenceBase(T100Assembly::T100SentenceScanner* scanner)
    :m_scanner(scanner),
    m_operator_parser(this),
    m_register_parser(this),
    m_expression_parser(this),
    m_variable_parser(this),
    m_label_parser(this)
{
    //ctor
}

T100SentenceBase::~T100SentenceBase()
{
    //dtor
}

T100BOOL T100SentenceBase::read()
{

}

T100BOOL T100SentenceBase::clear()
{
    m_type  = P_NONE;
    m_scanner->clear();
    return T100TRUE;
}

T100BOOL T100SentenceBase::append()
{
    return m_scanner->append();
}

T100VOID T100SentenceBase::setLoaded(T100BOOL value)
{
    m_scanner->setLoaded(value);
}

T100BOOL T100SentenceBase::isLoaded()
{
    return m_scanner->isLoaded();
}

T100OperatorParser& T100SentenceBase::getOperatorParser()
{
    return m_operator_parser;
}

T100RegisterParser& T100SentenceBase::getRegisterParser()
{
    return m_register_parser;
}

T100ExpressionParser& T100SentenceBase::getExpressionParser()
{
    return m_expression_parser;
}

T100VariableParser& T100SentenceBase::getVariableParser()
{
    return m_variable_parser;
}

T100LabelParser& T100SentenceBase::getLabelParser()
{
    return m_label_parser;
}

}
