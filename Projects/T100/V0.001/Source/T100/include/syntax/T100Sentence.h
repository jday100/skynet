#ifndef T100SENTENCE_H
#define T100SENTENCE_H

#include "T100Error.h"
#include "ISentence.h"
#include "T100String.h"
#include "T100OrderTypes.h"
#include "T100KeywordToken.h"
#include "T100SentenceToken.h"
class T100SentenceScan;
class T100FileData;


class T100Sentence : public ISentence
{
    public:
        T100Sentence(T100SentenceScan*);
        virtual ~T100Sentence();

        T100String                  data;

        virtual T100STDSTRING       tostring();


        T100BOOL                    run(T100FileData*);


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
        //

    protected:
        T100SentenceToken*          m_token;
        T100KeywordToken*           m_item;
        T100BOOL*                   m_loaded;
        T100SYMBOL_TYPE             m_type          = S_NONE;

        T100VOID                    create();
        T100VOID                    destroy();

        T100BOOL                    read();
        T100BOOL                    clear();
        T100BOOL                    append();

        T100VOID                    setLoaded(T100BOOL);
        T100BOOL                    isLoaded();

        virtual T100VOID            log();
        virtual T100BOOL            build(T100FileData*);

        T100BOOL                    buildOperator(T100FileData*, T100OPERATOR&, T100OPERATOR_BUILD&);
        T100BOOL                    buildOperator(T100FileData*, T100OPERATOR_COMPLEXUS&, T100OPERATOR_BUILD&);
        T100BOOL                    buildOperator(T100FileData*, T100OPERATOR_BINOCULAR&, T100OPERATOR_INFO&);
        T100BOOL                    buildComplexus(T100FileData*, T100OPERATOR_COMPLEXUS&, T100OPERATOR_BUILD&);

        T100BOOL                    buildInfo(T100ORDER_TYPE, T100FileData*, T100OPERATOR_INFO&);

    private:
        T100SentenceScan*           m_scan         = T100NULL;
};

#endif // T100SENTENCE_H
