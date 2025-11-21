#include "T100FileScanner.h"

namespace T100LIBRARY{

T100FileScanner::T100FileScanner() :
    T100LeafScanner(),
    m_filename()
{
    //ctor
}

T100FileScanner::~T100FileScanner()
{
    //dtor
}

T100VOID T100FileScanner::SetFile(const T100WSTRING& file)
{
    m_filename  = file;
}

const T100WSTRING& T100FileScanner::GetFile()
{
    return m_filename;
}

T100BOOL T100FileScanner::Open()
{
    m_file      = T100NEW T100BinaryFile(m_filename);
    m_reader    = m_file->CreateReader();

    if(m_reader){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100FileScanner::Close()
{
    m_file->DestroyReader(m_reader);
    T100SAFE_DELETE(m_file);
    return T100TRUE;
}

T100BOOL T100FileScanner::Read()
{
    T100INT     result;

    result  = m_reader->Read(m_token->Data, m_token->Length);

    if(result == m_token->Length){
        return T100TRUE;
    }else if(result == 0){
        if(m_reader->IsEof()){
            m_state->Eof    = T100TRUE;
        }else{
            m_state->Error  = T100TRUE;
        }
        m_token->Length = 0;
        return T100FALSE;
    }else{
        if(result < m_token->Length){
            m_token->Length = result;
            return T100TRUE;
        }else{
            m_state->Error  = T100TRUE;
            m_token->Length = 0;
            return T100FALSE;
        }
    }
    m_state->Error  = T100TRUE;
    return T100FALSE;
}

T100BOOL T100FileScanner::Clear()
{

}

T100BOOL T100FileScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100FileToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    return Run();
}

T100BOOL T100FileScanner::Run()
{
    T100BOOL        result;

    result  = Read();

    return result;
}

}
