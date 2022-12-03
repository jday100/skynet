#include "T100SentenceBase.h"

#include "T100SentenceScanner.h"

namespace T100SentenceBase{

T100SentenceBase::T100SentenceBase(T100Assembly::T100SentenceScanner* scanner)
    :T100Assembly::T100Sentence(scanner),
    m_scanner(scanner),
    m_operator_parser(this),
    m_complexus_parser(this),
    m_binocular_parser(this),
    m_register_parser(this),
    m_number_parser(this),
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

T100ComplexusParser& T100SentenceBase::getComplexusParser()
{
    return m_complexus_parser;
}

T100BinocularParser& T100SentenceBase::getBinocularParser()
{
    return m_binocular_parser;
}

T100RegisterParser& T100SentenceBase::getRegisterParser()
{
    return m_register_parser;
}

T100NumberParser& T100SentenceBase::getNumberParser()
{
    return m_number_parser;
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

T100BOOL T100SentenceBase::parseBrackets(::T100SentenceBase::T100OPERATOR& op)
{
    T100BOOL        result          = T100FALSE;

    setLoaded(T100FALSE);

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type){
    case T100Component::T100TOKEN_BR:
        {
            return T100TRUE;
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            m_token->type   = T100Component::T100TOKEN_ERROR;
            m_token->err    = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    case T100Component::T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CHAR_OPEN_BRACKETS:
        {
            result = read();
            if(!result){
                return T100FALSE;
            }

            if(T100Assembly::T100CONSTANT_INTEGER == m_item->type){
                T100WORD        value;

                value = std::stoll(m_item->value.to_wstring());

                result = read();
                if(!result){
                    return T100FALSE;
                }

                if(T100Assembly::T100CHAR_CLOSED_BRACKETS == m_item->type){
                    op.ISARRAY  = T100TRUE;
                    op.LENGTH   = value;

                    setLoaded(T100FALSE);
                    return T100TRUE;
                }else{
                    m_token->type   = T100Component::T100TOKEN_ERROR;
                    m_token->err    = T100Assembly::T100ERROR_SENTENCE;
                    //
                    return T100FALSE;
                }
            }else{
                m_token->type   = T100Component::T100TOKEN_ERROR;
                m_token->err    = T100Assembly::T100ERROR_SENTENCE;
                //
                return T100FALSE;
            }
        }
        break;
    default:
        return T100TRUE;
    }
    return T100FALSE;
}

T100Component::T100DATA_TYPE T100SentenceBase::getType(::T100SentenceBase::T100DATA_TYPE type)
{
    T100Component::T100DATA_TYPE        result;

    switch(type){
    case T100DATA_INTEGER:
        {
            result = T100Component::T100DATA_INTEGER;
        }
        break;
    default:
        result = T100Component::T100DATA_NONE;
    }

    return result;
}

}
