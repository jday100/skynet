#ifndef T100SENTENCEBASE_H
#define T100SENTENCEBASE_H

#include <atomic>
#include "T100OrderTypes.h"
#include "T100AssemblyCommon.h"
#include "T100SentenceCommon.h"
#include "T100SentenceToken.h"
#include "T100KeywordToken.h"
#include "T100BuildInfo.h"

#include "T100BinocularParser.h"
#include "T100ComplexusParser.h"
#include "T100OperatorParser.h"

#include "T100RegisterParser.h"
#include "T100NumberParser.h"
#include "T100ExpressionParser.h"

#include "T100BracketsParser.h"
#include "T100BraceParser.h"

#include "T100VariableParser.h"
#include "T100LabelParser.h"


#include "T100Sentence.h"

#include "T100OperatorBuilder.h"
#include "T100ComplexusBuilder.h"
#include "T100BinocularBuilder.h"
#include "T100DoubleBuilder.h"

namespace T100Assembly{
class T100SentenceScanner;
}

namespace T100SentenceBase{

class T100SentenceBase : public T100Assembly::T100Sentence
{
    public:
        T100SentenceBase(T100Assembly::T100SentenceScanner*);
        virtual ~T100SentenceBase();

        T100PREFIX_TYPE             m_type          = P_NONE;

    public:
        T100OperatorParser&         getOperatorParser();
        T100RegisterParser&         getRegisterParser();
        T100ExpressionParser&       getExpressionParser();

        T100VariableParser&         getVariableParser();
        T100LabelParser&            getLabelParser();

        T100BracketsParser&         getBracketsParser();
        T100BraceParser&            getBraceParser();

    public:
        T100OperatorBuilder&        getOperatorBuilder();
        T100ComplexusBuilder&       getComplexusBuilder();
        T100BinocularBuilder&       getBinocularBuilder();
        T100DoubleBuilder&          getDoubleBuilder();

    private:
        T100Assembly::T100SentenceScanner*          m_scanner           = T100NULL;

        T100OperatorParser                          m_operator_parser;

        T100RegisterParser                          m_register_parser;

        T100ExpressionParser                        m_expression_parser;

        T100VariableParser                          m_variable_parser;
        T100LabelParser                             m_label_parser;

        T100BracketsParser                          m_brackets_parser;
        T100BraceParser                             m_brace_parser;

    private:
        T100OperatorBuilder                         m_operator_builder;
        T100ComplexusBuilder                        m_complexus_builder;
        T100BinocularBuilder                        m_binocular_builder;
        T100DoubleBuilder                           m_double_builder;

};

}

#endif // T100SENTENCEBASE_H
