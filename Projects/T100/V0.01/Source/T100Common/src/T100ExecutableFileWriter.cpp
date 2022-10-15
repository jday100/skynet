#include "T100ExecutableFileWriter.h"
#include "T100String.h"
#include "T100SegmentCode.h"
#include "T100SegmentData.h"


T100ExecutableFileWriter::T100ExecutableFileWriter(T100STRING file)
    :T100FileWriter(file.to_wstring())
{
    //ctor
}

T100ExecutableFileWriter::~T100ExecutableFileWriter()
{
    //dtor
}

T100BOOL T100ExecutableFileWriter::save(T100ExecutableInfo& info)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = write_head();
    if(!value){
        return T100FALSE;
    }

    value = write_table();
    if(!value){
        return T100FALSE;
    }

    value = write_code();
    if(!value){
        return T100FALSE;
    }

    value = write_data();
    if(!value){
        return T100FALSE;
    }

    value   = write_share();
    result  = value;

    return result;
}

T100BOOL T100ExecutableFileWriter::write_head()
{
    T100BOOL        result      = T100FALSE;

    T100WORD*       data        = T100NULL;
    T100WORD        length;

    data    = (T100WORD*)&m_head;
    length  = (sizeof(T100EXECUTABLE_FILE_HEAD) + 3) / 4;

    result = write(data, length);

    return result;
}

T100BOOL T100ExecutableFileWriter::write_table()
{
    T100BOOL        result      = T100FALSE;

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
    T100BOOL        result      = T100TRUE;

    if(!m_info){
        return T100FALSE;
    }

    for(auto item : m_info->m_codes){
        if(item){
            result = write_segment((T100Segment*)item);
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
    T100BOOL    result      = T100TRUE;

    if(!m_info){
        return T100FALSE;
    }

    for(auto item : m_info->m_datas){
        if(item){
            result = write_segment((T100Segment*)item);
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
    T100BOOL    result      = T100TRUE;

    if(!m_info){
        return T100FALSE;
    }

    for(auto item : m_info->m_share_codes){
        if(item){
            result = write_segment((T100Segment*)item);
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
            result = write_segment((T100Segment*)item);
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
    T100BOOL        result      = T100TRUE;

    T100EXECUTABLE_FILE_CODE    code;
    T100WORD        index       = 0;
    T100WORD        length      = 0;
    T100WORD*       data        = T100NULL;
    T100WORD        size        = 0;

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
                offset      += length;
                length      = 0;
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
    T100BOOL        result      = T100TRUE;

    T100EXECUTABLE_FILE_DATA    data;
    T100WORD        index       = 0;
    T100WORD        length      = 0;
    T100WORD*       point       = T100NULL;
    T100WORD        size        = 0;

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
                offset      += length;
                length      = 0;
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
    T100BOOL        result      = T100TRUE;

    T100WORD        index       = 0;
    T100WORD        length      = 0;
    T100WORD        location    = 0;
    T100WORD*       data        = T100NULL;
    T100WORD        size        = 0;

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

            data = item->getName().to_string().raw_data();
            size = item->getName().to_string().raw_length();

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
    T100BOOL        result      = T100TRUE;

    T100WORD        index       = 0;
    T100WORD        length      = 0;
    T100WORD        location    = 0;
    T100WORD*       data        = T100NULL;
    T100WORD        size        = 0;

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

            data = item->getName().to_string().raw_data();
            size = item->getName().to_string().raw_length();

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

T100BOOL T100ExecutableFileWriter::write_segment(T100Segment* seg)
{
    T100BOOL        result      = T100FALSE;
    T100WORD*       data        = T100NULL;
    T100WORD        length;

    if(!seg){
        return T100FALSE;
    }

    data    = seg->getMem().data();
    length  = seg->getLength();

    result  = write(data, length);

    return result;
}
