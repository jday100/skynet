#include "T100DataParser.h"

T100DataParser::T100DataParser(T100FILE_DATA& file) :
    m_file(file),
    m_current(file.Data)
{
    //ctor
}

T100DataParser::~T100DataParser()
{
    //dtor
}

T100BYTE* T100DataParser::Get(T100UINT length)
{
    T100BYTE*   result      = T100NULL;

    result      = m_current;
    m_current   += length;

    return result;
}
