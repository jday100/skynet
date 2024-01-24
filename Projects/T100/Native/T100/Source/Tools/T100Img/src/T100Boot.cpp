#include "T100Boot.h"

#include <cstring>


T100Boot::T100Boot()
{
    //ctor
}

T100Boot::~T100Boot()
{
    //dtor
}


int T100Boot::build(T100ImgFile& file){
    init();

    file.write(m_buffer, 512);
}

int T100Boot::init() {
    memset(&m_buffer, 0, 512);

    m_buffer[510] = 0x55;
    m_buffer[511] = 0xaa;
}
