#include "T100Font.h"

T100Font::T100Font()
{
    //ctor
}

T100Font::~T100Font()
{
    //dtor
}

T100BOOL T100Font::load(T100String file)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100FontFile    font(file);

    T100FONTFILE_ROW_VECTOR     rows;

    value = font.open(T100FILE_READ);
    if(!value){
        return T100FALSE;
    }

    value = font.read_head();
    if(value){
        if(0 == m_width && 0 == m_height){
            m_width     = font.getFontWidth();
            m_height    = font.getFontHeight();
        }else if(m_width == font.getFontWidth() && m_height == font.getFontHeight()){

        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    if(result){
        T100FONTFILE_ROW*   row;
        T100WORD            size;

        size = font.getRowSize();
        for(int i=0;i<size;i++){
            row = T100NEW T100FONTFILE_ROW;

            value = font.read_row(row);
            if(!value){
                clear(rows);
                result = T100FALSE;
                break;
            }
            rows.push_back(row);
        }
    }

    if(result){
        T100WORD*       data;
        T100HWORD       length;
        T100WORD        size;
        T100WORD        code;

        value = font.allot(data, length);
        if(value){
            for(auto row:rows){
                if(row){
                    value = font.seek(row->SEEK);
                    if(value){
                        size = row->LENGTH;
                        code = row->BEGIN;
                        for(int i=0;i<size;i++){
                            value = font.read_item(data, length);
                            if(value){
                                value = unwind(code, data, length);
                                if(!value){
                                    result = T100FALSE;
                                    break;
                                }
                                code++;
                            }else{
                                result = T100FALSE;
                                break;
                            }
                        }
                        if(result){
                            if(row->END + 1 == code){

                            }else{
                                result = T100FALSE;
                                break;
                            }
                        }else{
                            break;
                        }
                    }else{
                        result = T100FALSE;
                        break;
                    }
                }else{
                    result = T100FALSE;
                    break;
                }
            }
        }else{
            result = T100FALSE;
        }
        clear(rows);
    }

    value = font.close();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

/*
T100BOOL T100Font::load(T100String file)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;
    T100FontFile    font(file);

    value = font.open(T100FILE_READ);
    if(!value){
        return T100FALSE;
    }

    value = font.read_head();
    if(value){
        if(0 == m_width && 0 == m_height){
            m_width     = font.getFontWidth();
            m_height    = font.getFontHeight();
        }else if(m_width == font.getFontWidth() && m_height == font.getFontHeight()){

        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    if(result){
        T100FONTFILE_ROW    row;
        T100WORD*           data;
        T100HWORD           length;
        T100WORD            size;
        T100WORD            index;
        T100WORD            s, i;

        value = font.allot(data, length);
        if(value){
            size = font.getRowSize();
            for(index = 0;index < size; size++){
                value = font.read_row(&row);
                if(value){
                    s = row.LENGTH;
                    value = font.seek(row.SEEK);
                    if(value){
                        for(i = 0;i < s;i++){
                            value = font.read_item(data, length);
                            if(value){

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
                }else{
                    result = T100FALSE;
                    break;
                }
            }
        }else{
            result = T100FALSE;
        }
    }

    value = font.close();
    if(!value){
        result = T100FALSE;
    }

    return result;
}
*/

T100WORD T100Font::getWidth()
{
    return m_width;
}

T100WORD T100Font::getHeight()
{
    return m_height;
}

T100BOOL T100Font::getFont(T100WORD key, T100FONT_VECTOR*& font)
{
    font = m_fonts[key];
    return T100TRUE;
}

T100VOID T100Font::clear(T100FONTFILE_ROW_VECTOR& rows)
{
    for(auto row:rows){
        if(row){
            T100DELETE(row);
        }
    }

    rows.clear();
}

T100BOOL T100Font::unwind(T100WORD code, T100WORD* data, T100HWORD length)
{
    T100BOOL            result      = T100TRUE;
    T100BOOL            value;

    T100FONT_VECTOR*    font;
    T100WORD            word;

    if(!data || 0 == length){
        return T100FALSE;
    }

    font = T100NEW T100FONT_VECTOR;

    for(int i=0;i<length;i++){
        word = data[i];
        value = unwind(word, font);
        if(!value){
            result = T100FALSE;
            break;
        }
    }

    if(!result){
        font->clear();
        T100DELETE(font);
    }else{
        m_fonts[code] = font;
    }

    return result;
}

T100BOOL T100Font::unwind(T100WORD data, T100FONT_VECTOR* font)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    if(!font){
        return T100FALSE;
    }

    T100WORD_BITS   word;

    //test
    //data = 0xffffffff;

    word.WORD   = data;

    if(word.BYTE0.BIT0){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE0.BIT1){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE0.BIT2){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE0.BIT3){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    //
    if(word.BYTE0.BIT4){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE0.BIT5){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE0.BIT6){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE0.BIT7){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    //
    if(word.BYTE1.BIT0){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE1.BIT1){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE1.BIT2){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE1.BIT3){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    //
    if(word.BYTE1.BIT4){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE1.BIT5){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE1.BIT6){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE1.BIT7){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    //
    if(word.BYTE2.BIT0){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE2.BIT1){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE2.BIT2){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE2.BIT3){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    //
    if(word.BYTE2.BIT4){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE2.BIT5){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE2.BIT6){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE2.BIT7){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    //
    if(word.BYTE3.BIT0){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE3.BIT1){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE3.BIT2){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE3.BIT3){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    //
    if(word.BYTE3.BIT4){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE3.BIT5){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE3.BIT6){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }
    if(word.BYTE3.BIT7){
        font->push_back(0x00ffffff);
    }else{
        font->push_back(0);
    }

    return result;
}
