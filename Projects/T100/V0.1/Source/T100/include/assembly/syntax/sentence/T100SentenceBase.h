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


namespace T100Assembly{
class T100SentenceScanner;
}

namespace T100SentenceBase{

class T100SentenceBase
{
    public:
        T100SentenceBase(T100Assembly::T100SentenceScanner*);
        virtual ~T100SentenceBase();

        T100TOKEN_TYPE              type            = T100TOKEN_NONE;
        T100STRING                  value;

        T100PREFIX_TYPE             m_type          = P_NONE;


        T100BOOL                    read();
        T100BOOL                    clear();
        T100BOOL                    append();

        T100VOID                    setLoaded(T100BOOL);
        T100BOOL                    isLoaded();

        virtual T100BOOL            parse() = 0;

        virtual T100BOOL            build(T100Assembly::T100BuildInfo*) = 0;

        T100Assembly::T100SentenceToken*            m_token         = T100NULL;
        T100Assembly::T100KeywordToken*             m_item          = T100NULL;

    protected:
        std::atomic_bool*           m_loaded        = T100NULL;


    public:
        T100OperatorParser&         getOperatorParser();
        T100RegisterParser&         getRegisterParser();
        T100ExpressionParser&       getExpressionParser();

        T100VariableParser&         getVariableParser();
        T100LabelParser&            getLabelParser();

    private:
        T100Assembly::T100SentenceScanner*          m_scanner           = T100NULL;

        T100OperatorParser                          m_operator_parser;

        T100RegisterParser                          m_register_parser;

        T100ExpressionParser                        m_expression_parser;

        T100VariableParser                          m_variable_parser;
        T100LabelParser                             m_label_parser;

};

}

#endif // T100SENTENCEBASE_H
