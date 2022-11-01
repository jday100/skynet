#include "T100FontFileReader.h"

#include "T100String32Tools.h"
#include "T100FontFile.h"
#include "T100Font.h"
#include "T100DataStructureTools.h"


namespace T100Component{

T100FontFileReader::T100FontFileReader(T100FontFile* file, T100Font* font)
    :T100Library::T100FileReader(file->getName()),
    m_file(file), m_font(font)
{
    //ctor
}

T100FontFileReader::~T100FontFileReader()
{
    //dtor
}

T100BOOL T100FontFileReader::load()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;
    T100BOOL        flag            = T100FALSE;

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
        flag = T100TRUE;
    }

    value = read_head();
    if(!value){
        result = T100FALSE;
    }

    T100FONTFILE_ROW_VECTOR     rows;

    if(result){
        T100FONTFILE_ROW*       row             = T100NULL;
        T100INT                 i;

        for(i=0; i<m_row_size; i++){
            row     = T100NEW T100FONTFILE_ROW();
            value   = read_row(row);
            if(value){
                rows.push_back(row);

                m_font->appendRow(row);
            }else{
                result = T100FALSE;
                break;
            }
        }
    }

    if(result){
        T100FONTFILE_ROW*       row             = T100NULL;
        T100WORD                data[m_length];
        T100WORD                length;
        T100INT                 i;
        T100WORD                total;
        T100WORD                index;
        T100WORD                key;
        T100WORD_VECTOR*        font            = T100NULL;

        length = m_length;

        for(i=0; i<m_row_size; i++){
            row = rows.at(i);
            if(row){
                key     = row->BEGIN;
                total   = row->LENGTH;

                for(index=0; index<total; index++){
                    value = read_item(data, length);
                    if(value){
                        if(!m_font->unwind(key, data, length)){
                            return T100FALSE;
                        }
                        key++;
                    }else{
                        result = T100FALSE;
                        break;
                    }
                }

                if(!result)break;
            }
        }
    }

    if(flag){
        value = close();
        if(!value){
            result = T100FALSE;
        }
    }

    if(!result){
        for(T100FONTFILE_ROW* item : rows){
            if(item){
                T100SAFE_DELETE(item);
            }
        }
    }

    return result;
}

T100BOOL T100FontFileReader::read_head()
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

    data        = (T100WORD*)&head;
    length      = sizeof(head) / 4;

    if(!read(data, length)){
        return T100FALSE;
    }

    m_font->setName(T100Library::T100String32Tools::to_string32(head.FONT_NAME, 128));
    m_font->setWidth(head.FONT_WIDTH);
    m_font->setHeight(head.FONT_HEIGHT);
    m_font->setLength(head.FONT_LENGTH);
    m_font->setRowSize(head.ROW_SIZE);

    m_length    = head.FONT_LENGTH;
    m_row_size  = head.ROW_SIZE;

    return T100TRUE;
}

T100BOOL T100FontFileReader::read_row(T100FONTFILE_ROW* row)
{
    if(m_row_current >= m_row_size){
        return T100FALSE;
    }

    T100WORD*       data;
    T100WORD        length;

    data    = (T100WORD*)row;
    length  = sizeof(T100FONTFILE_ROW) / 4;

    if(!read(data, length)){
        return T100FALSE;
    }

    m_row_current++;

    return T100TRUE;
}

T100BOOL T100FontFileReader::read_item(T100WORD* data, T100WORD length)
{
    T100WORD        result;

    result = length;

    if(!read(data, result)){
        return T100FALSE;
    }

    m_item_current++;

    return T100TRUE;
}

}
