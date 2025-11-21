#ifndef T100SENTENCESCANNER_H
#define T100SENTENCESCANNER_H

#include "T100SentenceToken.h"
#include "T100KeywordScanner.h"

namespace T100LIBRARY{

class T100SentenceScanner : public T100LeafScanner
{
    public:
        T100SentenceScanner();
        virtual ~T100SentenceScanner();

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                  m_state         = T100NULL;
        T100SentenceToken*              m_token         = T100NULL;
        T100KeywordToken                m_item;

        virtual T100BOOL                Run();

    private:
        T100KeywordScanner*             m_scanner       = T100NULL;
};

}

#endif // T100SENTENCESCANNER_H
