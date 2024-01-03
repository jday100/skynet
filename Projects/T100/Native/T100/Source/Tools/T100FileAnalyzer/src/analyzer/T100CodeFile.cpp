#include "T100CodeFile.h"

T100CodeFile::T100CodeFile(T100FileReader&  reader)
    :m_reader(reader)
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

    result = m_reader.open();

    if(0 == result){
        size = m_reader.read(length, buffer);

        result = m_reader.close();
    }else{

    }

    return result;
}
