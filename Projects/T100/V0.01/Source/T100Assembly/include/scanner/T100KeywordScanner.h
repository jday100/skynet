#ifndef T100KEYWORDSCANNER_H
#define T100KEYWORDSCANNER_H

#include "T100StringScanner.h"
#include "T100KeywordToken.h"
#include "T100KeywordTable.h"


class T100KeywordScanner : public T100Scanner
{
    public:
        T100KeywordScanner();
        virtual ~T100KeywordScanner();

        T100VOID                setSource(T100Scanner*);
        T100Scanner*            getSource();

        T100BOOL                next(T100Token&);

    protected:
        T100KeywordToken*       m_token         = T100NULL;
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
        T100StringScanner*      m_scanner       = T100NULL;
        T100KeywordTable        m_keywords;

};

#endif // T100KEYWORDSCANNER_H
