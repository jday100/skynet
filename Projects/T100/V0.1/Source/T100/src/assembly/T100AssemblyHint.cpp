#include "T100AssemblyHint.h"

#include <cwchar>
#include "T100ByteToken.h"
#include "T100ProduceInfo.h"
#include "T100SentenceToken.h"

namespace T100Assembly{

T100BOOL        T100AssemblyHint::m_detail              = T100TRUE;

T100AssemblyHint::T100AssemblyHint()
    :T100Library::T100Hint()
{
    //ctor
}

T100AssemblyHint::~T100AssemblyHint()
{
    //dtor
}

T100WSTRING T100AssemblyHint::byte_hint(T100ByteToken* token, T100WSTRING msg)
{
    T100WSTRING     result;
    T100WSTRING     value;
    T100WSTRING     name;
    T100WCHAR       buffer[1024];

    switch(token->type){
    case T100Component::T100TOKEN_EOF:
        {
            value   = L"EOF";
            name    = L"T100TOKEN_EOF";
        }
        break;
    case T100Component::T100TOKEN_ERROR:
        {
            value   = L"ERROR";
            name    = L"T100TOKEN_ERROR";
        }
        break;
    case T100Component::T100TOKEN_BR:
        {
            value   = L"BR";
            name    = L"T100TOKEN_BR";
        }
        break;
    default:
        break;
    };

    swprintf(buffer, L"Byte: [%s] Type: [%s] >> %s", value, name, msg);

    return buffer;
}

T100WSTRING T100AssemblyHint::sentence_hint(T100SentenceToken* token, T100WSTRING msg)
{
    T100STRING      name;

    name = T100ProduceInfo::m_token_names[token->type];

}

}
