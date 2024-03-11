#include "T100Asm64LetterScanner.h"

T100Asm64LetterScanner::T100Asm64LetterScanner()
    :T100Scanner()
{
    //ctor
}

T100Asm64LetterScanner::~T100Asm64LetterScanner()
{
    //dtor
}

T100BOOL T100Asm64LetterScanner::open(T100STRING file)
{
    m_file  = T100NEW T100File(file);

    if(m_file){
        if(m_file->open()){
            m_buffer    = T100NEW T100Buffer();
            m_filename  = file;
            return T100TRUE;
        }else{
            T100DELETE m_file;
            m_file      = T100NULL;
        }
    }
    return T100FALSE;
}

T100BOOL T100Asm64LetterScanner::close()
{
    if(m_file){
        if(m_file->close()){
            T100DELETE m_file;
            m_file      = T100NULL;
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100Asm64LetterScanner::next(T100Token& token)
{
    m_token = dynamic_cast<T100Asm64LetterToken*>(&token);
    read();

    m_token->value  = m_item;

}

T100BOOL T100Asm64LetterScanner::read()
{
    T100BOOL        result;

    if(m_buffer->empty()){
        result  = m_file->read(*m_buffer);
        if(result){

        }else{
            return T100FALSE;
        }
    }
    result  = m_buffer->next(m_item);

    return result;
}

T100BOOL T100Asm64LetterScanner::append()
{

}

T100VOID T100Asm64LetterScanner::clear()
{

}

T100BOOL T100Asm64LetterScanner::classify()
{

}
