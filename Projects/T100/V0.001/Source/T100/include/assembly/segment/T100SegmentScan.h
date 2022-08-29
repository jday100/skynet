#ifndef T100SEGMENTSCAN_H
#define T100SEGMENTSCAN_H

#include "T100SentenceScan.h"
#include "T100SegmentToken.h"


class T100SegmentScan : public T100Scan
{
    public:
        T100SegmentScan();
        virtual ~T100SegmentScan();

        T100BOOL                next(IToken&);
        T100BOOL                open(T100String&);
        T100BOOL                close();

    protected:
        T100SegmentToken*       m_token             = T100NULL;
        T100SentenceToken       m_item;

        T100SegmentToken*       getToken();
        T100SentenceToken*      getItem();

        T100BOOL                run();
        T100BOOL                append();
        T100BOOL                read();

    private:
        T100SentenceScan*       m_scan              = T100NULL;
};

#endif // T100SEGMENTSCAN_H
