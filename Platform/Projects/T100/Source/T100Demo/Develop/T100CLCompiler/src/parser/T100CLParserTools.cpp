#include "T100CLParserTools.h"

T100CLParserTools::T100CLParserTools()
{
    //ctor
}

T100CLParserTools::~T100CLParserTools()
{
    //dtor
}

T100BOOL T100CLParserTools::create(T100CLSourceParser*& source, T100CLFileParser*& file)
{
    T100CLFileParser*           file_parser         = T100NULL;
    T100CLByteParser*           byte_parser         = T100NULL;
    T100CLCharParser*           char_parser         = T100NULL;
    T100CLStringParser*         string_parser       = T100NULL;
    T100CLKeywordParser*        keyword_parser      = T100NULL;
    T100CLSentenceParser*       sentence_parser     = T100NULL;
    T100CLSegmentParser*        segment_parser      = T100NULL;
    T100CLSourceParser*         source_parser       = T100NULL;

    file_parser     = T100NEW T100CLFileParser();

    byte_parser     = T100NEW T100CLByteParser();

    char_parser     = T100NEW T100CLCharParser();

    string_parser   = T100NEW T100CLStringParser();

    keyword_parser  = T100NEW T100CLKeywordParser();

    sentence_parser = T100NEW T100CLSentenceParser();

    segment_parser  = T100NEW T100CLSegmentParser();

    source_parser   = T100NEW T100CLSourceParser();
    if(source_parser){
        source_parser->setSource(segment_parser);
    }

    source  = source_parser;
    file    = file_parser;
}
