#include "T100WString.h"

T100WString::T100WString()
{
    //ctor
}

T100WString::T100WString(wchar_t* msg)
{
    int len         = 0;

    len = wcslen(msg);

    for(int i=0;i<len;i++){
        m_wstring.push_back(msg[i]);
    }
}

T100WString::~T100WString()
{
    //dtor
}

T100WString& T100WString::operator=(wchar_t msg[0])
{
    int len         = 0;

    len = wcslen(msg);
    m_wstring.clear();

    for(int i=0;i<len;i++){
        m_wstring.push_back(msg[i]);
    }
    return *this;
}

std::iostream T100WString::operator<<(T100WString& msg)
{
    //test
    std::wcout << msg.data();
}

wchar_t* T100WString::data()
{
    return m_wstring.data();
}
