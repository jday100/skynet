#include "T100FontFileWriter.h"

#include <string.h>
#include "T100String32Tools.h"
#include "T100FontFile.h"
#include "T100Font.h"


T100FontFileWriter::T100FontFileWriter(T100FontFile* file, T100Font* font)
    :m_file(file), m_font(font),
    T100FileWriter(file->getName())
{
    //ctor
}

T100FontFileWriter::~T100FontFileWriter()
{
    //dtor
}

T100BOOL T100FontFileWriter::save()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    if(opened()){
        value = seek(0);
        if(!value){
            return T100FALSE;
        }
    }else{
        value = open();
        if(!value){
            return T100FALSE;
        }
    }

    if(0 >= m_font->getRowSize()){
        result = T100FALSE;
    }

    if(result){
        value = write_head();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        for(T100FONT_ROW* item : m_font->getFonts()){
            if(item){
                if(write_row(item->ROW)){

                }else{
                    result = T100FALSE;
                    break;
                }
            }else{
                result = T100FALSE;
                break;
            }
        }
    }

    if(result){
        for(T100FONT_ROW* item : m_font->getFonts()){
            for(T100FONT_DATA_VECTOR* data : *(item->FONTS)){
                if(data){
                    if(write_item(data->data(), data->size())){

                    }else{
                        result = T100FALSE;
                        goto ERROR;
                    }
                }else{
                    result = T100FALSE;
                    goto ERROR;
                }
            }
        }
    }
ERROR:

    value = close();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100FontFileWriter::write_head()
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
    if(!T100String32Tools::copy(head.FONT_NAME, m_file->getFontName().to_string().raw_data(), 128)){
        return T100FALSE;
    }

    head.FONT_WIDTH     = m_font->getWidth();
    head.FONT_HEIGHT    = m_font->getHeight();
    head.ROW_SIZE       = m_font->getRowSize();

    data    = (T100WORD*)&head;
    length  = sizeof(head) / 4;

    if(!write(data, length)){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100FontFileWriter::write_row(T100FONTFILE_ROW* row)
{
    if(m_row_current >= m_font->getRowSize()){
        return T100FALSE;
    }

    T100WORD*       data;
    T100WORD        length;

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

T100BOOL T100FontFileWriter::write_item(T100WORD* data, T100WORD length)
{
    T100WORD        result;

    result = length;
    if(!write(data, result)){
        return T100FALSE;
    }

    m_item_current++;

    return T100TRUE;
}

T100BOOL T100FontFileWriter::divide(T100FONTFILE_ROW* row)
{
    if(!row){
        return T100FALSE;
    }

    T100WORD        head_length;
    T100WORD        rows_length;
    T100WORD        length;
    T100WORD        total;

    head_length     = sizeof(T100FONTFILE_HEAD) / 4;
    rows_length     = sizeof(T100FONTFILE_ROW) / 4 * m_row_size;

    length = (m_font->getWidth() * m_font->getHeight() + 31) / 32;

    total = head_length + rows_length + length * m_item_total;

    row->SEEK   = total;

    row->LENGTH = row->END - row->BEGIN + 1;

    m_item_total += row->LENGTH;

    return T100TRUE;
}
