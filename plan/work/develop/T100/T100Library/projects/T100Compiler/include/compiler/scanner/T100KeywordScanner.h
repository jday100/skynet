#ifndef T100KEYWORDSCANNER_H
#define T100KEYWORDSCANNER_H

#include "T100KeywordToken.h"
#include "T100StringScanner.h"

namespace T100LIBRARY{

class T100KeywordScanner : public T100LeafScanner
{
    public:
        T100KeywordScanner();
        virtual ~T100KeywordScanner();

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                  m_state         = T100NULL;
        T100KeywordToken*               m_token         = T100NULL;
        T100StringToken                 m_item;

        virtual T100BOOL                Run();

    private:
        T100StringScanner*              m_scanner       = T100NULL;
};

}

#endif // T100KEYWORDSCANNER_H
