#include "T100WString.h"

T100WString::T100WString()
{
    //ctor
}

T100WString::~T100WString()
{
    //dtor
}

T100WString& T100WString::operator=(wchar_t msg[0])
{
    int i = sizeof(msg);

    m_wstring.push_back(L'A');
    return *this;
}

std::iostream T100WString::operator<<(T100WString& msg)
{
    std::wcout << msg.data();
}

wchar_t* T100WString::data()
{
    return m_wstring.data();
}
