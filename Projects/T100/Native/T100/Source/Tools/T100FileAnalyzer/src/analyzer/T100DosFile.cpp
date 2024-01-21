#include "T100DosFile.h"

#include <iostream>

T100DosFile::T100DosFile(T100ByteBuffer& buffer)
    : T100CodeFile(buffer)
{
    //ctor
}

T100DosFile::~T100DosFile()
{
    //dtor
}

bool T100DosFile::parse() {
    char        byte;

    byte = m_buffer.getByte();

    if('M' == byte){

    }else{
        return false;
    }

    byte = m_buffer.getByte();
    if('Z' == byte){

    }else{
        return false;
    }

    return true;
}
