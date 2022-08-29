#include "T100Font.h"

#include "T100FontFileReader.h"


T100Font::T100Font()
    :m_rows()
{
    //ctor
}

T100Font::~T100Font()
{
    //dtor
}

T100VOID T100Font::setName(T100String name)
{
    m_name = name;
}

T100String T100Font::getName()
{
    return m_name;
}

T100VOID T100Font::setWidth(T100WORD width)
{
    m_width = width;
}

T100WORD T100Font::getWidth()
{
    return m_width;
}

T100VOID T100Font::setHeight(T100WORD height)
{
    m_height = height;
}

T100WORD T100Font::getHeight()
{
    return m_height;
}

T100BOOL T100Font::setRowSize(T100WORD size)
{
    m_row_size = size;
    return T100TRUE;
}

T100WORD T100Font::getRowSize()
{
    return m_row_size;
}

T100BOOL T100Font::load(T100String file)
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;
    T100FontFile            font(file);
    T100FontFileReader*     reader          = T100NULL;


    T100FONTFILE_ROW_VECTOR     rows;

    //value = font.open(T100FILE_READ);

    reader = font.getReader(this);
    if(!reader){
        return T100FALSE;
    }

    reader->read_head();


}

T100BOOL T100Font::setFont(T100WORD key, T100FONT_DATA_VECTOR* font)
{
    m_fonts[key] = font;
    return T100TRUE;
}

T100BOOL T100Font::getFont(T100WORD key, T100FONT_DATA_VECTOR*& font)
{
    font = m_fonts[key];
    return T100TRUE;
}

T100BOOL T100Font::appendRow(T100FONTFILE_ROW* row)
{
    T100FONT_ROW*   item = T100NEW T100FONT_ROW();

    item->ROW   = row;

    m_rows.push_back(item);

    m_row_size = m_rows.size();

    return T100TRUE;
}

T100BOOL T100Font::removeRow(T100FONTFILE_ROW* row)
{
    T100FONT_ROW_VECTOR::iterator it;

    for(it = m_rows.begin(); it != m_rows.end(); it++){
        T100FONT_ROW* item = (*it);

        if(item){
            if(row == item->ROW){
                m_rows.erase(it);

                m_row_size = m_rows.size();
                return T100TRUE;
            }
        }
    }

    return T100FALSE;
}

T100FONT_ROW_VECTOR& T100Font::getFonts()
{
    return m_rows;
}
