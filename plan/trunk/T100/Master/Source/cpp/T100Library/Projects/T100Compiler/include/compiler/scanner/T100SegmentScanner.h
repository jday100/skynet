#ifndef T100SEGMENTSCANNER_H
#define T100SEGMENTSCANNER_H

#include "T100SegmentToken.h"
#include "T100SentenceScanner.h"

namespace T100LIBRARY{

class T100SegmentScanner : public T100LeafScanner
{
    public:
        T100SegmentScanner();
        virtual ~T100SegmentScanner();

        virtual T100VOID                SetSource(T100LeafScanner*);
        virtual T100LeafScanner*        GetSource();

        virtual T100BOOL                Next(T100LeafState&, T100LeafToken&);

    protected:
        T100LeafState*                  m_state         = T100NULL;
        T100SegmentToken*               m_token         = T100NULL;
        T100SentenceToken               m_item;

        virtual T100BOOL                Run();

    private:
        T100SentenceScanner*            m_scanner       = T100NULL;
};

}

#endif // T100SEGMENTSCANNER_H
