#include "T100Parser.h"

#include "T100ScannerTools.h"

namespace T100LIBRARY{

T100Parser::T100Parser() :
    T100Class()
{
    //ctor
}

T100Parser::~T100Parser()
{
    //dtor
}

T100VOID T100Parser::SetSourceScanner(T100SourceScanner* scanner)
{
    m_sourceScanner     = scanner;
}

T100SourceScanner* T100Parser::GetSourceScanner()
{
    return m_sourceScanner;
}

T100VOID T100Parser::SetFileScanner(T100FileScanner* scanner)
{
    m_fileScanner       = scanner;
}

T100FileScanner* T100Parser::GetFileScanner()
{
    return m_fileScanner;
}

T100BOOL T100Parser::Parse(const T100WSTRING& file, T100FrontInfo& info)
{
    T100BOOL                    result;
    T100LeafState               state;
    T100SourceToken             token;
    T100SourceScanner*          source      = T100NULL;
    T100FileScanner*            scanner     = T100NULL;

    result  = T100ScannerTools::CreateScanner(source, scanner);

    if(!result || !source || !scanner){
        return T100FALSE;
    }

    scanner->SetFile(file);
    scanner->Open();

    do{
        result  = source->Next(state, token);
    }while(result);

    scanner->Close();
    T100SAFE_DELETE(source);

    return result;
}

}
