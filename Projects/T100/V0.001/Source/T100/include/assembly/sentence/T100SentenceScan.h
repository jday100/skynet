#ifndef T100SENTENCESCAN_H
#define T100SENTENCESCAN_H

#include "T100KeywordScan.h"
#include "T100SentenceToken.h"


class T100SentenceScan : public T100Scan
{
    friend class T100Sentence;
    public:
        T100SentenceScan();
        virtual ~T100SentenceScan();

        T100BOOL                next(IToken&);
        T100BOOL                open(T100String&);
        T100BOOL                close();

    protected:
        T100SentenceToken*      m_token             = T100NULL;
        T100KeywordToken        m_item;

        T100SentenceToken*      getToken();
        T100KeywordToken*       getItem();

        T100BOOL                run();
        T100BOOL                append();
        T100BOOL                read();

        T100VOID                nextLine();

        T100BOOL                parseOrder();
        T100BOOL                parseTail();

    private:
        T100KeywordScan*        m_scan              = T100NULL;
        T100Sentence*           m_sentence          = T100NULL;

};

#endif // T100SENTENCESCAN_H
