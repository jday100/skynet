#include "T100FontFile.h"

#include <cstring>
#include "T100Unicode.h"
#include "T100StringTools.h"


T100FontFile::T100FontFile(T100String file)
    :T100File(file)
{
    //ctor
}

T100FontFile::~T100FontFile()
{
    //dtor
}

T100BOOL T100FontFile::load()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100FONTFILE_ROW_VECTOR     rows;

    value = read_head();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        T100FONTFILE_ROW*   row;
        T100INTEGER         i;

        for(i = 0;i < m_row_size;i++){
            row = T100NEW T100FONTFILE_ROW;
            value = read_row(row);
            if(!value){
                result = T100FALSE;
                break;
            }else{
                rows.push_back(row);
            }
        }
    }

    if(result){
        T100FONTFILE_ROW*   row     = T100NULL;
        T100WORD*           data;
        T100WORD            length;
        T100INTEGER         i;
        T100WORD            total;
        T100WORD            index;

        length = m_length;

        for(i = 0;i < m_row_size;i++){
            row = rows.at(i);
            if(row){
                total = row->LENGTH;
                for(index = 0;index < total;index++){
                    value = read_item(data, length);
                    if(value){
                        //
                    }else{
                        result = T100FALSE;
                        break;
                    }
                }
                if(!result)break;
            }else{
                result = T100FALSE;
                break;
            }
        }
    }

    return result;
}

T100BOOL T100FontFile::save()
{
    return T100FALSE;
}

T100BOOL T100FontFile::exists()
{
    return T100File::exists();
}

T100BOOL T100FontFile::create()
{
    return T100File::create();
}

T100BOOL T100FontFile::remove()
{
    return T100File::remove();
}

T100BOOL T100FontFile::open(T100FILE_MODE mode)
{
    return T100File::open(mode);
}

T100BOOL T100FontFile::close()
{
    return T100File::close();
}

T100BOOL T100FontFile::opened()
{
    return T100File::opened();
}

T100BOOL T100FontFile::seek(T100DWORD seek)
{
    return T100File::seek(seek);
}

T100DWORD T100FontFile::length()
{
    return T100File::length();
}

T100BOOL T100FontFile::read_head()
{
    T100FONTFILE_HEAD       head;
    T100WORD*               data;
    T100WORD                length;

    if(!opened()){
        return T100FALSE;
    }

    if(!seek(0)){
        return T100FALSE;
    }

    data    = (T100WORD*)&head;
    length  = sizeof(head) / 4;

    if(!read(data, length)){
        return T100FALSE;
    }

    m_font_name     = T100StringTools::to_string(head.FONT_NAME, 128);
    m_font_width    = head.FONT_WIDTH;
    m_font_height   = head.FONT_HEIGHT;
    m_row_size      = head.ROW_SIZE;

    m_seek_row      = sizeof(T100FONTFILE_HEAD) / 4;

    return T100TRUE;
}

T100BOOL T100FontFile::write_head()
{
    T100FONTFILE_HEAD       head;
    T100WORD*               data;
    T100WORD                length;

    if(!opened()){
        return T100FALSE;
    }

    if(!seek(0)){
        return T100FALSE;
    }

    head.FILE_SIGN.SIGN = T100FILE_FONT;

    memset(head.FONT_NAME, 0, sizeof(head.FONT_NAME));
    if(!T100StringTools::copy(head.FONT_NAME, m_font_name.getRawData(), 128)){
        return T100FALSE;
    }

    head.FONT_WIDTH     = m_font_width;
    head.FONT_HEIGHT    = m_font_height;
    head.ROW_SIZE       = m_row_size;

    data    = (T100WORD*)&head;
    length  = sizeof(head) / 4;

    if(!write(data, length)){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100FontFile::read_row(T100FONTFILE_ROW* row)
{
    if(m_row_current >= m_row_size){
        return T100FALSE;
    }

    T100WORD*   data;
    T100WORD    length;

    data    = (T100WORD*)row;
    length  = sizeof(T100FONTFILE_ROW) / 4;

    if(!read(data, length)){
        return T100FALSE;
    }

    m_row_current++;

    return T100TRUE;
}

T100BOOL T100FontFile::write_row(T100FONTFILE_ROW* row)
{
    if(m_row_current >= m_row_size){
        return T100FALSE;
    }

    T100WORD*   data;
    T100WORD    length;

    if(!divide(row)){
        return T100FALSE;
    }

    data    = (T100WORD*)row;
    length  = sizeof(T100FONTFILE_ROW) / 4;

    if(!write(data, length)){
        return T100FALSE;
    }

    m_row_current++;

    return T100TRUE;
}

T100BOOL T100FontFile::read_item(T100WORD* data, T100WORD length)
{
    /*
    if(m_item_current >= m_item_current){
        return T100FALSE;
    }
    */

    T100WORD    temp;

    temp = length;
    if(!read(data, temp)){
        return T100FALSE;
    }

    m_item_current++;

    return T100TRUE;
}

T100BOOL T100FontFile::write_item(T100WORD* data, T100WORD length)
{
    /*
    if(m_item_current >= m_item_current){
        return T100FALSE;
    }
    */

    T100WORD    temp;

    temp = length;
    if(!write(data, temp)){
        return T100FALSE;
    }

    m_item_current++;

    return T100TRUE;
}

T100BOOL T100FontFile::allot(T100WORD*& data, T100HWORD& length)
{
    length = (m_font_width * m_font_height + 31) / 32;

    data = T100NEW T100WORD[length];

    return T100TRUE;
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

T100BOOL T100FontFile::divide(T100FONTFILE_ROW* row)
{
    if(!row){
        return T100FALSE;
    }

    T100WORD    head_length;
    T100WORD    rows_length;
    T100WORD    length;
    T100WORD    total;

    head_length     = sizeof(T100FONTFILE_HEAD) / 4;
    rows_length     = sizeof(T100FONTFILE_ROW) / 4 * m_row_size;

    length = (m_font_width * m_font_height + 31) / 32;

    total = head_length + rows_length + length * m_item_total;

    row->SEEK   = total;

    row->LENGTH = row->END - row->BEGIN + 1;

    m_item_total += row->LENGTH;

    return T100TRUE;
}
