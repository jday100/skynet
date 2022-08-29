#ifndef T100SEGMENTSCANNER_H
#define T100SEGMENTSCANNER_H

#include "T100SentenceScanner.h"
#include "T100SegmentToken.h"


class T100SegmentScanner : public T100Scanner
{
    public:
        T100SegmentScanner();
        virtual ~T100SegmentScanner();

        T100VOID                    setSource(T100Scanner*);
        T100Scanner*                getSource();

        T100BOOL                    next(T100Token&);

    protected:
        T100SegmentToken*           m_token             = T100NULL;
        T100SentenceToken           m_item;

        T100SegmentToken*           getToken();
        T100SentenceToken*          getItem();

        T100BOOL                    run();
        T100BOOL                    append();
        T100BOOL                    read();

    private:
        T100SentenceScanner*        m_scanner           = T100NULL;

};

#endif // T100SEGMENTSCANNER_H
