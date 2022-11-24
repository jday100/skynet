#ifndef T100SENTENCE_H
#define T100SENTENCE_H

#include <atomic>
#include "T100OrderTypes.h"
#include "T100AssemblyCommon.h"
#include "T100BuildInfo.h"
#include "T100SentenceToken.h"
#include "T100KeywordToken.h"

namespace T100Assembly{
class T100SentenceScanner;

class T100Sentence
{
    public:
        T100Sentence(T100SentenceScanner*);
        virtual ~T100Sentence();

        T100TOKEN_TYPE              type            = T100TOKEN_NONE;
        T100STRING                  value;
        T100SentenceToken*          m_token         = T100NULL;
        T100KeywordToken*           m_item          = T100NULL;

        T100BOOL                    read();
        T100BOOL                    clear();
        T100BOOL                    append();

        T100VOID                    setLoaded(T100BOOL);
        T100BOOL                    isLoaded();

        virtual T100BOOL            parse() = 0;

        virtual T100BOOL            build(T100BuildInfo*) = 0;

    protected:
        T100BOOL                    parseOperator(T100Component::T100OPERATOR&);
        T100BOOL                    parseOperator(T100Component::T100OPERATOR_COMPLEXUS&);
        T100BOOL                    parseOperator(T100Component::T100OPERATOR_BINOCULAR&);
        T100BOOL                    parseComplexus(T100Component::T100OPERATOR_COMPLEXUS&);

        T100BOOL                    parseNumber(T100Component::T100OPERATOR&);
        T100BOOL                    parseRegister(T100Component::T100OPERATOR&);
        T100BOOL                    parseExpression(T100Component::T100OPERATOR&);
        T100BOOL                    parseVariable(T100Component::T100OPERATOR&);
        T100BOOL                    parseLabel(T100Component::T100OPERATOR&);
        T100BOOL                    parseBrackets(T100Component::T100OPERATOR&);
        T100BOOL                    parseBrace(T100Component::T100OPERATOR&, T100Component::T100OPERATOR&);

    protected:
        T100BOOL                    buildOperator(T100BuildInfo*, T100Component::T100OPERATOR&, T100Component::T100OPERATOR_BUILD&);
        T100BOOL                    buildOperator(T100BuildInfo*, T100Component::T100OPERATOR_COMPLEXUS&, T100Component::T100OPERATOR_BUILD&);
        T100BOOL                    buildOperator(T100BuildInfo*, T100Component::T100OPERATOR_BINOCULAR&, T100Component::T100OPERATOR_INFO&);
        T100BOOL                    buildComplexus(T100BuildInfo*, T100Component::T100OPERATOR_COMPLEXUS&, T100Component::T100OPERATOR_BUILD&);

        T100BOOL                    buildInfo(T100Component::T100ORDER_TYPE, T100BuildInfo*, T100Component::T100OPERATOR_INFO&);

    protected:
        T100BOOL                    getProcedureOffset(T100BuildInfo*, T100STRING, T100WORD&);
        T100BOOL                    createPartInfo(T100STRING);

        virtual T100VOID            log();

    protected:

        std::atomic_bool*           m_loaded        = T100NULL;

        T100Component::T100SYMBOL_TYPE             m_type          = T100Component::S_NONE;

        T100VOID                    create();
        T100VOID                    destroy();



    private:
        T100SentenceScanner*        m_scanner       = T100NULL;

};

}

#endif // T100SENTENCE_H
