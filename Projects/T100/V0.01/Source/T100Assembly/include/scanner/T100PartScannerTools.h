#ifndef T100PARTSCANNERTOOLS_H
#define T100PARTSCANNERTOOLS_H

#include "T100ByteScanner.h"
#include "T100CharScanner.h"
#include "T100StringScanner.h"
#include "T100KeywordScanner.h"
#include "T100SentenceScanner.h"
#include "T100SegmentScanner.h"
#include "T100PartScanner.h"


class T100PartScannerTools
{
    public:
        T100PartScannerTools();
        virtual ~T100PartScannerTools();

        T100PartScanner*        create(T100WSTRING);

        T100BOOL                close();

        T100VOID                destroy();

    protected:

    private:
        T100ByteScanner*        m_byte_scanner              = T100NULL;
        T100CharScanner*        m_char_scanner              = T100NULL;
        T100StringScanner*      m_string_scanner            = T100NULL;
        T100KeywordScanner*     m_keyword_scanner           = T100NULL;
        T100SentenceScanner*    m_sentence_scanner          = T100NULL;
        T100SegmentScanner*     m_segment_scanner           = T100NULL;
        T100PartScanner*        m_part_scanner              = T100NULL;

};

#endif // T100PARTSCANNERTOOLS_H
