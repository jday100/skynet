#include "T100CodeFile.h"

#include <iostream>


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

    while(m_buffer.load()){
        parse();
    }

    return result;
}

int T100CodeFile::parse() {
    char        byte;

    byte = m_buffer.getByte();

    switch(byte){
    default:
        std::cout << byte;
        break;
    }
}
