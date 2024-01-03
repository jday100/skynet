#include "T100ByteBuffer.h"

T100ByteBuffer::T100ByteBuffer(T100FileReader& reader)
    :m_reader(reader)
{
    //ctor
}

T100ByteBuffer::~T100ByteBuffer()
{
    //dtor
}

char T100ByteBuffer::getByte() {
    return 0;
}
