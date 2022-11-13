#include "T100ExecutableFileWriter.h"

#include <cstring>
#include "T100String.h"
#include "T100SegmentCode.h"
#include "T100SegmentData.h"

namespace T100Component{

T100ExecutableFileWriter::T100ExecutableFileWriter(T100STRING file)
    :T100Library::T100FileWriter(file.to_wstring())
{
    //ctor
}

T100ExecutableFileWriter::~T100ExecutableFileWriter()
{
    //dtor
}

T100BOOL T100ExecutableFileWriter::save(T100ExecutableInfo& info)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    m_info = &info;

    if(!opened()){
        value = open();
        if(!value){
            return T100FALSE;
        }
    }

    if(result){
        value = write_head();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = write_table();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = write_code();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = write_data();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = write_share();
        if(!value){
            result = T100FALSE;
        }
    }

    value = close();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_head()
{
    T100BOOL        result          = T100FALSE;

    T100WORD*       data            = T100NULL;
    T100WORD        length;

    if(create_head()){

    }else{
        return T100FALSE;
    }

    data    = (T100WORD*)&m_head;
    length  = (sizeof(T100EXECUTABLE_FILE_HEAD) + 3) / 4;

    result  = write(data, length);

    return result;
}

T100BOOL T100ExecutableFileWriter::write_table()
{
    T100BOOL        result          = T100FALSE;

    result = write_table(m_head.CODE_OFFSET, m_info->m_codes);
    if(!result){
        return T100FALSE;
    }

    result = write_table(m_head.DATA_OFFSET, m_info->m_datas);
    if(!result){
        return T100FALSE;
    }

    result = write_share_table(m_head.SHARE_CODE_OFFSET, m_info->m_share_codes);
    if(!result){
        return T100FALSE;
    }

    result = write_share_table(m_head.SHARE_DATA_OFFSET, m_info->m_share_datas);

    return result;
}

T100BOOL T100ExecutableFileWriter::write_code()
{
    T100BOOL        result          = T100TRUE;

    if(!m_info){
        return T100FALSE;
    }

    for(auto item : m_info->m_codes){
        if(item){
            result = write_segment((T100Assembly::T100Segment*)item);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_data()
{
    T100BOOL        result          = T100TRUE;

    if(!m_info){
        return T100FALSE;
    }

    for(auto item : m_info->m_datas){
        if(item){
            result = write_segment((T100Assembly::T100Segment*)item);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_share()
{
    T100BOOL        result          = T100TRUE;

    if(!m_info){
        return T100FALSE;
    }

    for(auto item : m_info->m_share_codes){
        if(item){
            result = write_segment((T100Assembly::T100Segment*)item);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    for(auto item : m_info->m_share_datas){
        if(item){
            result = write_segment((T100Assembly::T100Segment*)item);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_table(T100WORD offset, T100SEGMENT_CODE_VECTOR& codes)
{
    T100BOOL        result          = T100TRUE;

    T100EXECUTABLE_FILE_CODE        code;
    T100WORD        index           = 0;
    T100WORD        length          = 0;
    T100WORD*       data            = T100NULL;
    T100WORD        size            = 0;

    data = (T100WORD*)&code;

    for(auto item : codes){
        if(item){
            length = item->getLength();

            code.INDEX      = index;
            code.OFFSET     = offset;
            code.LENGTH     = length;

            size = (sizeof(T100EXECUTABLE_FILE_CODE) + 3) / 4;

            if(write(data, size)){
                index++;
                offset  += length;
                length  = 0;
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_table(T100WORD offset, T100SEGMENT_DATA_VECTOR& datas)
{
    T100BOOL        result          = T100TRUE;

    T100EXECUTABLE_FILE_DATA        data;
    T100WORD        index           = 0;
    T100WORD        length          = 0;
    T100WORD*       point           = T100NULL;
    T100WORD        size            = 0;

    point = (T100WORD*)&data;

    for(auto item : datas){
        if(item){
            length = item->getLength();

            data.INDEX      = index;
            data.OFFSET     = offset;
            data.LENGTH     = length;

            size = (sizeof(T100EXECUTABLE_FILE_DATA) + 3) / 4;

            if(write(point, size)){
                index++;
                offset  += length;
                length  = 0;
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_share_table(T100WORD offset, T100SEGMENT_CODE_VECTOR& codes)
{
    T100BOOL        result          = T100TRUE;

    T100WORD        index           = 0;
    T100WORD        length          = 0;
    T100WORD        location        = 0;
    T100WORD*       data            = T100NULL;
    T100WORD        size            = 0;

    for(auto item : codes){
        if(item){
            length      = item->getLength();
            location    = item->getLocation();

            data = &index;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = &offset;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = &length;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = &location;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = item->getName().to_string32().raw_data();
            size = item->getName().to_string32().raw_length();

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            index++;
            offset  += length;
            length  = 0;
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_share_table(T100WORD offset, T100SEGMENT_DATA_VECTOR& datas)
{
    T100BOOL        result          = T100TRUE;

    T100WORD        index           = 0;
    T100WORD        length          = 0;
    T100WORD        location        = 0;
    T100WORD*       data            = T100NULL;
    T100WORD        size            = 0;

    for(auto item : datas){
        if(item){
            length      = item->getLength();
            location    = item->getLocation();

            data = &index;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = &offset;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = &length;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = &location;
            size = 1;

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            data = item->getName().to_string32().raw_data();
            size = item->getName().to_string32().raw_length();

            if(write(data, size)){

            }else{
                return T100FALSE;
            }

            index++;
            offset  += length;
            length  = 0;
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::write_segment(T100Assembly::T100Segment* seg)
{
    T100BOOL        result          = T100FALSE;
    T100WORD*       data            = T100NULL;
    T100WORD        length;

    if(!seg){
        return T100FALSE;
    }

    data    = seg->getMem().data();
    length  = seg->getLength();

    result  = write(data, length);

    return result;
}

T100BOOL T100ExecutableFileWriter::create_head()
{
    T100BOOL        result          = T100FALSE;
    T100WORD        table           = 0;
    T100WORD        total           = 0;
    T100WORD        length          = 0;

    if(!m_info){
        return T100FALSE;
    }

    memset(&m_head, 0, sizeof(T100EXECUTABLE_FILE_HEAD));

    m_head.COMMON.SIGN      = T100Library::T100FILE_EXECUTABLE;

    result = count(m_info->m_codes, total, length);
    if(!result){
        return T100FALSE;
    }

    m_offset = sizeof(T100EXECUTABLE_FILE_HEAD) / 4;

    m_head.CODE_COUNT       = total;
    if(0 != total){
        m_head.CODE_TABLE_OFFSET        = m_offset;
        m_head.CODE_TABLE_LENGTH        = sizeof(T100EXECUTABLE_FILE_CODE) / 4 * total;
        m_head.CODE_LENGTH              = length;

        m_offset += m_head.CODE_TABLE_LENGTH;
    }

    total   = 0;
    length  = 0;

    result = count(m_info->m_datas, total, length);
    if(!result){
        return T100FALSE;
    }

    m_head.DATA_COUNT       = total;
    if(0 != total){
        m_head.DATA_TABLE_OFFSET        = m_offset;
        m_head.DATA_TABLE_LENGTH        = sizeof(T100EXECUTABLE_FILE_DATA) / 4 * total;
        m_head.DATA_LENGTH              = length;

        m_offset += m_head.DATA_TABLE_LENGTH;
    }

    total   = 0;
    length  = 0;

    result = count(m_info->m_share_codes, table, total, length);
    if(!result){
        return T100FALSE;
    }

    m_head.SHARE_CODE_COUNT     = total;
    if(0 != total){
        m_head.SHARE_CODE_TABLE_OFFSET      = m_offset;
        m_head.SHARE_CODE_TABLE_LENGTH      = table + total * 3;
        m_head.SHARE_CODE_LENGTH            = length;

        m_offset += m_head.SHARE_CODE_TABLE_LENGTH;
    }

    table   = 0;
    total   = 0;
    length  = 0;

    result = count(m_info->m_share_datas, table, total, length);
    if(!result){
        return T100FALSE;
    }

    m_head.SHARE_DATA_COUNT     = total;
    if(0 != total){
        m_head.SHARE_DATA_TABLE_OFFSET      = m_offset;
        m_head.SHARE_DATA_TABLE_LENGTH      = table + total * 4;
        m_head.SHARE_DATA_LENGTH            = length;

        m_offset += m_head.SHARE_DATA_TABLE_LENGTH;
    }

    table   = 0;
    total   = 0;
    length  = 0;

    if(0 != m_head.CODE_COUNT){
        m_head.CODE_OFFSET      = m_offset;
        m_offset                += m_head.CODE_LENGTH;
    }

    if(0 != m_head.DATA_COUNT){
        m_head.DATA_OFFSET      = m_offset;
        m_offset                += m_head.DATA_LENGTH;
    }

    if(0 != m_head.SHARE_CODE_COUNT){
        m_head.SHARE_CODE_OFFSET    = m_offset;
        m_offset                    += m_head.SHARE_CODE_LENGTH;
    }

    if(0 != m_head.SHARE_DATA_COUNT){
        m_head.SHARE_DATA_OFFSET    = m_offset;
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::count(T100SEGMENT_CODE_VECTOR& seg, T100WORD& total, T100WORD& length)
{
    T100BOOL        result          = T100TRUE;

    for(auto item : seg){
        if(item){
            total++;
            length += item->getLength();
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::count(T100SEGMENT_CODE_VECTOR& seg, T100WORD& table, T100WORD& total, T100WORD& length)
{
    T100BOOL        result          = T100TRUE;

    for(auto item : seg){
        if(item){
            table   += item->getName().to_string32().raw_length();
            total++;
            length  += item->getLength();
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::count(T100SEGMENT_DATA_VECTOR& seg, T100WORD& total, T100WORD& length)
{
    T100BOOL        result          = T100TRUE;

    for(auto item : seg){
        if(item){
            total++;
            length  += item->getLength();
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ExecutableFileWriter::count(T100SEGMENT_DATA_VECTOR& seg, T100WORD& table, T100WORD& total, T100WORD& length)
{
    T100BOOL        result          = T100TRUE;

    for(auto item : seg){
        if(item){
            table   += item->getName().to_string32().raw_length();
            total++;
            length  += item->getLength();
        }else{
            return T100FALSE;
        }
    }

    return result;
}

}
