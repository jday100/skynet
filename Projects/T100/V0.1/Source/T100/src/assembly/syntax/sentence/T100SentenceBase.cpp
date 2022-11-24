#include "T100SentenceBase.h"

#include "T100SentenceScanner.h"

namespace T100SentenceBase{

T100SentenceBase::T100SentenceBase(T100Assembly::T100SentenceScanner* scanner)
    :T100Assembly::T100Sentence(scanner),
    m_scanner(scanner),
    m_operator_parser(this),
    m_register_parser(this),
    m_expression_parser(this),
    m_variable_parser(this),
    m_label_parser(this),
    m_brackets_parser(this),
    m_brace_parser(this),
    m_operator_builder(this),
    m_complexus_builder(this),
    m_binocular_builder(this),
    m_double_builder(this)
{
    //ctor
}

T100SentenceBase::~T100SentenceBase()
{
    //dtor
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

T100BracketsParser& T100SentenceBase::getBracketsParser()
{
    return m_brackets_parser;
}

T100BraceParser& T100SentenceBase::getBraceParser()
{
    return m_brace_parser;
}


T100OperatorBuilder& T100SentenceBase::getOperatorBuilder()
{
    return m_operator_builder;
}

T100ComplexusBuilder& T100SentenceBase::getComplexusBuilder()
{
    return m_complexus_builder;
}

T100BinocularBuilder& T100SentenceBase::getBinocularBuilder()
{
    return m_binocular_builder;
}

T100DoubleBuilder& T100SentenceBase::getDoubleBuilder()
{
    return m_double_builder;
}

}
