#ifndef T100SENTENCE_H
#define T100SENTENCE_H

#include "T100OrderTypes.h"
#include "T100AssemblyCommon.h"
#include "T100BuildInfo.h"
#include "T100SentenceToken.h"
#include "T100KeywordToken.h"
class T100SentenceScanner;


class T100Sentence
{
    public:
        T100Sentence(T100SentenceScanner*);
        virtual ~T100Sentence();

        T100TOKEN_TYPE              type        = T100TOKEN_NONE;
        T100STRING                  value;

        virtual T100BOOL            parse() = 0;

        virtual T100BOOL            build(T100BuildInfo*) = 0;

    protected:
        T100BOOL                    parseOperator(T100OPERATOR&);
        T100BOOL                    parseOperator(T100OPERATOR_COMPLEXUS&);
        T100BOOL                    parseOperator(T100OPERATOR_BINOCULAR&);
        T100BOOL                    parseComplexus(T100OPERATOR_COMPLEXUS&);

        T100BOOL                    parseNumber(T100OPERATOR&);
        T100BOOL                    parseRegister(T100OPERATOR&);
        T100BOOL                    parseExpression(T100OPERATOR&);
        T100BOOL                    parseVariable(T100OPERATOR&);
        T100BOOL                    parseLabel(T100OPERATOR&);
        T100BOOL                    parseBrackets(T100OPERATOR&);
        T100BOOL                    parseBrace(T100OPERATOR&, T100OPERATOR&);

    protected:
        T100BOOL                    buildOperator(T100BuildInfo*, T100OPERATOR&, T100OPERATOR_BUILD&);
        T100BOOL                    buildOperator(T100BuildInfo*, T100OPERATOR_COMPLEXUS&, T100OPERATOR_BUILD&);
        T100BOOL                    buildOperator(T100BuildInfo*, T100OPERATOR_BINOCULAR&, T100OPERATOR_INFO&);
        T100BOOL                    buildComplexus(T100BuildInfo*, T100OPERATOR_COMPLEXUS&, T100OPERATOR_BUILD&);

        T100BOOL                    buildInfo(T100ORDER_TYPE, T100BuildInfo*, T100OPERATOR_INFO&);

    protected:
        T100BOOL                    getProcedureOffset(T100BuildInfo*, T100String, T100WORD&);

    protected:
        T100SentenceToken*          m_token         = T100NULL;
        T100KeywordToken*           m_item          = T100NULL;
        std::atomic_bool*           m_loaded        = T100NULL;

        T100SYMBOL_TYPE             m_type          = S_NONE;


        T100VOID                    create();
        T100VOID                    destroy();

        T100BOOL                    read();
        T100BOOL                    clear();
        T100BOOL                    append();

        T100VOID                    setLoaded(T100BOOL);
        T100BOOL                    isLoaded();

    private:
        T100SentenceScanner*        m_scanner           = T100NULL;

};

#endif // T100SENTENCE_H
