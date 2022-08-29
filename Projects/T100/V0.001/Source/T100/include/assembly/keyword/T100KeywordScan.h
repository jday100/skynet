#ifndef T100KEYWORDSCAN_H
#define T100KEYWORDSCAN_H

#include "T100StringScan.h"
#include "T100KeywordToken.h"
#include "T100KeywordTable.h"


class T100KeywordScan : public T100Scan
{
    public:
        T100KeywordScan();
        virtual ~T100KeywordScan();

        T100BOOL                next(IToken&);
        T100BOOL                open(T100String&);
        T100BOOL                close();

    protected:
        T100KeywordToken*       m_token             = T100NULL;
        T100StringToken         m_item;

        T100KeywordToken*       getToken();
        T100StringToken*        getItem();

        T100BOOL                run();
        T100BOOL                append();
        T100BOOL                read();

        T100TOKEN_TYPE          classify();

        T100BOOL                parseUpper();
        T100BOOL                parseLower();
        T100BOOL                parseDigit();
        T100BOOL                parseQuotes();
        T100BOOL                parseSlash();

    private:
        T100StringScan*         m_scan              = T100NULL;
        T100KeywordTable        m_keywords;

};

#endif // T100KEYWORDSCAN_H
