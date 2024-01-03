#include "T100ByteBuffer.h"

T100ByteBuffer::T100ByteBuffer(T100FileReader& reader)
    :m_reader(reader)
{
    //ctor
    m_buffer = new char[m_length];
}

T100ByteBuffer::~T100ByteBuffer()
{
    //dtor

    delete m_buffer;
}

char T100ByteBuffer::getByte() {
    if(m_index >= m_count){
        if(!load()){
            throw;
        }
    }

    char result;

    result = m_buffer[m_index++];

    return result;
}


bool T100ByteBuffer::load() {
    bool result = false;

    int size;

    size = m_reader.read(m_length, m_buffer);

    if(0 < size){
        m_count     = size;
        m_index     = 0;
        result      = true;
    }

    return result;
}
