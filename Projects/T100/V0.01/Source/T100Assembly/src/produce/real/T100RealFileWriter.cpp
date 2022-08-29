#include "T100RealFileWriter.h"
#include "T100String.h"


T100RealFileWriter::T100RealFileWriter(T100STRING file)
    :T100FileWriter(file.to_wstring())
{
    //ctor
}

T100RealFileWriter::~T100RealFileWriter()
{
    //dtor
}

T100BOOL T100RealFileWriter::save(T100RealInfo& info)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    if(!opened()){
        value = open();
        if(!value){
            return T100FALSE;
        }
    }

    m_info = &info;

    if(result){
        value = write_head();
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
        value = write_code();
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

T100BOOL T100RealFileWriter::write_head()
{
    T100BOOL            result          = T100TRUE;
    T100WORD            offset;
    T100WORD_BITS       order;
    T100WORD_BITS       data;

    if(m_info){
        offset          = m_info->getData().getLength() + 2;

        data.WORD       = offset;

        order.BYTE0.BYTE    = T100ORDER_JUMP;
        order.BYTE1.BYTE    = T_NONE;
        order.BYTE2.BYTE    = T_IMM;
        order.BYTE3.BYTE    = T_NONE;

        result = write(&(order.WORD), 4);
        if(!result){
            return T100FALSE;
        }

        result = write(&(data.WORD), 4);
        if(!result){
            return T100FALSE;
        }

    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100RealFileWriter::write_data()
{
    T100BOOL            result          = T100TRUE;
    T100WORD            size;

    if(!m_info){
        return T100FALSE;
    }

    if(m_info->getData().size() == 0){
        return T100TRUE;
    }

    size    = m_info->getData().getMem().size() * 4;
    result  = write(m_info->getData().getMem().data(), size);
    if(!result){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100RealFileWriter::write_code()
{
    T100BOOL            result          = T100TRUE;
    T100WORD            size;

    if(!m_info){
        return T100FALSE;
    }

    if(m_info->getCode().size() == 0){
        return T100FALSE;
    }

    size    = m_info->getCode().getMem().size() * 4;
    result  = write(m_info->getCode().getMem().data(), size);
    if(!result){
        return T100FALSE;
    }

    return T100TRUE;
}
