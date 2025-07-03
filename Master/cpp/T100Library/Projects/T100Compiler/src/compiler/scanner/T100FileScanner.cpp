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
    T100UINT        result;

    result  = m_reader->Read(m_token->Data, m_token->Length);

    if(result <= m_token->Length){
        return T100TRUE;
    }
    return T100FALSE;
}

}
