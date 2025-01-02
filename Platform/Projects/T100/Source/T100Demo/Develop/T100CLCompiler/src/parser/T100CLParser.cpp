#include "T100CLParser.h"

#include "T100CLSourceToken.h"
#include "T100CLParserTools.h"

T100CLParser::T100CLParser()
    :T100Parser()
{
    //ctor
    create();
}

T100CLParser::~T100CLParser()
{
    //dtor
    destroy();
}

T100VOID T100CLParser::create()
{
    T100BOOL            result;

    result  = T100CLParserTools::create(m_source, m_file);
}

T100VOID T100CLParser::destroy()
{
    T100SAFE_DELETE m_source;
    T100SAFE_DELETE m_file;
}

T100BOOL T100CLParser::parse(T100WString filename, T100ParserInfo& info)
{
    T100BOOL                result;
    T100State               state;
    T100CLSourceToken       token;

    result  = m_file->open(filename);
    if(result){
        while(m_source->next(state, token)){

        }
        result  = m_file->close();
    }

    return result;
}

