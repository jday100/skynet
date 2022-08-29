#include "T100PartScannerTools.h"

T100PartScannerTools::T100PartScannerTools()
{
    //ctor
}

T100PartScannerTools::~T100PartScannerTools()
{
    //dtor
}

T100PartScanner* T100PartScannerTools::create(T100WSTRING file)
{
    if(file.empty()){
        return T100NULL;
    }

    m_byte_scanner      = T100NEW T100ByteScanner();
    if(m_byte_scanner){
        if(m_byte_scanner->open(file)){

        }else{
            return T100NULL;
        }
    }else{
        return T100NULL;
    }

    m_char_scanner      = T100NEW T100CharScanner();
    if(m_char_scanner){
        m_char_scanner->setSource(m_byte_scanner);
    }else{
        m_byte_scanner->close();

        T100SAFE_DELETE(m_byte_scanner);
        return T100NULL;
    }

    m_string_scanner    = T100NEW T100StringScanner();
    if(m_string_scanner){
        m_string_scanner->setSource(m_char_scanner);
    }else{
        m_byte_scanner->close();

        T100SAFE_DELETE(m_byte_scanner);
        T100SAFE_DELETE(m_char_scanner);
        return T100NULL;
    }

    m_keyword_scanner   = T100NEW T100KeywordScanner();
    if(m_keyword_scanner){
        m_keyword_scanner->setSource(m_string_scanner);
    }else{
        m_byte_scanner->close();

        T100SAFE_DELETE(m_byte_scanner);
        T100SAFE_DELETE(m_char_scanner);
        T100SAFE_DELETE(m_string_scanner);
        return T100NULL;
    }

    m_sentence_scanner  = T100NEW T100SentenceScanner();
    if(m_sentence_scanner){
        m_sentence_scanner->setSource(m_keyword_scanner);
    }else{
        m_byte_scanner->close();

        T100SAFE_DELETE(m_byte_scanner);
        T100SAFE_DELETE(m_char_scanner);
        T100SAFE_DELETE(m_string_scanner);
        T100SAFE_DELETE(m_keyword_scanner);
        return T100NULL;
    }

    m_segment_scanner   = T100NEW T100SegmentScanner();
    if(m_segment_scanner){
        m_segment_scanner->setSource(m_sentence_scanner);
    }else{
        m_byte_scanner->close();

        T100SAFE_DELETE(m_byte_scanner);
        T100SAFE_DELETE(m_char_scanner);
        T100SAFE_DELETE(m_string_scanner);
        T100SAFE_DELETE(m_keyword_scanner);
        T100SAFE_DELETE(m_sentence_scanner);
        return T100NULL;
    }

    m_part_scanner      = T100NEW T100PartScanner();
    if(m_part_scanner){
        m_part_scanner->setSource(m_segment_scanner);
    }else{
        m_byte_scanner->close();

        T100SAFE_DELETE(m_byte_scanner);
        T100SAFE_DELETE(m_char_scanner);
        T100SAFE_DELETE(m_string_scanner);
        T100SAFE_DELETE(m_keyword_scanner);
        T100SAFE_DELETE(m_sentence_scanner);
        T100SAFE_DELETE(m_segment_scanner);
        return T100NULL;
    }

    return m_part_scanner;
}

T100VOID T100PartScannerTools::destroy()
{
    T100SAFE_DELETE(m_byte_scanner);
    T100SAFE_DELETE(m_char_scanner);
    T100SAFE_DELETE(m_string_scanner);
    T100SAFE_DELETE(m_keyword_scanner);
    T100SAFE_DELETE(m_sentence_scanner);
    T100SAFE_DELETE(m_segment_scanner);
    T100SAFE_DELETE(m_part_scanner);
}

T100BOOL T100PartScannerTools::close()
{
    if(m_byte_scanner){
        return m_byte_scanner->close();
    }

    return T100FALSE;
}
