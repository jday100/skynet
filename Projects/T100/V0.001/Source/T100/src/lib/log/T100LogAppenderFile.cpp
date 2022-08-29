#include "T100LogAppenderFile.h"

#include "T100Common.h"


T100LogAppenderFile::T100LogAppenderFile(T100STDSTRING file)
    :T100LogAppender(), m_file(file)
{
    //ctor
    create();
}

T100LogAppenderFile::~T100LogAppenderFile()
{
    //dtor
    destroy();
}

T100VOID T100LogAppenderFile::create()
{
    //m_ofs = T100NEW std::ofstream(m_file.c_str(), std::ios::out | std::ios::app);
    m_ofs = T100NEW std::ofstream(m_file.c_str(), std::ios::out);
    if(m_ofs){
        if(m_ofs->is_open()){

        }else{
            T100DELETE(m_ofs);
            m_ofs = T100NULL;
        }
    }
}

T100VOID T100LogAppenderFile::destroy()
{
    if(m_ofs){
        if(m_ofs->is_open()){
            m_ofs->close();
        }

        T100DELETE(m_ofs);
        m_ofs = T100NULL;
    }
}

T100VOID T100LogAppenderFile::out(T100LOG_TYPE type, T100STDSTRING msg)
{
    if(m_ofs){
        *m_ofs << msg;
        *m_ofs << std::endl;
    }
}
