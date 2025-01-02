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
    if(byte_parser){
        byte_parser->setSource(file_parser);
    }

    char_parser     = T100NEW T100CLCharParser();
    if(char_parser){
        char_parser->setSource(byte_parser);
    }

    string_parser   = T100NEW T100CLStringParser();
    if(string_parser){
        string_parser->setSource(char_parser);
    }

    keyword_parser  = T100NEW T100CLKeywordParser();
    if(keyword_parser){
        keyword_parser->setSource(string_parser);
    }

    sentence_parser = T100NEW T100CLSentenceParser();
    if(sentence_parser){
        sentence_parser->setSource(keyword_parser);
    }

    segment_parser  = T100NEW T100CLSegmentParser();
    if(segment_parser){
        segment_parser->setSource(sentence_parser);
    }

    source_parser   = T100NEW T100CLSourceParser();
    if(source_parser){
        source_parser->setSource(segment_parser);
    }

    source  = source_parser;
    file    = file_parser;
}
