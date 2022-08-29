#ifndef T100SENTENCESCANNER_H
#define T100SENTENCESCANNER_H

#include "T100KeywordScanner.h"
#include "T100SentenceToken.h"


class T100SentenceScanner : public T100Scanner
{
    friend class T100Sentence;
    public:
        T100SentenceScanner();
        virtual ~T100SentenceScanner();

        T100VOID                setSource(T100Scanner*);
        T100Scanner*            getSource();

        T100BOOL                next(T100Token&);


    protected:
        T100SentenceToken*      m_token         = T100NULL;
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
        T100KeywordScanner*     m_scanner       = T100NULL;
        T100Sentence*           m_sentence      = T100NULL;

};

#endif // T100SENTENCESCANNER_H
