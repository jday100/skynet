#include "T100CodeFile.h"

T100CodeFile::T100CodeFile(T100ByteBuffer&  buffer)
    :m_buffer(buffer)
{
    //ctor
}

T100CodeFile::~T100CodeFile()
{
    //dtor
}

int T100CodeFile::run() {
    int result;
    int size;
    int length      = 1024;
    char buffer[length];



    return result;
}

int T100CodeFile::parse() {
    char        byte;

    byte = m_buffer.getByte();
}
