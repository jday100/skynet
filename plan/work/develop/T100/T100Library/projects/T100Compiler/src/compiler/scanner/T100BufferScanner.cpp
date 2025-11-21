#include "T100BufferScanner.h"

namespace T100LIBRARY{

T100BufferScanner::T100BufferScanner() :
    T100LeafScanner(),
    m_item()
{
    //ctor
    init();
}

T100BufferScanner::~T100BufferScanner()
{
    //dtor
    uninit();
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100BufferScanner::init()
{
    m_item.Data     = T100NEW T100BYTE[m_length];

    if(m_item.Data){
        m_item.Length   = m_length;
    }
}

T100VOID T100BufferScanner::uninit()
{
    if(m_item.Data){
        T100SAFE_DELETES(m_item.Data);
        m_item.Length   = -1;
    }
}

T100VOID T100BufferScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100FileScanner*>(scanner);
}

T100LeafScanner* T100BufferScanner::GetSource()
{
    return m_scanner;
}

T100BOOL T100BufferScanner::Read()
{
    T100BOOL        result      = T100TRUE;

    if(m_loaded){
        if(m_index >= m_item.Length){
            m_item.Length   = m_length;
            result = m_scanner->Next(*m_state, m_item);
            if(result){
                m_index = 0;
            }
        }
    }else{
        if(m_index == -1){
            m_item.Length   = m_length;
            result = m_scanner->Next(*m_state, m_item);
            if(result){
                m_index     = 0;
                m_loaded    = T100TRUE;
            }
        }else{
            result  = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100BufferScanner::Append()
{
    T100BOOL        result;

    result  = Read();

    if(result){
        if(m_index < m_item.Length){
            m_token->Value   = m_item.Data[m_index++];
        }else{
            m_state->Error  = T100TRUE;
            result  = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100BufferScanner::Clear()
{
    m_token->Value      = 0;
}

T100BOOL T100BufferScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100BufferToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    Clear();

    return Run();
}

T100BOOL T100BufferScanner::Run()
{
    return Append();
}

}
