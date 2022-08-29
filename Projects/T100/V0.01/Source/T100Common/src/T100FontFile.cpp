#include "T100FontFile.h"

#include <cstring>
#include "T100Unicode.h"


T100FontFile::T100FontFile(T100String file)
    :T100File(file.to_wstring())
{
    //ctor
}

T100FontFile::~T100FontFile()
{
    //dtor
}

T100VOID T100FontFile::setFontName(T100String name)
{
    m_font_name = name;
}

T100String T100FontFile::getFontName()
{
    return m_font_name;
}

T100VOID T100FontFile::setFontWidth(T100WORD width)
{
    m_font_width = width;
}

T100WORD T100FontFile::getFontWidth()
{
    return m_font_width;
}

T100VOID T100FontFile::setFontHeight(T100WORD height)
{
    m_font_height = height;
}

T100WORD T100FontFile::getFontHeight()
{
    return m_font_height;
}

T100VOID T100FontFile::setRowSize(T100WORD size)
{
    m_row_size = size;
}

T100WORD T100FontFile::getRowSize()
{
    return m_row_size;
}

T100FontFileReader* T100FontFile::getReader(T100Font* font)
{
    return T100NEW T100FontFileReader(this, font);
}

T100FontFileWriter* T100FontFile::getWriter(T100Font* font)
{
    return T100NEW T100FontFileWriter(this, font);
}
