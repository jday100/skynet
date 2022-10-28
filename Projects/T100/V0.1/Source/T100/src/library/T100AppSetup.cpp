#include "T100AppSetup.h"

#include <sstream>

namespace T100Library{

T100WSTRING         T100AppSetup::m_log                     = L"logs";

T100AppSetup::T100AppSetup()
    :T100Setup()
{
    //ctor
}

T100AppSetup::~T100AppSetup()
{
    //dtor
}

T100WSTRING T100AppSetup::getLog(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << m_log << L"\\" << L"error";
    }else{
        result << m_log << L"\\" << path;
    }
    return result.str();
}

}
