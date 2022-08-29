#ifndef T100FILESCAN_H
#define T100FILESCAN_H

#include "T100SegmentScan.h"
#include "T100FileToken.h"


class T100FileScan : public T100Scan
{
    public:
        T100FileScan();
        virtual ~T100FileScan();

        T100BOOL                next(IToken&);
        T100BOOL                open(T100String&);
        T100BOOL                close();

    protected:
        T100FileToken*          m_token             = T100NULL;
        T100SegmentToken        m_item;

        T100FileToken*          getToken();
        T100SegmentToken*       getItem();

        T100BOOL                run();
        T100BOOL                append();
        T100BOOL                read();

        T100String              getFile();

    private:
        T100SegmentScan*        m_scan              = T100NULL;
};

#endif // T100FILESCAN_H
