#include "T100Font.h"

#include "T100TestTools.h"
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

T100VOID T100Font::setLength(T100WORD length)
{
    m_length = length;
}

T100WORD T100Font::getLength()
{
    return m_length;
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

    reader = font.getReader(this);
    if(!reader){
        return T100FALSE;
    }

    if(!reader->load()){
        return T100FALSE;
    }

    T100SAFE_DELETE(reader);

    return T100TRUE;
}

/*
T100BOOL T100Font::load(T100String file)
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;
    T100FontFile            font(file);
    T100FontFileReader*     reader          = T100NULL;

    T100FONTFILE_ROW_VECTOR     rows;

    reader = font.getReader(this);
    if(!reader){
        return T100FALSE;
    }

    value = reader->read_head();
    if(!value){
        result = T100FALSE;
    }

    T100FONTFILE_ROW*       row;
    T100INT                 i;

    if(result){
        for(i=0;i<m_row_size;i++){
            row     = T100NEW T100FONTFILE_ROW();
            value   = reader->read_row(row);
            if(!value){
                result = T100FALSE;
                break;
            }else{
                rows.push_back(row);
            }
        }
    }

    if(result){
        T100FONTFILE_ROW*       row         = T100NULL;
        T100WORD*               data        = T100NULL;
        T100WORD                length;
        T100INT                 i;
        T100WORD                total;
        T100WORD                index;

        length = m_length;

        for(i=0;i<m_row_size;i++){
            row = rows.at(i);
            if(row){
                total = row->LENGTH;

                for(index=0;index<total;index++){
                    value = reader->read_item(data, length);
                    if(!value){
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
*/

T100BOOL T100Font::setFont(T100WORD key, T100FONT_DATA_VECTOR* font)
{
    m_fonts[key] = font;
    return T100TRUE;
}

T100BOOL T100Font::getFont(T100WORD key, T100FONT_DATA_VECTOR*& font)
{
    font = m_fonts[key];

    T100FONT_DATA_VECTOR& temp = *font;

    T100TestTools::Print(temp);

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

T100BOOL T100Font::unwind(T100WORD code, T100WORD* data, T100HWORD length)
{
    T100BOOL            result      = T100TRUE;
    T100BOOL            value;

    T100FONT_DATA_VECTOR*   font;
    T100WORD                word;

    if(!data || 0 == length){
        return T100FALSE;
    }

    font = T100NEW T100FONT_DATA_VECTOR;

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
        T100SAFE_DELETE(font);
    }else{
        m_fonts[code] = font;
    }

    return result;
}

T100BOOL T100Font::unwind(T100WORD data, T100FONT_DATA_VECTOR* font)
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
