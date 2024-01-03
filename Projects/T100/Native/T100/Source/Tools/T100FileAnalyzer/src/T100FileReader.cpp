#include "T100FileReader.h"

T100FileReader::T100FileReader(char* file)
    :m_file(file)
{
    //ctor
}

T100FileReader::~T100FileReader()
{
    //dtor
}

int T100FileReader::open() {
    int result = 0;
    m_ifs = new std::ifstream(m_file, std::ios::in | std::ios::binary);

    if(m_ifs->is_open()){

    }else{
        result = -1;
    }

    return result;
}


int T100FileReader::close() {
    int result = 0;
    if(m_ifs){
        m_ifs->close();
    }else{
        result = -1;
    }

    return result;
}


int T100FileReader::read(int length, char* buffer) {
    int result = 0;
    if(m_ifs){
        int size;

        size = m_ifs->read(buffer, length).gcount();

        result = size;
    }

    return result;
}
