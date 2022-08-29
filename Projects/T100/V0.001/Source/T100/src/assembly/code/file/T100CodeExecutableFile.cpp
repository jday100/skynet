#include "T100CodeExecutableFile.h"

#include <cstring>


T100CodeExecutableFile::T100CodeExecutableFile()
{
    //ctor
}

T100CodeExecutableFile::~T100CodeExecutableFile()
{
    //dtor
}

T100BOOL T100CodeExecutableFile::setData(T100FileData* data)
{
    if(data){
        m_data  = data;
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100CodeExecutableFile::write_head()
{
    T100BOOL    result          = T100FALSE;

    T100STDCHAR*                data        = T100NULL;
    T100WORD                    length;

    result = create_head(m_data, m_head);
    if(!result){
        return T100FALSE;
    }

    data    = (T100STDCHAR*)&m_head;
    length  = sizeof(T100EXECUTABLE_FILE_HEAD);

    if(m_ofs->write(data, length).good()){
        m_offset += length / 4;
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CodeExecutableFile::write_table()
{
    T100BOOL        result          = T100FALSE;

    result = write_table(m_head.CODE_OFFSET, m_data->m_codes);
    if(!result){
        return T100FALSE;
    }

    result = write_table(m_head.DATA_OFFSET, m_data->m_datas);
    if(!result){
        return T100FALSE;
    }

    result = write_share_table(m_head.SHARE_CODE_OFFSET, m_data->m_share_codes);
    if(!result){
        return T100FALSE;
    }

    result = write_share_table(m_head.SHARE_DATA_OFFSET, m_data->m_share_datas);

    return result;
}

T100BOOL T100CodeExecutableFile::write_code()
{
    T100BOOL    result      = T100TRUE;

    if(!m_data){
        return T100FALSE;
    }

    /*
    result = write_table(m_data->m_codes);
    if(!result){
        return T100FALSE;
    }
    */

    for(auto item : m_data->m_codes){
        if(item){
            result = write_segment(item);
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

T100BOOL T100CodeExecutableFile::write_data()
{
    T100BOOL    result      = T100TRUE;

    if(!m_data){
        return T100FALSE;
    }

    for(auto item : m_data->m_datas){
        if(item){
            result = write_segment(item);
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

T100BOOL T100CodeExecutableFile::write_share()
{
    T100BOOL    result      = T100TRUE;

    if(!m_data){
        return T100FALSE;
    }

    for(auto item : m_data->m_share_codes){
        if(item){
            result = write_segment(item);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    for(auto item : m_data->m_share_datas){
        if(item){
            result = write_segment(item);
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

T100BOOL T100CodeExecutableFile::create_head(T100FileData* data, T100EXECUTABLE_FILE_HEAD& head)
{
    T100BOOL    result      = T100FALSE;
    T100WORD    table       = 0;
    T100WORD    total       = 0;
    T100WORD    length      = 0;

    if(!data){
        return T100FALSE;
    }

    memset(&head, 0, sizeof(T100EXECUTABLE_FILE_HEAD));

    head.COMMON.SIGN    =   T100FILE_EXECUTABLE;

    result = count(data->m_codes, total, length);
    if(!result){
        return T100FALSE;
    }

    m_offset = sizeof(T100EXECUTABLE_FILE_HEAD) / 4;

    head.CODE_COUNT             = total;
    if(0 != total){
        head.CODE_TABLE_OFFSET      = m_offset;
        head.CODE_TABLE_LENGTH      = sizeof(T100EXECUTABLE_FILE_CODE) / 4 * total;
        //head.CODE_OFFSET            = offset;
        head.CODE_LENGTH            = length;

        m_offset  += head.CODE_TABLE_LENGTH;
    }

    total   = 0;
    length  = 0;

    result = count(data->m_datas, total, length);
    if(!result){
        return T100FALSE;
    }

    head.DATA_COUNT             = total;
    if(0 != total){
        head.DATA_TABLE_OFFSET      = m_offset;
        head.DATA_TABLE_LENGTH      = sizeof(T100EXECUTABLE_FILE_DATA) / 4 * total;
        //head.DATA_OFFSET            = offset;
        head.DATA_LENGTH            = length;

        m_offset  += head.DATA_TABLE_LENGTH;
    }

    total   = 0;
    length  = 0;

    result = count(data->m_share_codes, table, total, length);
    if(!result){
        return T100FALSE;
    }

    head.SHARE_CODE_COUNT           = total;
    if(0 != total){
        head.SHARE_CODE_TABLE_OFFSET    = m_offset;
        head.SHARE_CODE_TABLE_LENGTH    = table + total * 3;
        //head.SHARE_CODE_OFFSET          = offset;
        head.SHARE_CODE_LENGTH          = length;

        m_offset  += head.SHARE_CODE_TABLE_LENGTH;
    }

    table   = 0;
    total   = 0;
    length  = 0;

    result = count(data->m_share_datas, table, total, length);
    if(!result){
        return T100FALSE;
    }

    head.SHARE_DATA_COUNT           = total;
    if(0 != total){
        head.SHARE_DATA_TABLE_OFFSET    = m_offset;
        head.SHARE_DATA_TABLE_LENGTH    = table + total * 4;
        //head.SHARE_DATA_OFFSET          = offset;
        head.SHARE_DATA_LENGTH          = length;

        m_offset  += head.SHARE_DATA_TABLE_LENGTH;
    }

    table   = 0;
    total   = 0;
    length  = 0;

    if(0 != head.CODE_COUNT){
        head.CODE_OFFSET        = m_offset;
        m_offset                += head.CODE_LENGTH;
    }

    if(0 != head.DATA_COUNT){
        head.DATA_OFFSET        = m_offset;
        m_offset                += head.DATA_LENGTH;
    }

    if(0 != head.SHARE_CODE_COUNT){
        head.SHARE_CODE_OFFSET  = m_offset;
        m_offset                += head.SHARE_CODE_LENGTH;
    }

    if(0 != head.SHARE_DATA_COUNT){
        head.SHARE_DATA_OFFSET  = m_offset;
    }

    return result;
}

T100BOOL T100CodeExecutableFile::write_table(T100WORD offset, T100SEGMENTDATA_VECTOR& segments)
{
    T100BOOL    result      = T100TRUE;

    T100EXECUTABLE_FILE_CODE    code;
    T100WORD        index       = 0;
    T100WORD        length      = 0;
    T100STDCHAR*    data        = T100NULL;
    T100WORD        size        = 0;

    data = (T100STDCHAR*)&code;

    for(auto item : segments){
        if(item){
            length = item->getLength();

            code.INDEX      = index;
            code.OFFSET     = offset;
            code.LENGTH     = length;

            size = sizeof(T100EXECUTABLE_FILE_CODE);

            if(m_ofs->write(data, size).good()){
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

T100BOOL T100CodeExecutableFile::write_share_table(T100WORD offset, T100SEGMENTDATA_VECTOR& segments)
{
    T100BOOL        result      = T100TRUE;

    T100WORD        index       = 0;
    T100WORD        length      = 0;
    T100WORD        location    = 0;
    T100STDCHAR*    data        = T100NULL;
    T100WORD        size        = 0;

    for(auto item : segments){
        if(item){
            length      = item->getLength();
            location    = item->getLocation();

            data = (T100STDCHAR*)&index;
            size = 4;

            if(m_ofs->write(data, size).good()){

            }else{
                return T100FALSE;
            }

            data = (T100STDCHAR*)&offset;
            size = 4;

            if(m_ofs->write(data, size).good()){

            }else{
                return T100FALSE;
            }

            data = (T100STDCHAR*)&length;
            size = 4;

            if(m_ofs->write(data, size).good()){

            }else{
                return T100FALSE;
            }

            data = (T100STDCHAR*)&location;
            size = 4;

            if(m_ofs->write(data, size).good()){

            }else{
                return T100FALSE;
            }

            data = (T100STDCHAR*)(item->getName().getRawData());
            size = item->getName().getByteLength();

            if(m_ofs->write(data, size).good()){

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

T100BOOL T100CodeExecutableFile::write_segment(T100Segment* seg)
{
    T100BOOL        result      = T100FALSE;
    T100STDCHAR*    data        = T100NULL;
    T100WORD        size;

    if(!seg){
        return T100FALSE;
    }

    data    = (T100STDCHAR*)(seg->getMem().data());
    size    = seg->getLength() * 4;

    if(m_ofs->write(data, size).good()){
        result = T100TRUE;
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CodeExecutableFile::save(T100STDSTRING file)
{
    T100BOOL        result      = T100FALSE;

    if(file.empty()){
        return T100FALSE;
    }

    m_ofs = T100NEW std::ofstream(file, std::ios::out | std::ios::binary);

    if(!(m_ofs->is_open())){
        T100DELETE(m_ofs);
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_FILE_OPEN_FAILURE));
        return T100FALSE;
    }
    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_OPEN_SUCCESS));

    result = write_head();

    if(result)result = write_table();

    if(result)result = write_code();

    if(result)result = write_data();

    if(result)result = write_share();

    m_ofs->close();
    T100DELETE(m_ofs);
    m_ofs = T100NULL;

    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_CLOSE_SUCCESS));

    return result;
}
